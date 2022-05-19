#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

//Vous pouvez utiliser votre nodemcu relié à des interrupteurs physiques pour lancer une url pour activer ou désactiver un appareil tasmota, ou lancer une routine grâce à l'outil web ( virtualsmarthome.xyz/url_routine_trigger/ ) et la skills "URL Routine Trigger" ( amazon.fr/Virtual-Smart-Home-Routine-Trigger/dp/B08SHHS8JZ )
//Cet outil vous permet de créer une sonette virtuelle Alexa déclenchée par une adresse url qu'il génère. Cette sonnette peut déclencher une routine dans Alexa.
//Ce code est à téléverser dans un NodeMcu v3 CH340 ESP8266 ESP 12E ( amzn.to/3HsEPPP ) si vous utilisez une autre version, le pinout des boutons peut être différent.

const char* ssid = "XXXXXXX"; //nom de votre réseau wifi
const char* password = "XXXXXX"; //mot de passe de votre réseau wifi

// Pins utilisés sur le NodeMCU
int button1 = 5; //D1
int button2 = 4; //D2
int button3 = 0; //D3
int button4 = 2; //D4
int button5 = 14; //D5
int button6 = 12; //D6
int button7 = 13; //D7
int button8 = 15; //D8  
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;
int button7State = 0;
int button8State = 0;
int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;
int lastButton5State = 0;
int lastButton6State = 0;
int lastButton7State = 0;
int lastButton8State = 0;
String url1 = "http://"; //url de l'interrupteur 1 sur on
String url2 = "http://"; //url de l'interrupteur 1 sur off
String url3 = "http://"; //url de l'interrupteur 2 sur on
String url4 = "http://"; //url de l'interrupteur 2 sur off
String url5 = "http://"; //url de l'interrupteur 3 sur on
String url6 = "http://"; //url de l'interrupteur 3 sur off
String url7 = "http://"; //url de l'interrupteur 4 sur on
String url8 = "http://"; //url de l'interrupteur 4 sur off
String url9 = "http://"; //url de l'interrupteur 5 sur on
String url10 = "http://"; //url de l'interrupteur 5 sur off
String url11 = "http://"; //url de l'interrupteur 6 sur on
String url12 = "http://"; //url de l'interrupteur 6 sur off
String url13 = "http://"; //url de l'interrupteur 7 sur on
String url14 = "http://"; //url de l'interrupteur 7 sur off
String url15 = "http://"; //url de l'interrupteur 8 sur on
String url16 = "http://"; //url de l'interrupteur 8 sur off


//Delay de protection
unsigned long lastTime = 0;
unsigned long timerDelay = 500;

void setup() {
  Serial.begin(115200);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);


  WiFi.begin(ssid, password);
  Serial.println("Connection");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecté au WiFi avec l'adresse IP: ");
  Serial.println(WiFi.localIP());

  Serial.println("Let's go");
}

void loop() {
  
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);
  button5State = digitalRead(button5);
  button6State = digitalRead(button6);
  button7State = digitalRead(button7);
  button8State = digitalRead(button8);


  if ((millis() - lastTime) > timerDelay) {  

    if (WiFi.status() == WL_CONNECTED) { //Si connecté au Wifi

      if (button1State != lastButton1State) { //Si interrupteur 1 change d'état
        if (button1State == 0) {              //Si interrupteur 1 est ON
          httpGetRequest(url1);  //Effectue une requête HTTP pour lancer l'url1
        }
        else if (button1State == 1) {         //Si interrupteur 1 est OFF
          httpGetRequest(url2);  //Effectue une requête HTTP pour lancer l'url2
        }
      }

      if (button2State != lastButton2State) { //Si interrupteur 2 change d'état
        if (button2State == 0) {              //Si interrupteur 1 est ON
          httpGetRequest(url3); //Effectue une requête HTTP pour lancer l'url3
        }
        else if (button2State == 1) {         //Si interrupteur 2 est OFF
          httpGetRequest(url4);  //Effectue une requête HTTP pour lancer l'url4
        }
      }

      if (button3State != lastButton3State) {
        if (button2State == 0) {
          httpGetRequest(url5);
        }
        else if (button3State == 1) {
          httpGetRequest(url6);
        }
      }

       if (button4State != lastButton4State) {
        if (button4State == 0) {
          httpGetRequest(url7);
        }
        else if (button4State == 1) {
          httpGetRequest(url8);
        }
      }

      if (button5State != lastButton5State) {
        if (button5State == 0) {
          httpGetRequest(url9);
        }
        else if (button5State == 1) {
          httpGetRequest(url10);
        }
      }       

      if (button6State != lastButton6State) {
        if (button6State == 0) {
          httpGetRequest(url11);
        }
        else if (button4State == 1) {
          httpGetRequest(url12);
        }
      }

      if (button7State != lastButton7State) {
        if (button7State == 0) {
          httpGetRequest(url13);
        }
        else if (button7State == 1) {
          httpGetRequest(url14);
        }
      }

      if (button8State != lastButton8State) {
        if (button8State == 0) {
          httpGetRequest(url15);
        }
        else if (button8State == 1) {
          httpGetRequest(url16);
        }
      }
          
      lastButton1State = button1State;
      lastButton2State = button2State;
      lastButton3State = button3State;
      lastButton4State = button4State;
      lastButton5State = button5State;
      lastButton6State = button6State;
      lastButton7State = button7State;
      lastButton8State = button8State;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}


void httpGetRequest(String url) {

  HTTPClient http;

  String serverPath = url; 

  http.begin(serverPath.c_str());

  int httpResponseCode = http.GET();
  Serial.println("Send request");

}
