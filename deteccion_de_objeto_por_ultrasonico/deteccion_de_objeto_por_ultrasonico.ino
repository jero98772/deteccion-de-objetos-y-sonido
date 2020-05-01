

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
long duration;
int distance;

const char *ssid = "ssid";
const char *password = "password";
int milisInterval = 2000;
int count = 0;
ESP8266WebServer server(80);
int sonido = 16;


void handleRoot() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

 
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(2000);
  String html = "<!DOCTYPE html> <html> <body> <h1>distance</h1> <head><meta http-equiv=\"refresh\" content=\"2\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"></head> <div id=\"distancia\">";
  html += distance;
  html += "</div> </body> </html>";
  server.send(200, "text/html", html);
  count++;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(2000);
  for (int piii = 0; piii < 50; piii++) {
    if (distance > 50); {
      analogWrite(sonido , 255);
      delay(piii);
    }
    if (distance > 25); {
      analogWrite(sonido , 255);
      delay(piii);
    }
    if (distance > 10); {
      analogWrite(sonido , 255);
      delay(piii);
    }
  }
}


void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);


  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(2000);
  for (int piii = 0; piii < 50; piii++) {
    if (distance > 50); {
      analogWrite(sonido , 255);
      delay(piii);
    }
    if (distance > 25); {
      analogWrite(sonido , 255);
      delay(piii);
    }
    if (distance > 10); {
      analogWrite(sonido , 255);
      delay(piii);
    }
  }
}
