// Define constants for the pins controlling lights
const uint8_t CABIN_LIGHTS_PIN = 10;      // Pin controlling the cabin lights
const uint8_t STORAGE_LIGHTS_PIN = 11;    // Pin controlling the storage lights
const uint8_t COCKPIT_LIGHTS_PIN = 12;    // Pin controlling the exterior lights

// Define constants for the pins connected to switches
const uint8_t CABIN_LIGHTS_SWITCH_PIN = 2;    // Cabin lights controlled by switch 1
const uint8_t STORAGE_LIGHTS_SWITCH_PIN = 3;  // Storage lights controlled by switch 2
const uint8_t COCKPIT_LIGHTS_SWITCH_PIN = 4;  // Exterior lights controlled by switch 3

// Define constants for pin modes
const uint8_t OUTPUT_PIN_MODE = OUTPUT;
const uint8_t INPUT_PIN_MODE = INPUT;

// Function to control lights based on switch state
void controlLights(uint8_t switchPin, uint8_t lightPin) {
  if (digitalRead(switchPin) == HIGH) {
    digitalWrite(lightPin, HIGH);  // Turn on the light
  } else {
    digitalWrite(lightPin, LOW);   // Turn off the light
  }
}

void setup() {
  // Set pin modes for lights as OUTPUT and switches as INPUT
  pinMode(CABIN_LIGHTS_PIN, OUTPUT_PIN_MODE);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT_PIN_MODE);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT_PIN_MODE);
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT_PIN_MODE);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT_PIN_MODE);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT_PIN_MODE);
}

void loop() {
  // Control cabin lights based on switch 1
  controlLights(CABIN_LIGHTS_SWITCH_PIN, CABIN_LIGHTS_PIN);

  // Control storage lights based on switch 2
  controlLights(STORAGE_LIGHTS_SWITCH_PIN, STORAGE_LIGHTS_PIN);

  // Control exterior lights based on switch 3
  controlLights(COCKPIT_LIGHTS_SWITCH_PIN, COCKPIT_LIGHTS_PIN);
}
