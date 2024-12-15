#pragma once
#include <Arduino.h>

// float get_dew_point_P_sm(float temperature, float a, float b, float c, float d);
// float get_dew_point_gamma_m(float temperature, float rel_humidity, float b, float c, float d);
// float get_dew_point(float temperature, float rel_humidity);

/// Dew point calculation (Arden Buck equation): P_s,m
///   
/// Reference: https://en.wikipedia.org/wiki/Dew_point
float get_dew_point_P_sm(float temperature, float a, float b, float c, float d)
{
  float rv = 0;

  rv = a * exp((b - temperature / d) * (temperature / (c + temperature)));

  return rv;
}

float get_dew_point_gamma_m(float temperature, float rel_humidity, float b, float c, float d)
{
  float rv = 0;

  rv = log(rel_humidity * exp((b - temperature/d)* (temperature / (c + temperature))));

  return rv;
}

float get_dew_point(float temperature, float rel_humidity)
{
  float rv;

  float a, b, c;
  float d = 234.5; // [°C]
  if (temperature >= 0.0 && temperature <= 50.0)
  {
    a = 6.1121; // [mbar]
    b = 17.368; // [1]
    c = 238.88; // [°C]
  }
  else if (temperature >= -40.0 && temperature <= 0.0)
  {
    a = 6.1121; // [mbar]
    b = 17.966; // [1]
    c = 247.15; // [°C]
  }

  float gamma_m = get_dew_point_gamma_m(temperature, rel_humidity, b, c, d);
  float p_sm = get_dew_point_P_sm(temperature, a, b, c, d);

  rv = c * gamma_m / (b - gamma_m);

  return rv; 
}



