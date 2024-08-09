#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

// Create an instance of the LED display
ArduinoLEDMatrix display;

void setup() {
    // Initialize the display
    display.begin();

    // Define a simple pattern (just an example)
    uint32_t pattern[4] = {
        0b111111111111,  // Row 1 (all LEDs on)
        0b000000000000,  // Row 2 (all LEDs off)
        0b111100011111,   // Row 3 (all LEDs on)
    };

    // Load the pattern into the display and show it
    display.loadFrame(pattern);
}

void loop() {
    // Keep the pattern static (nothing to do in the loop)
}
