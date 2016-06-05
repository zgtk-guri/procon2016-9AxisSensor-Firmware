#include "mbed.h"
#include "MPU9250.h"

AnalogIn battLevelInput(dp9);
MPU9250 sensor(dp2, dp1, dp6, dp28);
RawSerial serial(dp16, dp15);

int main() {
    serial.baud(115200);
    
    while(1) {

    }
}
