# ESPHome_AdafruitPCT2075
ESPHome custom sensor support for the Qwiic / STEMMA QT compatible Adafruit PCT2075 Temperature Sensor.
https://learn.adafruit.com/adafruit-pct2075-temperature-sensor

Source: https://github.com/adafruit/Adafruit_PCT2075

This can be added to your ESPHome yaml:

esphome:
  includes:
    - CustomSensor_Adafruit_PCT2075.h
  libraries:
    - "Adafruit PCT2075"

sensor:
  - platform: custom
    lambda: |-
      auto my_PCT2075 = new CustomPCT2075Temp();
      App.register_component(my_PCT2075);
      return {my_PCT2075};
      
    sensors:
      name: "PCT2075 Temperature"
      unit_of_measurement: "°C"
      accuracy_decimals: 2
