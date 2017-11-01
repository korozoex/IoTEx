#define LIGHT_SIG A0

void setup() {
  Serial.begin( 9600 );
  pinMode( LIGHT_SIG, INPUT );
}

void loop() {
  int sValue = analogRead( LIGHT_SIG );
  Serial.print("the light sensor value is ");
  Serial.println( sValue );
  delay( 1000 );
}
