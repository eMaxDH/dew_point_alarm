// sensor.hpp
#pragma once

#include <Arduino.h>

#include <ArxSmartPtr.h>
#include <DHT11.h>

class Sensor {
public:
  Sensor();
  ~Sensor();

  void setup();
  void loop();

private:
  std::shared_ptr<DHT11> _dht11;
};
