// sensor.hpp
#pragma once

#include <Arduino.h>

// #include <ArxSmartPtr.h>
// #include <DHT11.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11


extern DHT dht;  

class Sensor {
public:
  Sensor();
  ~Sensor();

  void setup();
  void loop(float &humi, float &tempC);

// private:
//   std::shared_ptr<DHT11> _dht11;
};
