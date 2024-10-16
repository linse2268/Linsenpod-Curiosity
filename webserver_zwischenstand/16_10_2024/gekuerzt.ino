#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// WiFi credentials
const char* ssid = "ringleben";
const char* password = "theahermine";

// Admin credentials
const char* admin = "admin";
const char* pwd = "passwort";

// DNS Name for mDNS
const char* dns_name = "esp"; 

WiFiClient client;
HTTPClient http;
ESP8266WebServer server(80); // Create web server on port 80

int x = 0; // Zähler-Variable
int direction = 1; // Richtung für den Zähler

// HTML und JavaScript Code als Konstante definieren
const char js_variable_code_part1[] PROGMEM =
R"=====(<html><head><title>Zähler</title></head><body>
    <h1>Zähler Beispiel</h1>
    <p>Aktueller Wert: <span id='counter'>Lade...</span></p>
    <script>
    setInterval(function(){
      var xhr = new XMLHttpRequest();
      xhr.open('GET', '/lol', true);  // Anfrage an den /lol Endpunkt
      xhr.onload = function(){
        if (xhr.status == 200) {
          var response = JSON.parse(xhr.responseText); // JSON verarbeiten
          document.getElementById('counter').innerText = response.wert; // HTML aktualisieren
        }
      };
      xhr.send(); // Anfrage absenden
    }, 1000);  // Alle 1000ms wiederholen
    </script>
  </body></html>)=====";

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    
    // Wait for WiFi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Initialize mDNS
    if (MDNS.begin(dns_name)) {
        Serial.println("dns gestartet");
    }

    // Set up the API endpoint for /lol (JSON response)
    server.on("/lol", handlevariable);

    // Set up the endpoint for serving the HTML page
    server.on("/", handleRoot);

    server.begin(); // Start the server
}

void loop() {
    server.handleClient(); // Handle incoming client requests
    MDNS.update(); // Update mDNS
}

// Function to handle serving the HTML page
void handleRoot() {
    server.send(200, "text/html", js_variable_code_part1); // Sende die HTML-Seite
}

// Function to handle /lol endpoint (JSON response)
void handlevariable() {
    x += direction; // Zähler erhöhen
    if (x > 9) {
        x = 0; // Zähler zurücksetzen, wenn größer als 9
    }

    // Send JSON response
    String jsonResponse = "{ \"wert\": ";
    jsonResponse += String(x);
    jsonResponse += " }";
  
    server.send(200, "application/json", jsonResponse); // Sende die JSON-Antwort
}
