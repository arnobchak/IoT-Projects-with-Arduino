#include <LiquidCrystal.h>
#include <DHT.h>

// Define the DHT sensor type and pin
#define DHTPIN 2       // Pin connected to the DHT sensor
#define DHTTYPE DHT11  // Replace with DHT22 if you're using DHT22
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(6, 7, 5, 4, 3, 8);

void setup() {
  // Initialize the DHT sensor
  dht.begin();

  // Initialize the LCD
  lcd.begin(16, 2);

  // Print a message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);  // Wait for the sensor to stabilize
}

void loop() {
  // Read temperature and humidity from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(2000);  // Wait before retrying
    return;
  }

  // Display temperature on the first row
  lcd.clear();
  lcd.setCursor(0, 0);  // Set the cursor to the top-left
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  // Display humidity on the second row
  lcd.setCursor(0, 1);  // Set the cursor to the second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // Wait for a short period before updating again
  delay(2000);
}
