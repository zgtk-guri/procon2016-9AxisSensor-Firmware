#include "mbed.h"
#include "MPU9250.h"

AnalogIn battLevelInput(dp9);
MPU9250 sensor(dp2, dp1, dp6, dp28);
Serial serial(dp16, dp15);
Ticker tick;

const int FREQ = 60;

bool interruptFlag = false;

void interrupt(){
	interruptFlag = true;
}

int main() {
    serial.baud(115200);
    wait(1);
    sensor.init();
    
    if(sensor.isFail){
    	while(1){
    		serial.printf("err.\r\n");
    		wait(1);
    	}
    }

    tick.attach(&interrupt, 1.0 / FREQ);

    while(1) {
    	if(interruptFlag){
    		sensor.refresh();
    		serial.printf("%04X,%04X,%04X,%04X,%04X,%04X,%04X,%04X,%04X\r\n",
    				sensor.accel[0],
					sensor.accel[1],
					sensor.accel[2],
					sensor.gyro[0],
					sensor.gyro[1],
					sensor.gyro[2],
					sensor.mag[0],
					sensor.mag[1],
					sensor.mag[2]);
    		interruptFlag = false;
    	}
    }
}
