#include <SPI.h>
#include <LoRa.h>

#define ss 10
#define rst 9
#define dio0 2
#define buttonPin 7
#define ledPin 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Transmitter");

  LoRa.setPins(ss, rst, dio0);

  while (!LoRa.begin(866E6)) {
    Serial.print(".");
    delay(500);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("Lora Initializing OK!");

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == LOW) {
    Serial.println("Button pressed! Sending message...");

    digitalWrite(ledPin, HIGH);

    LoRa.beginPacket();
    LoRa.print("Button Pressed!");
    LoRa.endPacket();

    delay(500);

    digitalWrite(ledPin, LOW);

    delay(300);
  }
}
