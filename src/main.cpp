#include <Arduino.h>
#include <TinyGPS++.h>
#include <AltSoftSerial.h>

// Define the pins for AltSoftSerial
#define GPS_RX_PIN 8
#define GPS_TX_PIN 7

AltSoftSerial gpsSerial; // Define AltSoftSerial object for GPS communication

TinyGPSPlus gps; // Create a TinyGPS++ object

void setup() {
    Serial.begin(115200); // Initialize serial communication for debugging
    gpsSerial.begin(9600); // Initialize AltSoftSerial for GPS module
}

void loop() {
    // Read data from GPS module
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) {
            if (gps.location.isValid()) {
                Serial.print("GPS:");
                Serial.print(gps.location.lat(), 6); // Latitude
                Serial.print(", ");
                Serial.print(gps.location.lng(), 6); // Longitude
                Serial.print(", ");
                Serial.print(gps.speed.knots()); // Speed in knots
                Serial.print(", ");
                Serial.print(gps.course.deg()); // Course in degrees from true north
                Serial.print(", ");
                Serial.print(gps.altitude.meters()); // Altitude in meters
                Serial.print(", ");
                Serial.print(gps.satellites.value()); // Number of satellites in view
                Serial.print(", ");
                Serial.print(gps.hdop.hdop()); // HDOP (Horizontal Dilution of Precision)
                Serial.println();
            }
        }
    }
}
