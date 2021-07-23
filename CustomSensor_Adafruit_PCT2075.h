#include "esphome.h"
#include "Adafruit_PCT2075.h" 

class CustomPCT2075Temp: public PollingComponent, public Sensor {
	
public:
    Adafruit_PCT2075 PCT2075;
	
    CustomPCT2075Temp(): PollingComponent(10000) {} // refresh update() every 10sec

    float get_setup_priority() const override {
        return esphome::setup_priority::BUS; // initialize as I2C / bus device
    }

    void setup() override {
        PCT2075.begin(); // initialize sensor
    }
	
    void update() override {
        float temperature = PCT2075.getTemperature(); // grab temperature readings
        publish_state(temperature); // pass the reading on to ESPHome & Home Assistant
    }
};
