#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#include <SPI.h>
#include <LoRa.h>
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//define the pins used by the transceiver module
#define ss 10
#define rst 9
#define dio0 2

void setup() {
  //initialize Serial Monitor


  
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");
    lcd.begin(16, 2);
//if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//    Serial.println(F("SSD1306 allocation failed"));
//    for(;;);
//  }
  delay(200);
  lcd.clear();
  lcd.print("Temperature");
   lcd.setCursor(0,10);
  lcd.println("And Humidity");
  delay(2000);
  lcd.clear();
//  lcd.setTextColor(WHITE);


  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(866E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 

  lcd.clear();
//  lcd.setTextSize(1);
  lcd.setCursor(0,0);
  lcd.print("Temp And Humid");
// lcd.setTextSize(2);
  lcd.setCursor(0,10);
//  
  // lcd.print(" ");
  lcd.print(LoRaData);
  lcd.print("C");
//   lcd.setCursor(0,1);
//  lcd.print("Humid");
//  lcd.print(LoRaData);
//  lcd.setCursor(0,12);
//  lcd.display(); 

      
     
//int packetSize = LoRa.parsePacket();
//  if (packetSize) {
//    // received a packet
//    Serial.print("Received packet '");

    // read packet
//    while (LoRa.available()) {
//      String LoRaData = LoRa.readString();
//      Serial.print(LoRaData); 
// lcd.clear();
//  lcd.setTextSize(1);
//  lcd.setCursor(0,5);
//  lcd.print("Humid");
//  lcd.setTextSize(2);
 
  lcd.setCursor(0,15);
  lcd.print(LoRaData);
  lcd.print(" %"); 
  
  lcd.display(); 
 
// }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
  }
//}
