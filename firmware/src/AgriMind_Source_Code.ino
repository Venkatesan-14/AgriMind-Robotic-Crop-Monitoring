/*
 * Project      : AgriMind – Robotic Crop Monitoring System
 * Platform     : ESP32 DevKit V1
 * Language     : Arduino (C++)
 *
 * Description:
 * This firmware controls the AgriMind prototype by managing rover movement,
 * soil probe operation, sensor data acquisition, GPS location tracking,
 * and a Wi-Fi-based dashboard for real-time monitoring.
 *
 * Developed as part of the AgriMind smart agriculture project.
 */

#include <WiFi.h>
#include <WebServer.h>
#include <TinyGPS++.h>


const char* ssid = "Agrimind rover";
const char* password = "12345678";
WebServer server(80);


TinyGPSPlus gps;
HardwareSerial gpsSerial(1);


#define MOTOR1 25
#define MOTOR2 26
#define PROBE1 27
#define PROBE2 14

#define PH_PIN 34
#define MOISTURE_PIN 35


#define PH7 1605
#define PH4 2105


float ph_value = 0;
float moisture = 0;
String gpsStatus = "Searching...";
float lat = 0, lon = 0;

void smartDelay(int ms) {
  unsigned long start = millis();
  while (millis() - start < ms) {
    server.handleClient();  // keeps dashboard alive
  }
}


String getSoilStatus(float m) {
  if (m < 30) return "CRITICAL (Dry)";
  else if (m < 60) return "MODERATE";
  else return "HEALTHY";
}

String getRecommendation(float m) {
  if (m < 30) return "Irrigation Needed Immediately";
  else if (m < 60) return "Monitor Soil Moisture";
  else return "No Action Required";
}


void runDemo() {


  digitalWrite(MOTOR1, HIGH);
  digitalWrite(MOTOR2, HIGH);
  smartDelay(4000);

  digitalWrite(MOTOR1, LOW);
  digitalWrite(MOTOR2, LOW);

 
  digitalWrite(PROBE1, HIGH);
  digitalWrite(PROBE2, LOW);
  smartDelay(2000);

  digitalWrite(PROBE1, LOW);
  digitalWrite(PROBE2, LOW);

 
  smartDelay(3000);


  digitalWrite(PROBE1, LOW);
  digitalWrite(PROBE2, HIGH);
  smartDelay(2000);

  digitalWrite(PROBE1, LOW);
  digitalWrite(PROBE2, LOW);


  int ph_raw = analogRead(PH_PIN);
  int moisture_raw = analogRead(MOISTURE_PIN);

  ph_value = 7 + ((ph_raw - PH7) * (4 - 7) / (PH4 - PH7));
  moisture = map(moisture_raw, 0, 4095, 0, 100);


  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isValid()) {
    lat = gps.location.lat();
    lon = gps.location.lng();
    gpsStatus = "Lat: " + String(lat, 6) + "<br>Lng: " + String(lon, 6);
  } else {
    gpsStatus = "Searching for signal...";
  }
}


void handleRoot() {

  String status = getSoilStatus(moisture);
  String rec = getRecommendation(moisture);

  String color = "lightgreen";
  if (moisture < 30) color = "red";
  else if (moisture < 60) color = "orange";

  String html = "<!DOCTYPE html><html><head>";
  html += "<meta http-equiv='refresh' content='2'>";
  html += "<title>AgriMind Dashboard</title>";

  html += "<style>";
  html += "body{font-family:Arial;background:#0f172a;color:white;text-align:center;}";
  html += ".card{background:#1e293b;padding:20px;margin:15px;border-radius:15px;display:inline-block;width:260px;}";
  html += ".value{font-size:26px;font-weight:bold;}";
  html += "</style></head><body>";

  html += "<h1>🌱 AgriMind Live Dashboard</h1>";

  html += "<div class='card'><h2>pH Value</h2><div class='value'>" + String(ph_value,2) + "</div></div>";

  html += "<div class='card'><h2>Moisture</h2><div class='value'>" + String(moisture,1) + " %</div></div>";

  html += "<div class='card'><h2>Status</h2><div class='value' style='color:" + color + "'>" + status + "</div></div>";

  html += "<div class='card'><h2>Recommendation</h2><div class='value'>" + rec + "</div></div>";

  html += "<div class='card'><h2>GPS</h2><div class='value'>" + gpsStatus + "</div></div>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}


void setup() {
  Serial.begin(115200);

  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(PROBE1, OUTPUT);
  pinMode(PROBE2, OUTPUT);

 
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  
  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.begin();
}


void loop() {
  runDemo();   
