int RELAY_FROST = A1;
int RELAY_DEFROST = A0;
int LED_FROST_GREEN = 13;
int LED_DEFROST_RED1 = 12;
int LED_DEFROST_RED2 = 11;
int delayDefault = 10000;
int i = 0;
int j = 0;


long delayFrost = 1800000;   //20 min
long delayStandBy = 1200000; //30 min
long delayDefrost = 2400000; //40 min


void setup() {
  // put your setup code here, to run once:
  
  pinMode(RELAY_FROST, OUTPUT);
  pinMode(LED_FROST_GREEN, OUTPUT);
  pinMode(RELAY_DEFROST, OUTPUT);
  pinMode(LED_DEFROST_RED1, OUTPUT);
  pinMode(LED_DEFROST_RED2, OUTPUT);
  
  digitalWrite(RELAY_FROST, LOW); // Estado inicial apagado
  digitalWrite(RELAY_DEFROST, LOW); //Estado inicial apagado

  digitalWrite(LED_FROST_GREEN, LOW);
  digitalWrite(LED_DEFROST_RED1, LOW);
  digitalWrite(LED_DEFROST_RED2, LOW);
  Serial.begin(9600);
  delay(delayStandBy/30);
}

void loop() {

  i=0;

  frost();
  delay(delayFrost);

  
}

void frost() {
    
  while(i < 6){
    //Enciende LEDS de aviso
    digitalWrite(LED_FROST_GREEN, HIGH);
    digitalWrite(LED_DEFROST_RED1, LOW);
    digitalWrite(LED_DEFROST_RED2, LOW);
    delay(10000);
    //Enciende compresor
    digitalWrite(RELAY_FROST, HIGH);
    Serial.println("RELAY_FROST ON");
    delay(delayFrost);
    //Apaga compresor
    digitalWrite(RELAY_FROST, LOW);
    digitalWrite(LED_FROST_GREEN, LOW);
    Serial.println("RELAY_FROST OFF");
    delay(delayStandBy);
    i = i+1;
  }

}

void defrost(){

    
    digitalWrite(RELAY_DEFROST, HIGH);
    digitalWrite(LED_FROST_GREEN, LOW);
    digitalWrite(LED_DEFROST_RED1, LOW);
    digitalWrite(LED_DEFROST_RED2, LOW);
    Serial.println("RELAY_DEFROST PREPARED");
    delay(delayStandBy);
 
    digitalWrite(RELAY_DEFROST, LOW);
    digitalWrite(LED_DEFROST_RED1, HIGH);
    digitalWrite(LED_DEFROST_RED2, HIGH);
    Serial.println("RELAY_DEFROST WORKING");
    delay(delayDefrost/3);

}

