#include "ESP8266.h"
#include <SoftwareSerial.h>

#define SSID "pr500m-f34ea9-1"
#define PASSWORD "bea6d5c0245d3"
#define HOST_NAME "127.0.1.1"
#define FILE_NAME "test.php"

int n = 0;

SoftwareSerial mySerial(2,3);  //RX, TX
ESP8266 wifi(mySerial);

/**
 * 初期設定
 */
void setup(void)
{
  Serial.begin(9600);

  if (wifi.setOprToStationSoftAP()) {
    Serial.println("to station ok");
  } else {
    Serial.println("to station error");
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
    Serial.println("connect success");
  } else {
    Serial.println("connect error");
  }

  if (wifi.disableMUX()) {
    Serial.println("disable mux success");
  } else {
    Serial.println("disable mux error");
  } 
}

void loop(void)
{
  n++;

  // TCPで接続
 wifi.createTCP(HOST_NAME, 80);
  
  // サーバーへ渡す情報
 char sendStr[128];
 sprintf(sendStr, "GET /%s?data=%d HTTP/1.0\r\nHost: %s\r\nUser-Agent: arduino\r\n\r\n", FILE_NAME, n, HOST_NAME);
 wifi.send((const uint8_t*)sendStr, strlen(sendStr));

  Serial.println(n);

  delay(100);
 }
