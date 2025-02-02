//include the libraries
#include <legopowerfunctions.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
//import the html codes
#include "webpageCode.h"

// WiFi credentials
const char* ssid = "redminote9";
const char* password = "PraktikuM";

// Admin credentials for the website security
const char* admin = "admin";
const char* pwd = "passwort";

const char* dns_name = "esp"; // DNS name for mDNS

WiFiClient client;//configurating the wifi and http client
HTTPClient http;
ESP8266WebServer server(80); // Create web server on port 80
LEGOPowerFunctions lego(15); //calibrates the ir transmittor to port 15(gpio8 -> D8)

int SPEED = 4; //starting speed cap
unsigned int sliderValue = 51;
//setup function
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
    server.on("/home", handleApiRequest);
    server.on("/drivepanel", handleApiRequest);
    //different inputs for driving n steering
    server.on("/drivepanel/w", handleButtonW);
    server.on("/drivepanel/w_release", handleButtonWRelease);
    server.on("/drivepanel/a", handleButtonA);
    server.on("/drivepanel/a_release", handleButtonARelease);
    server.on("/drivepanel/s", handleButtonS);
    server.on("/drivepanel/s_release", handleButtonSRelease);
    server.on("/drivepanel/d", handleButtonD);
    server.on("/drivepanel/d_release", handleButtonDRelease);

    server.on("/drivepanel/ArrowUp", handleButtonUP);
    server.on("/drivepanel/ArrowUp_release", handleButtonUPRelease);
    server.on("/drivepanel/ArrowDown", handleButtonDOWN);
    server.on("/drivepanel/ArrowDown_release", handleButtonDOWNRelease);
          
    server.on("/drivepanel/ArrowLeft", handleArrowL);
    server.on("/drivepanel/ArrowRight", handleArrowR);

    server.on("/drivepanel/p", handleButtonP);
    server.on("/drivepanel/p_release", handleButtonP_release);
    // Set up the API endpoint for /lol (JSON response)
    server.on("/var", handleVariable);
    server.on("/drivepanel/honk", handleHonk);

    
    server.on("/json_test", HTTP_POST, handleData);


    server.begin(); // Start the server
}
//normal loop
void loop() {
    server.handleClient(); // Handle incoming client requests
    MDNS.update(); // Update mDNS
}

// API endpoint handlers
//short security check
void handleApiRequest() {
    if (!server.authenticate(admin, pwd)) {
        server.requestAuthentication(); // Prompt for authentication
    } else {
        // Call the appropriate API endpoint handler based on the URL
        String url = server.uri();
        if (url == "/home") {
            handleHome();
        } else if (url == "/drivepanel") {
            handledrivepanel();
        } else if (url == "/") {
            handleRoot();
        }
    }
}
// it redirects [ip]/[root] to [ip]/home
void handleRoot() {
    server.sendHeader("Location", String("/home"), true);
    server.send(302, "text/plain", ""); // Redirect to home
}

// endpoint on [ip]/home
void handleHome() {
    server.send(200, "text/html", homepagecode); // Send homepage content
}
// endpoint on [ip]/drivepanel ->the main oage for driving the rover
void handledrivepanel() {
    server.send(200, "text/html", drivepanel); // Send button test script
}

void handleData() {
    if (server.hasArg("plain")) { // Check if data is received
        String json = server.arg("plain"); // Read the raw JSON data
        Serial.println("Empfangene Daten:");
        Serial.println(json); // Print JSON data to serial monitor
        
        // Initialize the JSON document
        StaticJsonDocument<200> doc;  // Use StaticJsonDocument with a suitable size
        
        // Deserialize the JSON document
        DeserializationError error = deserializeJson(doc, json);
        
        if (error) {
            Serial.print("Fehler beim JSON-Parsing: ");
            Serial.println(error.c_str());
            server.send(400, "text/plain", "Fehler beim JSON-Parsing.");
            return;
        }

        // Extract the "value" from JSON and convert it to String
        String sliderValue = String(doc["value"].as<int>());  // Explicitly convert to String
        Serial.println("Aktualisierter Slider-Wert: " + sliderValue);
        
        // Respond to the client
        server.send(200, "text/plain", "Daten empfangen!");
    } else {
        server.send(400, "text/plain", "Keine Daten erhalten.");
    }
}




//steering endpoints
//w or fwd
void handleButtonW() {
     int pwmwert;
    Serial.println("w pressed, SPEED = " + String(SPEED));
    switch (SPEED) {
        case 1: pwmwert = PWM_REV1; break;
        case 2: pwmwert = PWM_REV2; break;
        case 3: pwmwert = PWM_REV3; break;
        case 4: pwmwert = PWM_REV4; break;
        case 5: pwmwert = PWM_REV5; break;
        case 6: pwmwert = PWM_REV6; break;
        case 7: pwmwert = PWM_REV7; break;
        default: pwmwert = PWM_FLT; break;
    }
    lego.SingleOutput(0, pwmwert, RED, CH4);
    server.send(200, "text/plain", "Button S pressed");
}

