#include "esphome.h"
#include "Adafruit_PCT2075.h" 

class CustomPCT2075Temp: public PollingComponent, public Sensor {
	
public:
    Adafruit_PCT2075 PCT2075;
	
    CustomPCT2075Temp(): PollingComponent(10000) {} 

    float get_setup_priority() const override {
        return esphome::setup_priority::BUS;
    }

    void setup() override {
        PCT2075.begin();
    }
	
    void update() override {
        float temperature = PCT2075.getTemperature();
        publish_state(temperature); 
    }
};
