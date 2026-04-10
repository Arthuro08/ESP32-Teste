#define BLYNK_TEMPLATE_ID "TMPL2M-PVcjMh"
#define BLYNK_TEMPLATE_NAME "desligaLiga"
#define BLYNK_AUTH_TOKEN "w7GnrhISiyudD_RgsmgGBGW8RksDhH-k"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "";
char pass[] = "";

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);
BlynkTImer timer;

const int PIN_TESTE = 2;

void sendFechadura(){
  int s = dht.readStatus();
  if (isnan(s)) return;
  
  Serial.printf("Status: %d", s);
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendFechadura);
  estado = 0;
  pinMode(PIN_TESTE, OUTPUT);
  digitalWrite(PIN_TESTE, HIGH);
}

void loop() {
  Blynk.run();
  timer.run();
  digitalWrite(PIN_TESTE, HIGH);
  Serial.println("Aberto");
  estado = 1;
  delay(2000);
  digitalWrite(PIN_TESTE, LOW);
  delay(2000);
  Serial.println("Fechado");
  estado = 0;
}
