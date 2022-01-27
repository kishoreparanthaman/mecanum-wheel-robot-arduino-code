#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "ssid";
const char* password = "passcode";
 const char* mqtt_server = " IP ";
WiFiClient espClient;
PubSubClient client(espClient);



void setup_wifi() 
{
   delay(100);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) 
{
 char message[length];
  int p;
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
  message[i]=(char)payload[i];
  }
  
  Serial.println();

p=atoi(message);
Serial.println(p);
  if(p==0) 
  {
    //forward func
  } 
  if(p==1)
  {
//rev    
  }
 //other if
} 

void reconnect() {
  while (!client.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    String clientId = "Botblue-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      client.subscribe("botblue");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(6000);
    }
  }
}

void setup() {
  
  Serial.println("MQTT");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);


  //pinmode


    }
}

void loop() {

 if (!client.connected()) {
    reconnect();
       
  }
  client.loop();   
    if (firstTime==0) {
            initialpose = (double)ypr[0] * 180/M_PI;
            firstTime = 1;
   client.publish("post1","Ready.....Botblue"); }

    
}

