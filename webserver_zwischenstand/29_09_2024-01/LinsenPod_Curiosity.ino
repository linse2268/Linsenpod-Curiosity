// http://arduino.esp8266.com/stable/package_esp8266com_index.json in preferences
//changes have to be made on lines 12, 13 and line 87 (12, 13 server from linux pc and 87 = 12)
//https://www.arduino.cc/reference/en/libraries/esp8266_mdns/
//https://github.com/Links2004/arduinoWebSockets
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "webpageCode.h"

const char* ssid = "ringleben";
const char* password = "theahermine";

//used for bring and get request from mysql
const char* serverName1 = "http://192.168.2.171/bringspecdata.php";
const char* serverName2 = "http://192.168.2.171/getdata.php";

const char* dns_name = "esp";

WiFiClient client;
HTTPClient http;
ESP8266WebServer server(80);

String currIndex = "";
String response_data;

//just for the variable display function(api/variable)
int x = 0;
int direction = 1;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  //wifi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // define dns "esp8266.local"
  if (MDNS.begin(dns_name)) {
    Serial.println("dns gestartet");
  }


  // Define API endpoints
    //error message
  server.onNotFound([](){
    server.send(404, "text/plain", "Link wurde nicht gefunden!");
  });
    //normal endpoints mb do a serverplay funtion to make it look better or make a class
  server.on("/", handleRoot);
  server.on("/api/home", handleHome);
  server.on("/api/download", handleDownload);
  server.on("/api/upload", handleUpload);
  server.on("/api/supload", handleSUpload);
  server.on("/api/flashcard", handleFlashcard);
  server.on("/api/redirecttest", handleRedirect);

  //switch functionality
  server.on("/api/testoutput", handleTestOutput);
  server.on("/api/testoutput/on", handleSwitchOn);
  server.on("/api/testoutput/off", handleSwitchOff);

  //button functionality
  // Define API endpoints
  server.on("/api/buttontest", handleButtonTest);
  server.on("/api/buttontest/w", handleButton1);
  server.on("/api/buttontest/w_release", handleButton1Release);
  server.on("/api/buttontest/a", handleButton2);
  server.on("/api/buttontest/a_release", handleButton2Release);
  server.on("/api/buttontest/s", handleButton3);
  server.on("/api/buttontest/s_release", handleButton3Release);
  server.on("/api/buttontest/d", handleButton4);
  server.on("/api/buttontest/d_release", handleButton4Release);
  
  //livestream
  server.on("/api/videostream", handlevideostream);
  //display updatet variable
  server.on("/api/variable", handlevariable);
  server.begin();
}

void loop() {
  if (currIndex == "bring") {
    sendBringRequest();
  } else if (currIndex == "get") {
    sendGetRequest();
  }
  server.handleClient();
  MDNS.update(); 
}


// API endpoint handlers
void handleRoot() {
  char html[100];
  snprintf(html, sizeof(html), "<html><p> it works! 123 :) </p></html>");
  server.send(200, "text/html", html);
}
//home
void handleHome() {
  String html = "<br>dbring specific data to server: <a href='/api/supload'><button>Click me </button></a>";
  html += "<br>dbring data to server: <a href='/api/upload'><button>Click me </button></a>";
  html += "<br>\n get data from server: <a href='/api/download'><button>Click me </button></a>";
  server.send(200, "text/html", html);
}

//mysql server actions
void handleDownload() {
  currIndex = "get";
  delay(1);
  server.sendHeader("Content-Disposition", "attachment; filename=helloworld.txt");
  server.send(200, "text/plain", response_data);
  String html = "<br>\n getting data :.... ";
  server.send(200, "text/html", html);
}

void handleUpload() {
  currIndex = "bring";
  String html = "<br>\n bringing data :.... ";
  server.send(200, "text/html", html);
}

void handleSUpload() {
  String html = "<head><title>here to upload your own data</title></head><body><form action='http://192.168.2.171/bringspecdata.php' method='GET'>";
  html += "<div><label for='fdata'>new note: </label><input type='text' id='fdata' name='fdata' placeholder = 'place new note here' required></div><br>";
  html += "<div><input type='reset'></div><br>";
  html += "<div><input type='submit'></div></form></body>";
  server.send(200, "text/html", html);
}


//flashcard only js css html project(flashcard variable)
void handleFlashcard() {
  server.send(200, "text/html", flashcardapp);
}

//redirection test/ view how redirection works(now on branch api/redirect leads to api/home)
void handleRedirect() {
  server.sendHeader("Location", String("/api/home"), true);
  server.send ( 302, "text/plain", "");
}


//api switch handlers
void handleTestOutput() {
  server.send(200, "text/html", js_script);
}

void handleSwitchOn() {
  Serial.println("Switch on");
  server.send(200, "text/plain", "Switch on");
}

void handleSwitchOff() {
  Serial.println("Switch off");
  server.send(200, "text/plain", "Switch off");
}



// api button handlers
// api button handlers
void handleButtonTest() {
  server.send(200, "text/html", button_js_script);
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


//lifestream test displayen
void handlevideostream() {
  // Send the HTTP headers
  server.sendHeader("Content-Type", "text/html");
  server.send(200, "text/html", video_stream);

  // Handle the video stream request
  
}

//variablen update tests
void handlevariable() {
  x += direction;
  if (x > 9) {
    x = 0;
  }
  String html = js_variable_code_part1;
  html += String(x);
  html += js_variable_code_part2;
  server.send(200, "text/html", html);
}



// Helper functions
void sendBringRequest() {
  Serial.print("angefangen zu bringen");
  String url = serverName1;
  url += "?temperature=";
  url += String(31.2);

  http.begin(client, url);
  int httpResponseCode = http.GET();

  if (httpResponseCode < 0) {
    Serial.print("Error on sending GET: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  currIndex = "";
  Serial.println("fertig zu bringen");
}
void sendGetRequest() {
  Serial.print("anfangen zu holen");
  String url = serverName2;

  http.begin(client, url);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    response_data = http.getString();
  } else {
    Serial.print("Error on sending GET: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  currIndex = "";
  Serial.println("holen geschafft");
}


