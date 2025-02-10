//
// Created by raphael on 2/9/25.
//

// Define DEBUG_SERIAL to enable debugging
#define DEBUG_SERIAL Serial

#include "../include/MS5803.h"

/*!
 *  @brief  Instantiates a new sensor_MS5803 class
 *  @param  sensorID
 *          sensor ID
 *  @param  address
 *          i2c address
 *  @param  theWire
 *          Wire object
 */
sensor_MS5803::sensor_MS5803(int32_t sensorID, uint8_t address,
                             TwoWire *theWire) {

    _sensorID = sensorID;
    i2c_dev = new Adafruit_I2CDevice(address, theWire);
}

bool MS5803::begin(){
    i2c_dev->begin(bool addr_detect = true)

}
