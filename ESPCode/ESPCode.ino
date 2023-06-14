#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define LED D4

const char* ssid = "AFFA_WIRELESS";
const char* password = "Aff@w!r3l3ss";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello from ESP8266!");
}

void handleOn() {
  String message = server.uri();
  message.remove(0, 1);  // Remove leading forward slash
  processMessage(message);
  server.send(200, "text/plain", "Message received");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.onNotFound(handleOn);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void processMessage(String message) {
  if (message == "1") {
    Serial.println(message);
    digitalWrite(LED, 0);
  } else if (message == "0") {
    Serial.println(message);
    digitalWrite(LED, 1);
  }
}