void handleButtonWRelease() {
    Serial.println("w_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH4);
    server.send(200, "text/plain", "Button 3 release");
}




void handleButtonP() {
     int pwmwert;
    Serial.println("w pressed, SPEED = " + String(SPEED));
    //lego.SingleOutput(0, PWM_REV6, BLUE, CH1);
    server.send(200, "text/plain", "Button p pressed");
}
//added, dass wenn man p loslässt, der motor/der launcher sich einmal dreht
void handleButtonP_release() {
    Serial.println("p_release");
    lego.SingleOutput(0, PWM_REV6, BLUE, CH1);
    delay(1000);
    lego.SingleOutput(0, PWM_BRK, BLUE, CH1);
    server.send(200, "text/plain", "Button p release");
}


//s or backwards
void handleButtonS() {
    int pwmwert;
    Serial.println("s pressed, SPEED = " + String(SPEED));
    switch (SPEED) {
        case 1: pwmwert = PWM_FWD1; break;
        case 2: pwmwert = PWM_FWD2; break;
        case 3: pwmwert = PWM_FWD3; break;
        case 4: pwmwert = PWM_FWD4; break;
        case 5: pwmwert = PWM_FWD5; break;
        case 6: pwmwert = PWM_FWD6; break;
        case 7: pwmwert = PWM_FWD7; break;
        default: pwmwert = PWM_FLT; break;
    }
    lego.SingleOutput(0, pwmwert, RED, CH4);
    server.send(200, "text/plain", "Button W pressed");
}

void handleButtonSRelease() {
    Serial.println("s_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH4);
    server.send(200, "text/plain", "Button 1 release");
}

//steering for a or left
void handleButtonA() {
    Serial.println("a");
    //uhrzeiger richtung und nach links
    lego.SingleOutput(0, PWM_REV7, BLUE, CH4);
    server.send(200, "text/plain", "Button 2");
}

void handleButtonARelease() {
    Serial.println("a_release");
    lego.SingleOutput(0, PWM_BRK, BLUE, CH4);
    server.send(200, "text/plain", "Button 2 release");
}
//d or steering for right
void handleButtonD() {
    Serial.println("d");
    lego.SingleOutput(0, PWM_FWD7, BLUE, CH4);
    server.send(200, "text/plain", "Button 4");
}

void handleButtonDRelease() {
    Serial.println("d_release");
    lego.SingleOutput(0, PWM_BRK, BLUE, CH4);
    server.send(200, "text/plain", "Button 4 release");
}

//pulling cam up
void handleButtonUP() {
    int pwmwert;
    Serial.println("UP pressed, SPEED = " + String(SPEED));
    switch (SPEED) {
        case 1: pwmwert = PWM_REV1; break;
        case 2: pwmwert = PWM_REV2; break;
        case 3: pwmwert = PWM_REV3; break;
        case 4: pwmwert = PWM_REV4; break;
        case 5: pwmwert = PWM_REV5; break;
        case 6: pwmwert = PWM_REV6; break;
        case 7: pwmwert = PWM_REV7; break;
        default: pwmwert = PWM_FLT; break;
    }
    lego.SingleOutput(0, pwmwert, RED, CH1);
    server.send(200, "text/plain", "Up Button Pressed");
}

void handleButtonUPRelease() {
    Serial.println("UP_release");
    lego.SingleOutput(0, PWM_BRK, RED, CH1);
    server.send(200, "text/plain", "Button 4 release");
}

//pushing cam down
void handleButtonDOWN() {
    int pwmwert;
    Serial.println("DOWN pressed, SPEED = " + String(SPEED));
    switch (SPEED) {
        case 1: pwmwert = PWM_FWD1; break;
        case 2: pwmwert = PWM_FWD2; break;
        case 3: pwmwert = PWM_FWD3; break;
        case 4: pwmwert = PWM_FWD4; break;
        case 5: pwmwert = PWM_FWD5; break;
        case 6: pwmwert = PWM_FWD6; break;
        case 7: pwmwert = PWM_FWD7; break;
        default: pwmwert = PWM_FLT; break;
    }
    lego.SingleOutput(0, pwmwert, RED, CH1);
    server.send(200, "text/plain", "Down Button Pressed");
}

void handleButtonDOWNRelease() {
    Serial.println("DOWN released");
    lego.SingleOutput(0, PWM_BRK, RED, CH1); // or PWM_FLT if braking isn't ideal
    server.send(200, "text/plain", "Down Button Released");
}

// l and r are left and right arrows -> regulating the speed from 1 - 7
void handleArrowL() {
    if (SPEED>1){
      Serial.println("speed down");
      SPEED -= 1;
      server.send(200, "text/plain", "Button 4");
    }
    
}
void handleArrowR() {
  if (SPEED<7){
    Serial.println("speed up");
    SPEED += 1;
    server.send(200, "text/plain", "Button 4");
  }
}

// Function to handle /var endpoint (JSON response) -> sends needed data which has to be displayed to the website via json string
void handleVariable() {
    // Send JSON response
    String jsonResponse = "{ \"wert\": ";
    jsonResponse += String(SPEED);//in this case it sends the current speed cap(standard 4)
    jsonResponse += " }";
  
    server.send(200, "application/json", jsonResponse); // Sende die JSON-Antwort zu [ip]/var
}

void handleHonk(){
  tone(12, sliderValue*10);
  delay(1000);
  noTone(12);
  server.send(200, "text/plain", "honked");
}
