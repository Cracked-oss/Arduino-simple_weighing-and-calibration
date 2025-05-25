#include <HX711.h>
#include <LiquidCrystal_I2C.h>

// Define pins for HX711
#define DOUT  4
#define CLK   5

// Initialize objects
HX711 scale;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables for calibration
long emptyValue = 0;
long weightValue = 0;
float testWeight = 1555; // Test weight in kg
bool firstPhase = true;
bool calibrationComplete = false;
float calibrationFactor = 0;

void setup() {
    Serial.begin(9600);
    
    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.print("HX711 Calibration");
    delay(2000);
    
    // Initialize HX711
    scale.begin(DOUT, CLK);
    scale.set_scale();
    scale.tare();
    
    Serial.println("Automatic HX711 Calibration:");
    Serial.println("1. Make sure the platform is empty");
    Serial.println("2. Wait 10 seconds for the first measurement");
}

void loop() {

  // Get the average of 10 readings instead of 5
  float weight = scale.get_units(3)/1000.0; 
  
  // Additional filtering for small variations
  // Improved filtering with adjustable threshold and hysteresis
  #define FILTER_THRESHOLD 0.5    // Minimum variation threshold
  #define HYSTERESIS 0.1          // Hysteresis band for stability
  
  static float last_weight = 0;
  if(abs(weight - last_weight) > FILTER_THRESHOLD) {
      // If variation is significant, update
      last_weight = weight;
  } else if (abs(weight - last_weight) > HYSTERESIS) {
      // If within hysteresis band, keep previous value
      weight = last_weight;
  }
  
  {
    if (!calibrationComplete) {
        if (firstPhase) {
            // First phase - measuring empty platform
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Empty platform");
            lcd.setCursor(0, 1);
            lcd.print("Please wait...");
            
            delay(10000); // Wait 10 seconds
            
            // Read average for empty platform
            emptyValue = scale.read_average(20);
            
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Place ");
            lcd.print(testWeight);
            lcd.print("kg");
            lcd.setCursor(0, 1);
            lcd.print("Then wait");
            
            firstPhase = false;
            delay(10000);
            
        } else {
            // Second phase - measuring with weight
            weightValue = scale.read_average(20);
            
            // Calculate calibration factor
            calibrationFactor = (weightValue - emptyValue) / testWeight;
            
            // Display results
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Factor:");
            lcd.setCursor(0, 1);
            lcd.print(calibrationFactor);
            
            Serial.println("\nCalibration results:");
            Serial.print("Empty value: ");
            Serial.println(emptyValue);
            Serial.print("Value with weight: ");
            Serial.println(weightValue);
            Serial.print("Calibration factor: ");
            Serial.println(calibrationFactor);
            Serial.println("\nUse this value in the main code:");
            Serial.print("scale.set_scale(");
            Serial.print(calibrationFactor);
            Serial.println(");");
            
            calibrationComplete = true;
        }
    } else {
        // After calibration - display measured weight
        scale.set_scale(calibrationFactor);
        float weight = scale.get_units(10);
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Weight:");
        lcd.setCursor(0, 1);
        lcd.print(weight, 2);
        lcd.print(" kg");
        
        delay(1000);
    }
}
}
