
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "i3detroit-wpa";
const char* password = "i3detroit";
const char* mqtt_server = "10.13.0.22";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
	  //
	  //
	  // TOOD: Remove all lights, subscribe to several individual lights to prove it's the fuckload of responses
      Serial.println("Subscribing");
      client.subscribe("tele/i3/commons/lights/+/LWT");
      client.subscribe("stat/i3/commons/lights/+/POWER");
      client.publish("cmnd/i3/commons/lights/all/POWER", "");
      client.loop();

      client.subscribe("stat/i3/inside/commons/east-ceiling-fans/POWER");
      client.subscribe("tele/i3/inside/commons/east-ceiling-fans/LWT");
      client.publish("cmnd/i3/inside/commons/east-ceiling-fans/POWER", "");

      client.loop();
      client.subscribe("stat/i3/machineShop/fans/ceilingFan/POWER");
      client.subscribe("tele/i3/machineShop/fans/ceilingFan/LWT");
      client.publish("cmnd/i3/machineShop/fans/ceilingFan/POWER", "");
      client.loop();

      client.subscribe("stat/i3/laserZone/ceilingFan/POWER");
      client.subscribe("tele/i3/laserZone/ceilingFan/LWT");
      client.publish("cmnd/i3/laserZone/ceilingFan/POWER", "");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  Serial.println("loop");
}
