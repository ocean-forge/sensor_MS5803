//
// Created by raphael on 2/9/25.
//

#ifndef SENSOR_MS5803_H
#define SENSOR_MS5803_H

#include <Arduino.h>

//#include <Adafruit_I2CDevice.h>
#include <sensor_unified.h>

/** MS5803 address **/
#define MS5803_ADDRESS_A (0x76)
#define MS5803_ADDRESS_B (0x77)

/** **/

class sensor_MS5803 : public sensor_unified {
public:
    /** MS5803 commands**/
    typedef enum {
        MS5803_RESET = 0x1E,
        MS5803_D1_256 = 0x40,
        MS5803_D1_512 = 0x42,
        MS5803_D1_1024 = 0x44,
        MS5803_D1_2048 = 0x46,
        MS5803_D1_4096 = 0x48,
        MS5803_D2_256 = 0x50,
        MS5803_D2_512 = 0x52,
        MS5803_D2_1024 = 0x54,
        MS5803_D2_2048 = 0x56,
        MS5803_D2_4096 = 0x58,
        MS5803_ADC_READ = 0x00
    };

    // Sensor calibration coefficients
    static unsigned int sensor_coeffs[8];

    sensor_MS5803(int32_t sensorID = -1, uint8_t address = MS5803_ADDRESS_A,
                  TwoWire *theWire = &Wire);
private:
    int32_t _sensorID;

};

#endif //SENSOR_MS5803_H
