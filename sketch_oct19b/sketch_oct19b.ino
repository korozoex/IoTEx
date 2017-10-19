#include "ESP8266.h"
#define SSID       "Buffalo-G-7950"
#define PASSWORD   "buff1212wpa2"

ESP8266 wifi(mySerial);

SoftwareSerial mySerial(12, 11); /* RX:D12, TX:D11 */

void setup(void)
{
Serial.begin(9600);
Serial.print("setup begin\r\n");

Serial.print("FW Version: ");
Serial.println(wifi.getVersion().c_str());


if (wifi.setOprToStation()) {
Serial.print("to station ok\r\n");
} else {
Serial.print("to station err\r\n");
}

if (wifi.joinAP(SSID, PASSWORD)) {
Serial.print("Join AP success\r\n");
Serial.print("IP: ");
Serial.println(wifi.getLocalIP().c_str());
} else {
Serial.print("Join AP failure\r\n");
}

Serial.print("setup end\r\n");
}

void loop(void)
{
}
