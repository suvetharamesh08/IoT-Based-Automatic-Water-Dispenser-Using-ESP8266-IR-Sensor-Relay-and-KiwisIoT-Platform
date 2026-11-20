#include <ESP8266WiFi.h>
#include <KiwisIoT.h>

// WiFi details
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

// Pin configuration
#define IR_SENSOR D1
#define RELAY D3
#define LED D2

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

// Relay activation time
int dispenseTime = 2000;

void setup() {
  Serial.begin(115200);

  pinMode(IR_SENSOR, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(LED, OUTPUT);

  // Relay and LED OFF
  digitalWrite(RELAY, HIGH);
  digitalWrite(LED, LOW);

  kiwisiot.begin();
}

void loop() {
  kiwisiot.run();

  int sensorValue = digitalRead(IR_SENSOR);

  if (sensorValue == LOW) {
    Serial.println("Object Detected");
    Serial.println("Dispenser Activated");

    // Pump ON
    digitalWrite(RELAY, LOW);
    digitalWrite(LED, HIGH);

    kiwisiot.send("0", 1);
    kiwisiot.send("1", "ON");

    delay(dispenseTime);

    // Pump OFF
    digitalWrite(RELAY, HIGH);
    digitalWrite(LED, LOW);

    kiwisiot.send("0", 0);

    Serial.println("Dispenser Stopped");
    kiwisiot.send("1", "OFF");

    // Wait until object is removed
    while (digitalRead(IR_SENSOR) == LOW) {
      kiwisiot.run();
      delay(50);
    }
  }
  else {
    digitalWrite(RELAY, HIGH);
    digitalWrite(LED, LOW);
  }
}
