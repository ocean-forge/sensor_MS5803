//
// Created by raphael on 1/26/25.
//

#ifndef SENSOR_MS5803_H
#define SENSOR_MS5803_H

#include <Arduino.h>

class MS_5803 {
public:
    // Constructor for the class.
    // The argument is the desired oversampling resolution, which has
    // values of 256, 512, 1024, 2048, 4096
    MS_5803(uint16_t Resolution = 512);
    // Initialize the sensor
    boolean initializeMS_5803(boolean Verbose = true);
    // Reset the sensor
    void resetSensor();
    // Read the sensor
    void readSensor();
    //*********************************************************************
    // Additional methods to extract temperature, pressure (mbar), and the
    // UP1,UT2 values after readSensor() has been called

    // Return temperature in degrees Celsius.
    float temperature() const       {return tempC;}
    // Return pressure in mbar.
    float pressure() const          {return mbar;}
//    // Return temperature in degress Fahrenheit.
//    float temperatureF() const		{return tempF;}
//    // Return pressure in psi (absolute)
//    float psia() const				{return psiAbs;}
//    // Return pressure in psi (gauge)
//    float psig() const				{return psiGauge;}
//    // Return pressure in inHg
//    float inHg() const				{return inHgPress;}
//    // Return pressure in mmHg
//    float mmHg() const				{return mmHgPress;}
    // Return the UP1 and UT2 values, mostly for troubleshooting
    unsigned long UP1val() const 	{return UP1;}
    unsigned long UT2val() const		{return UT2;}


private:

    float mbar; // Store pressure in mbar.
    float tempC; // Store temperature in degrees Celsius
//    float tempF; // Store temperature in degrees Fahrenheit
//    float psiAbs; // Store pressure in pounds per square inch, absolute
//    float psiGauge; // Store gauge pressure in pounds per square inch (psi)
//    float inHgPress;	// Store pressure in inches of mercury
//    float mmHgPress;	// Store pressure in mm of mercury
    unsigned long UP1;	// Store UP1 value
    unsigned long UT2;	// Store UT2 value
    int32_t mbarInt; // pressure in mbar, initially as a signed long integer
    // Check data integrity with CRC4
    unsigned char MS_5803_CRC(unsigned int n_prom[]);
    // Handles commands to the sensor.
    unsigned long MS_5803_ADC(char commandADC);
    // Oversampling resolution
    uint16_t _Resolution;
};

#endif //SENSOR_MS5803_H
