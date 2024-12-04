// Define the analog pin connected to the LDR
const int LDRPin = A0; // Analog pin A0
int LDRValue = 0;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
 
  // Print the value to the serial monitor
  LDRValue = analogRead(LDRPin);
  Serial.println(LDRValue);

  // Wait for a short period to avoid flooding the serial monitor
delay(500);
}