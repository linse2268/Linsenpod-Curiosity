#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>

String currindex = "";
String response_data;
const char* ssid1 = "ringleben";
const char* password1 = "theahermine";


//hier ip vopm pc
const char* serverName1 = "http://192.168.2.160/testfile.php";
const char* serverName2 = "http://192.168.2.160/test_data2.php";
WiFiClient client;
HTTPClient http;
ESP8266WebServer server(80);


void setup() {
  
  Serial.begin(9600);
  WiFi.begin(ssid1, password1);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  server.on("/", []() {
    char html[100];
    snprintf(html, sizeof(html), "<html><p> it works! 123 :) </p></html>");
    server.send(200, "text/html", html);
  });

  server.on("/api/home", []() {
    String html_0 = "<br>dbring specific data to server: <a href='/api/supload'><button>Click me </button></a>";
    String html_1 = "<br>dbring data to server: <a href='/api/upload'><button>Click me </button></a>";
    String html_2 = "<br>\n get data from server: <a href='/api/download'><button>Click me </button></a>";
    server.send(200, "text/html",html_2  + html_0);
  });

  server.on("/api/download", []() {
    currindex = "get";
    delay(1);
    server.sendHeader("Content-Disposition", "attachment; filename=helloworld.txt");
    server.send(200, "text/plain", response_data);
    String html_3 = "<br>\n getting data :.... ";
    server.send(200, "text/html",html_3);
    

  });

  server.on("/api/upload", []() {
    currindex = "bring";
    String html_4 = "<br>\n bringing data :.... ";
    server.send(200, "text/html",html_4);
  });

  server.on("/api/supload", []() {
    String html_5 = "<head><title>here to upload your own data</title></head><body><form action='http://192.168.2.160/testfile.php' method='GET'><div><label for='fdata'>new note: </label><input type='text' id='fdata' name='fdata' placeholder = 'place new note here' required></div><br><div><input type='reset'></div><br><div><input type='submit'></div></form></body>";
    server.send(200, "text/html",html_5);
  });

  server.begin();
}


void loop() {
  
  if (currindex == "bring") {
      Serial.print("angefangen zu bringen");
      String url1 = serverName1;
      url1 += "?temperature=";
      url1 += String(31.2);

      
      http.begin(client, url1);

      int httpResponseCode = http.GET();

      if (httpResponseCode < 0) {
        Serial.print("Error on sending GET: ");
        Serial.println(httpResponseCode);
      }

      http.end();
      currindex = "";
      Serial.println("fertig zu bringen");
  }
  else if(currindex == "get"){ 
      Serial.print("anfangen zu holen");

      String url2 = serverName2;
      
      http.begin(client, url2);

      int httpResponseCode = http.GET();

      if (httpResponseCode > 0) {
        response_data = http.getString();
      } else {
        Serial.print("Error on sending GET: ");
        Serial.println(httpResponseCode);
      }

      http.end();
      currindex = "";
      Serial.println("holen geschafft");
  }
  server.handleClient();
}