#include <Arduino.h>
#include <ArduinoGraphics.h>
#include <Arduino_LED_Matrix.h>
#include "RTC.h"


ArduinoLEDMatrix matrix;

void setup() {
    Serial.begin(9600);

    // setup time
    RTC.begin();
    RTCTime mytime(9, Month::AUGUST, 2024, 2, 24, 00, DayOfWeek::FRIDAY, SaveLight::SAVING_TIME_ACTIVE);

    RTC.setTime(mytime);


    matrix.begin();

    matrix.beginDraw();
    matrix.stroke(0xFFFFFFFF);
    // add some static text
    // will only show "UNO" (not enough space on the display)
    const char text[] = "UNO r4";
    matrix.textFont(Font_4x6);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText();

    matrix.endDraw();

    delay(2000);
}

void loop() {
    RTCTime currenttime;
    RTC.getTime(currenttime);

    // Print out date (DD/MM//YYYY)
    Serial.print(currenttime.getDayOfMonth());
    Serial.print("/");
    Serial.print(Month2int(currenttime.getMonth()));
    Serial.print("/");
    Serial.print(currenttime.getYear());
    Serial.print(" - ");

    // Print time (HH/MM/SS)
    Serial.print(currenttime.getHour());
    Serial.print(":");
    Serial.print(currenttime.getMinutes());
    Serial.print(":");
    Serial.println(currenttime.getSeconds());

    // Make it scroll!
    matrix.beginDraw();

    matrix.stroke(0xFFFFFFFF);
    matrix.textScrollSpeed(55);

    // add the text
    const char text[] = "    Hello World!   ";
    matrix.textFont(Font_5x7);
    matrix.beginText(0, 1, 0xFFFFFF);
    matrix.println(text);
    matrix.endText(SCROLL_LEFT);

    matrix.endDraw();
}


