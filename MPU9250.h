/*
 * MPU9250.h
 *
 *  Created on: 2016/06/15
 *      Author: takah_000
 */

#ifndef MPU9250_H_
#define MPU9250_H_

#include "mbed.h"

class MPU9250{
public:
	MPU9250(SPI spi, PinName cs);
	MPU9250(PinName mosi, PinName miso, PinName sck, PinName cs);

	void init();


	void frequency(int freq = 1000000);
	void writeReg(uint8_t addr, uint8_t data);
	uint8_t readReg(uint8_t addr);
	void readMultipleRegs(int count, uint8_t* buf, uint8_t startAddr);

	void writeI2CReg(uint8_t slaveAddr, uint8_t regAddr, uint8_t data);
	uint8_t readI2CReg(uint8_t slaveAddr, uint8_t regAddr);
	void readI2CMultipleRegs(int count, uint8_t slaveAddr, uint8_t regAddr);

	enum {
		GYRO_FS_250DPS = 0x00,
		GYRO_FS_500DPS = 0x08,
		GYRO_FS_1000DPS = 0x10,
		GYRO_FS_2000DPS = 0x18
	};

	enum {
		ACCEL_FS_2G = 0x00,
		ACCEL_FS_4G = 0x08,
		ACCEL_FS_8G = 0x10,
		ACCEL_FS_16G = 0x18
	};

	void refresh();

	bool isFail;

	uint16_t accel[3];
	uint16_t gyro[3];
	uint16_t mag[3];
	uint16_t temp;
	bool isMagOF;

private:

	SPI spi;
	DigitalOut cs;
};

#endif /* MPU9250_H_ */
