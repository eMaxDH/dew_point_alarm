#include "sensor.hpp"

Sensor::Sensor(){
}

Sensor::~Sensor(){
}

void Sensor::setup()
{
  Serial.println("=== Sensor Setup ===");
  // Create an instance of the DHT11 class.
  // - For Arduino: Connect the sensor to Digital I/O Pin 2.
  // - For ESP32: Connect the sensor to pin GPIO2 or P2.
  // - For ESP8266: Connect the sensor to GPIO2 or D4.
  _dht11 = std::make_shared<DHT11>(PD2);
  // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
  // _dht11->setDelay(2500); // Set this to the desired delay. Default is 500ms.
}

void Sensor::loop()
{
  Serial.println("=== Sensor Loop ===");

  int temperature = 0;
  int humidity = 0;

  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = _dht11->readTemperatureHumidity(temperature, humidity);

  // Check the results of the readings.
  // If the reading is successful, print the temperature and humidity values.
  // If there are errors, print the appropriate error messages.
  if (result == 0) {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
      Serial.println(" %");
  } else {
      // Print error message based on the error code.
      Serial.println(DHT11::getErrorString(result));
  }

  // humidity = dht11.readHumidity();

  // // Check the result of the reading.
  // // If there's no error, print the humidity value.
  // // If there's an error, print the appropriate error message.
  // if (humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
  //     Serial.print("Humidity: ");
  //     Serial.print(humidity);
  //     Serial.println(" %");
  // } else {
  //     // Print error message based on the error code.
  //     Serial.println(DHT11::getErrorString(humidity));
  // }
}