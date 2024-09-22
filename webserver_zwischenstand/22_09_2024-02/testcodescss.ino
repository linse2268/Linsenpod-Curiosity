// http://arduino.esp8266.com/stable/package_esp8266com_index.json in preferences
//changes have to be made on lines 12, 13 and line 87 (12, 13 server from linux pc and 87 = 12)
//https://www.arduino.cc/reference/en/libraries/esp8266_mdns/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
//#include "webpageCode.h"

const char* ssid = "ringleben";
const char* password = "theahermine";

const char* serverName1 = "http://192.168.2.171/bringspecdata.php";
const char* serverName2 = "http://192.168.2.171/getdata.php";

const char* dns_name = "ESP8266";

WiFiClient client;
HTTPClient http;
ESP8266WebServer server(80);

String currIndex = "";
String response_data;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

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
    //normal endpoints
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

void handleHome() {
  String html = "<br>dbring specific data to server: <a href='/api/supload'><button>Click me </button></a>";
  html += "<br>dbring data to server: <a href='/api/upload'><button>Click me </button></a>";
  html += "<br>\n get data from server: <a href='/api/download'><button>Click me </button></a>";
  server.send(200, "text/html", html);
}

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

void handleFlashcard() {
  server.send(200, "text/html", flashcardapp);
}


void handleRedirect() {
  server.sendHeader("Location", String("/api/home"), true);
  server.send ( 302, "text/plain", "");
}


//api switch handlers
void handleTestOutput() {
  String html = "<html><body><h1>Test Output</h1><form><input type='checkbox' id='switch' name='switch'><label for='switch'>Switch</label></form><script>const switchButton = document.getElementById('switch');switchButton.addEventListener('change', () => {if (switchButton.checked) {sendSwitchState('on');} else {sendSwitchState('off');}});function sendSwitchState(state) {const xhr = new XMLHttpRequest();xhr.open('GET', '/api/testoutput/' + state, true);xhr.send();}</script></body></html>";
  server.send(200, "text/html", html);
}

void handleSwitchOn() {
  Serial.println("Switch on");
  server.send(200, "text/plain", "Switch on");
}

void handleSwitchOff() {
  Serial.println("Switch off");
  server.send(200, "text/plain", "Switch off");
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


