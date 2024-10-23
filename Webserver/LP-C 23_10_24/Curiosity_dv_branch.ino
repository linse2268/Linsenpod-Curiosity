#include <legopowerfunctions.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "webpageCode.h"

// WiFi credentials
const char* ssid = "ringleben";
const char* password = "theahermine";

// Admin credentials
const char* admin = "admin";
const char* pwd = "passwort";

const char* dns_name = "esp"; // DNS name for mDNS

WiFiClient client;
HTTPClient http;
ESP8266WebServer server(80); // Create web server on port 80
LEGOPowerFunctions lego(15);

String currIndex = "";
String response_data;

int x = 0; // Zähler-Variable
int direction = 1; // Richtung für den Zähler

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

    // Define API endpoints
    server.onNotFound([](){
        server.send(404, "text/plain", "Link wurde nicht gefunden!"); // Handle 404 errors
    });

    // Set up the various API endpoints
    server.on("/", handleApiRequest);
    server.on("/api/home", handleApiRequest);
    server.on("/api/buttontest", handleApiRequest);
    server.on("/api/buttontest/w", handleButton1);
    server.on("/api/buttontest/w_release", handleButton1Release);
    server.on("/api/buttontest/a", handleButton2);
    server.on("/api/buttontest/a_release", handleButton2Release);
    server.on("/api/buttontest/s", handleButton3);
    server.on("/api/buttontest/s_release", handleButton3Release);
    server.on("/api/buttontest/d", handleButton4);
    server.on("/api/buttontest/d_release", handleButton4Release);

    server.on("/api/buttontest/ArrowUp", handleButtonUP);
    server.on("/api/buttontest/ArrowUp_release", handleButtonUPRelease);
    server.on("/api/buttontest/ArrowDown", handleButtonDOWN);
    server.on("/api/buttontest/ArrowDown_release", handleButtonDOWNRelease);
    
    // Set up the API endpoint for /lol (JSON response)
    server.on("/lol", handleVariable);

    server.begin(); // Start the server
}

void loop() {
    server.handleClient(); // Handle incoming client requests
    MDNS.update(); // Update mDNS
}

// API endpoint handlers
void handleApiRequest() {
    if (!server.authenticate(admin, pwd)) {
        server.requestAuthentication(); // Prompt for authentication
    } else {
        // Call the appropriate API endpoint handler based on the URL
        String url = server.uri();
        if (url == "/api/home") {
            handleHome();
        } else if (url == "/api/buttontest") {
            handleButtonTest();
        } else if (url == "/") {
            handleRoot();
        }
    }
}

void handleHome() {
    server.send(200, "text/html", homepagecode); // Send homepage content
}

void handleButtonTest() {
    server.send(200, "text/html", button_js_script); // Send button test script
}

void handleButton1() {
    Serial.println("w");
    lego.SingleOutput(0, PWM_REV7, RED, CH4);
    server.send(200, "text/plain", "Button 1");
}

void handleButton1Release() {
    Serial.println("w_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH4);
    server.send(200, "text/plain", "Button 1 release");
}

void handleButton2() {
    Serial.println("a");
    //uhrzeiger richtung und nach links
    lego.SingleOutput(0, PWM_REV7, BLUE, CH4);
    server.send(200, "text/plain", "Button 2");
}

void handleButton2Release() {
    Serial.println("a_release");
    lego.SingleOutput(0, PWM_BRK, BLUE, CH4);
    server.send(200, "text/plain", "Button 2 release");
}

void handleButton3() {
    Serial.println("s");
    lego.SingleOutput(0, PWM_FWD7, RED, CH4);
    
    server.send(200, "text/plain", "Button 3");
}

void handleButton3Release() {
    Serial.println("s_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH4);
    server.send(200, "text/plain", "Button 3 release");
}

void handleButton4() {
    Serial.println("d");
    lego.SingleOutput(0, PWM_FWD7, BLUE, CH4);
    server.send(200, "text/plain", "Button 4");
}

void handleButton4Release() {
    Serial.println("d_release");
    lego.SingleOutput(0, PWM_BRK, BLUE, CH4);
    server.send(200, "text/plain", "Button 4 release");
}


void handleButtonUP() {
    Serial.println("up");
    lego.SingleOutput(0, PWM_REV7, RED, CH1);
    server.send(200, "text/plain", "Button 4");
}

void handleButtonUPRelease() {
    Serial.println("UP_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH1);
    server.send(200, "text/plain", "Button 4 release");
}

void handleButtonDOWN() {
    Serial.println("down");
    lego.SingleOutput(0, PWM_FWD7, RED, CH1);
    server.send(200, "text/plain", "Button 4");
}

void handleButtonDOWNRelease() {
    Serial.println("DOWN_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH1);
    server.send(200, "text/plain", "Button 4 release");
}





// Function to handle serving the counter HTML page
void handleRoot() {
    server.sendHeader("Location", String("/api/home"), true);
    server.send(302, "text/plain", ""); // Redirect to home
}

// Function to handle /lol endpoint (JSON response)
void handleVariable() {
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
