/*
 * MPU9250.cpp
 *
 *  Created on: 2016/06/15
 *      Author: takah_000
 */

#include "MPU9250.h"

MPU9250::MPU9250(SPI _spi, PinName _cs):spi(_spi), cs(_cs){
}

MPU9250::MPU9250(PinName mosi, PinName miso, PinName sck, PinName _cs):spi(mosi,miso,sck), cs(_cs){
}

void MPU9250::init(){
	spi.frequency(1000000);
	spi.format(8, 0);

	if(readReg(0x75) != 0x71){
		isFail = true;
		return;
	}
	isFail = false;

	writeReg(0x6B, 0x80);	//Reset
	writeReg(0x6B, 0x00);
	writeReg(0x6C, 0x00);

	writeReg(0x19, 0x00);	//Sample Rate Divider = 0
	writeReg(0x1A, 0x03);	//Gylo LPF = 41Hz
	writeReg(0x1B, 0x18);	//Gylo +-2000dps
	writeReg(0x1C, 0x18);	//Acc +-16g
	writeReg(0x1D, 0x0B);	//Acc LPF = 40Hz
	writeReg(0x23, 0x00);	//FIFO all disabled
	writeReg(0x37, 0x00);	//Interrupt disabled
	writeReg(0x38, 0x00);	//Interrupt disabled
	writeReg(0x69, 0x00);	//Interrupt disabled
	writeReg(0x6A, 0x20);	//I2C master enabled

	//AK8963
	writeI2CReg(0x0C, 0x0B, 0x01);	//Reset
	writeI2CReg(0x0C, 0x0A, 0x16);	//16bit, 100Hz

	//if(readI2CReg(0x0C, 0x00) != 0x48){
	//	isFail = true;
	//}

}

void MPU9250::frequency(int freq){
	spi.frequency(freq);
}

void MPU9250::writeReg(uint8_t addr, uint8_t data){
	cs = 0;
	spi.write(addr & 0x7F);
	spi.write(data);
	cs = 1;
	wait_us(50);
}

uint8_t MPU9250::readReg(uint8_t addr){
	cs = 0;
	spi.write(addr | 0x80);
	uint8_t res = spi.write(0x00);
	cs = 1;
	wait_us(50);
	return res;
}

void MPU9250::readMultipleRegs(int count, uint8_t* buf, uint8_t startAddr){
	cs = 0;
	spi.write(startAddr | 0x80);
	for(int i = 0; i < count; i++){
		buf[i] = spi.write(0x00);
	}
	cs = 1;
	wait_us(50);
}


void MPU9250::writeI2CReg(uint8_t slaveAddr, uint8_t regAddr, uint8_t data){
	writeReg(0x25, slaveAddr & 0x7F);
	writeReg(0x26, regAddr);
	writeReg(0x63, data);
	writeReg(0x27, 0x81);
}

uint8_t MPU9250::readI2CReg(uint8_t slaveAddr, uint8_t regAddr){
	writeReg(0x25, slaveAddr | 0x80);
	writeReg(0x26, regAddr);
	writeReg(0x27, 0x81);
	return readReg(0x49);
}

void MPU9250::readI2CMultipleRegs(int count, uint8_t slaveAddr, uint8_t regAddr){
	if(count < 0 || count > 15) return;
	writeReg(0x25, slaveAddr | 0x80);
	writeReg(0x26, regAddr);
	writeReg(0x27, 0x80 | count);
}

void MPU9250::refresh(){
	readI2CMultipleRegs(7, 0x0C, 0x03);

	uint8_t buf[21];
	readMultipleRegs(21, buf, 0x3B);

	for(int i = 0; i < 3; i++){
		//Acc
		accel[i] = (buf[i * 2] << 8) | buf[i * 2 + 1];

		//Gyro
		gyro[i] = (buf[i * 2 + 8] << 8) | buf[i * 2 + 9];

		//Mag
		mag[i] = (buf[i * 2 + 15] << 8) | buf[i * 2 + 14];
	}

	temp = (buf[6] << 8) | buf[7];

	isMagOF = buf[20] & 0x08;
}
