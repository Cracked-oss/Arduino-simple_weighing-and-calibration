#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// Define HX711 pins
#define DOUT  4
#define CLK   5

// Initialize HX711 sensor
HX711 scale;

// Initialize I2C LCD (address 0x27, 16 characters on 2 lines)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

float calibration_factor = 96.49; // Calibration factor - adjust as needed

void setup() {
  Serial.begin(9600);
  
  // LCD initialization
  lcd.init();
  lcd.backlight();
  lcd.print("Weight:");
  
  // Initialize HX711 with pins
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); // Apply calibration factor
  scale.tare(); // Reset to zero
}

void loop() {
  scale.power_up();
  delay(10);
  
  // Increase average readings to 5 for better stability
  float weight_kg = scale.get_units(5) / 1000.0;

 // if(weight_kg < 0) {
   // weight_kg > 0;
  //}
  
    // We use the absolute value for display
  float display_weight = abs(weight_kg);
  
  // Adjust filter thresholds
  #define FILTER_THRESHOLD 0.003    // 5g minimum variation
  #define HYSTERESIS 0.002          // 3g hysteresis band
  
  static float last_weight = 0;
  if(abs(weight_kg - last_weight) > FILTER_THRESHOLD) {
      last_weight = weight_kg;
  } else if (abs(weight_kg - last_weight) > HYSTERESIS) {
      weight_kg = last_weight;
  }
  
  lcd.setCursor(0, 1);
  lcd.print(display_weight, 2);
  lcd.print(" kg   ");
  
  Serial.print("Weight: ");
  Serial.print(display_weight, 2);
  Serial.println(" kg   ");

  scale.power_down();
  delay(200);
}
