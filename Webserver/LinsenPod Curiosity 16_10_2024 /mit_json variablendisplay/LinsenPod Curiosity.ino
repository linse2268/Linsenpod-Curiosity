// http://arduino.esp8266.com/stable/package_esp8266com_index.json in preferences
// changes have to be made on lines 12, 13 and line 87 (12, 13 server from linux pc and 87 = 12)
// https://www.arduino.cc/reference/en/libraries/esp8266_mdns/
// https://github.com/Links2004/arduinoWebSockets
// https://squidpod.github.io/images/pics/here_image.png

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

//neu-neu-neu-neu
int Trigger = 7;
int Echo = 6;


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
    server.on("/api/buttontest/w", handleApiRequest);
    server.on("/api/buttontest/w_release", handleApiRequest);
    server.on("/api/buttontest/a", handleApiRequest);
    server.on("/api/buttontest/a_release", handleApiRequest);
    server.on("/api/buttontest/s", handleApiRequest);
    server.on("/api/buttontest/s_release", handleApiRequest);
    server.on("/api/buttontest/d", handleApiRequest);
    server.on("/api/buttontest/d_release", handleApiRequest);

    server.begin(); // Start the server




    //neu-neu-neu-neu
    pinMode(Trigger,OUTPUT);
    pinMode(Echo,INPUT);
}

void loop() {
    server.handleClient(); // Handle incoming client requests
    MDNS.update(); // Update mDNS


    //neu-neu-neu-neu
    //Messen
    Ultra();

    int dauer = pulseIn(Echo, HIGH); //empfängt
    int entfernung = 0.0343*(dauer/2); 

    
    //Printen zur Kontrolle
    
    Serial.print(entfernung);
    delay(20);
}

// API endpoint handlers
void handleRoot() {
    server.sendHeader("Location", String("/api/home"), true);
    server.send(302, "text/plain", ""); // Redirect to home
}

// Home endpoint
void handleHome() {
    server.send(200, "text/html", homepagecode); // Send homepage content
}

// API button handlers
void handleButtonTest() {
    server.send(200, "text/html", button_js_script); // Send button test script
}

  void handleButton1() {
      Serial.println("w");
      server.send(200, "text/plain", "Button 1");
  }

  void handleButton1Release() {
      Serial.println("w_release");
      server.send(200, "text/plain", "Button 1 release");
  }

  void handleButton2() {
      Serial.println("a");
      server.send(200, "text/plain", "Button 2");
  }

  void handleButton2Release() {
      Serial.println("a_release");
      server.send(200, "text/plain", "Button 2 release");
  }

  void handleButton3() {
      Serial.println("s");
      server.send(200, "text/plain", "Button 3");
  }

  void handleButton3Release() {
      Serial.println("s_release");
      server.send(200, "text/plain", "Button 3 release");
  }

  void handleButton4() {
    Serial.println("d");
    server.send(200, "text/plain", "Button 4");
  }

  void handleButton4Release() {
      Serial.println("d_release");
      server.send(200, "text/plain", "Button 4 release");
  }

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
        } else if (url == "/api/buttontest/w") {
            handleButton1();
        } else if (url == "/api/buttontest/w_release") {
            handleButton1Release();
        } else if (url == "/api/buttontest/a") {
            handleButton2();
        } else if (url == "/api/buttontest/a_release") {
            handleButton2Release();
        } else if (url == "/api/buttontest/s") {
            handleButton3();
        } else if (url == "/api/buttontest/s_release") {
            handleButton3Release();
        } else if (url == "/api/buttontest/d") {
            handleButton4();
        } else if (url == "/api/buttontest/d_release") {
            handleButton4Release();
        }
    }
}


//neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu
//neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu-neu
void Ultra(){
digitalWrite(Trigger, LOW); delay (5); 
digitalWrite(Trigger, HIGH); delay (5); 
digitalWrite(Trigger, LOW);
}

void handlevariable() {
    

    // Send JSON response
    String jsonResponse = "{ \"wert\": ";
    jsonResponse += String(entfernung);
    jsonResponse += " }";
  
    server.send(200, "application/json", jsonResponse); // Sende die JSON-Antwort
}


void handleRoot() {
    server.send(200, "text/html", js_variable_code_part1); // Sende die HTML-Seite
}
