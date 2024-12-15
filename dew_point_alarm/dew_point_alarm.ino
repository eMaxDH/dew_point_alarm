#include "sensor.hpp"
#include "dew_point_calc.hpp"

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

Sensor s;

void alarm(bool enable = true) {
  if (enable)
  {
    digitalWrite(PD0, HIGH);
  }
  else {
    digitalWrite(PD0, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:

  // Initialize serial communication to allow debugging and data readout.
  // Using a baud rate of 9600 bps.
  Serial.begin(9600);
  Serial.println("Hallo");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PD0, OUTPUT);

  s.setup();
}

void loop() {

  float dew_point = 0;
  float tempC = 10.0;
  float humi = 0.6;

  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  
  if (val > 100) {
    alarm(true);
  }
  else
  {
    alarm(false);
  }
  delay(500);

  s.loop(humi, tempC);
  
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C ~ "); 
  dew_point = get_dew_point(tempC, humi/100.0);
  Serial.print("dew point: ");
  Serial.println(dew_point);
}
