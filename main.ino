#include <WiFi.h> 
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h> 

#define WIFI_SSID "" 
#define PASSWORD_WIFI "" 
#define BOT_API_TOKEN "" 
#define chat_id "" //nel readme è presente la guida su come ottenere il chat id del bot

int Gas_analog = 4;    // used for ESP32
int Gas_digital = 2;   // used for ESP32

WiFiClientSecure s_client; //wifi client
UniversalTelegramBot bot(BOT_API_TOKEN, s_client); //telegram client 

void setup() {
  WiFi.begin(WIFI_SSID, PASSWORD_WIFI); //connetto al wifi
  s_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); //creo una connessione con Telegram utilizzando un certificato di sicurezza
  
  pinMode(Gas_digital, INPUT);

  while (WiFi.status() != WL_CONNECTED) { //finchè il wifi non è connesso attendi
    delay(500);
  }
  bot.sendMessage(chat_id,"Bot started...");
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);
  if (gassensorAnalog > 1000) {
    bot.sendMessage(chat_id, "ATTENZIONE; RILEVATO GAS!!!");
    bot.sendMessage(chat_id, "ATTENZIONE; RILEVATO GAS!!!");
    bot.sendMessage(chat_id, "ATTENZIONE; RILEVATO GAS!!!");
    delay(1000);
  }
  
  delay(1000);
}
