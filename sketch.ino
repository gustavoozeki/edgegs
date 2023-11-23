#include <DHTesp.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFi.h>

// Define o LCD
LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

// Define um ID MQTT aleatório
String ID_MQTT;
char *letters = "abcdefghijklmnopqrstuvwxyz0123456789";

// Define os tópicos MQTT
#define TOPIC_TEMPERATURE   "uc/cm/c3/2324/temperature"

// Atualiza a cada 1 segundo
#define PUBLISH_DELAY 1000  // Alterei para 5 segundos para reduzir o tráfego MQTT
unsigned long publishUpdate;

// Configurações do Wi-Fi
const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";

// Define o Broker MQTT e a PORTA
const char *BROKER_MQTT = "broker.hivemq.com";
int BROKER_PORT = 1883;

// Portas definidas
const int DHT_PIN = 15;
const int LED_PIN = 12;  // Adicionei uma constante para o pino do LED vermelho

// Limites de temperatura para acender o LED vermelho
const float TEMPERATURE_LOWER_LIMIT = 36.0;
const float TEMPERATURE_UPPER_LIMIT = 38.0;

// Variáveis globais
WiFiClient espClient;
PubSubClient MQTT(espClient); 
DHTesp dhtSensor;

// Declarações
void startWifi(void);
void initMQTT(void);
void reconnectMQTT(void);
void reconnectWiFi(void);
void checkWiFIAndMQTT(void);

void setup() {
  Serial.begin(115200);

  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("Initializing...");
  LCD.setCursor(0, 1);
  LCD.print("Please wait...");

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  pinMode(LED_PIN, OUTPUT);

  startWifi();
  initMQTT();
}

void loop() {
  if ((millis() - publishUpdate) >= PUBLISH_DELAY) {
    publishUpdate = millis();
    checkWiFIAndMQTT();

    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    float temperature = data.temperature;

    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("Temp: " + String(temperature, 2) + "C");

    char temperatureStr[6];
    dtostrf(temperature, 4, 2, temperatureStr);

    MQTT.publish(TOPIC_TEMPERATURE, temperatureStr);

    // Lógica para acender o LED vermelho
    if (temperature < TEMPERATURE_LOWER_LIMIT || temperature > TEMPERATURE_UPPER_LIMIT) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }

    MQTT.loop();
  }
}


void startWifi(void) {
  reconnectWiFi();
}

void initMQTT(void) {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}

void reconnectMQTT(void) {
  while (!MQTT.connected()) {
    ID_MQTT = "";
    Serial.print("* Starting connection with broker: ");
    Serial.println(BROKER_MQTT);

    int i = 0;
    for (i = 0; i < 10; i++) {
      ID_MQTT = ID_MQTT + letters[random(0, 36)];
    }

    if (MQTT.connect(ID_MQTT.c_str())) {
      Serial.print("* Connected to broker successfully with ID: ");
      Serial.println(ID_MQTT);
      MQTT.subscribe(TOPIC_TEMPERATURE);
    } else {
      Serial.println("* Failed to connected to broker. Trying again in 2 seconds.");
      delay(2000);
    }
  }
}

void checkWiFIAndMQTT(void) {
  if (!MQTT.connected())
    reconnectMQTT();
  reconnectWiFi();
}

void reconnectWiFi(void) {
  if (WiFi.status() == WL_CONNECTED)
    return;

  WiFi.begin(SSID, PASSWORD);

  Serial.print("* Connecting to Wifi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("* Successfully connected to Wi-Fi, with local IP: ");
  Serial.println(WiFi.localIP());

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Finished!");
  LCD.setCursor(0, 1);
  LCD.print("-- ");
  LCD.print(WiFi.localIP());
}

