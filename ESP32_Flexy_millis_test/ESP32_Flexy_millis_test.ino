/*
 * test millis()
 * 2024.01.17 Jay Teramoto
*/

long last_excution_time;
int count;

void setup() {
    delay(500);
    Serial.begin(9600);
    while(!Serial){};
    delay(500);
 
    last_excution_time = millis();
    count = 0;
    Serial.println();
    Serial.println("Start millis test");
    Serial.print(count);
    Serial.print(" ");
    Serial.println(last_excution_time);

}

void loop() {
  if (millis() - last_excution_time > 4999){
    count++;
    last_excution_time = millis();
    Serial.print(count);
    Serial.print(" ");
    Serial.println(last_excution_time);
  }
}