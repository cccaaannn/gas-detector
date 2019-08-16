

#define gas_sensor_pin A0
#define buzzerpin 13        //buzzerin + sı buraya - si gnd ye

#define red_led 11
#define green_led 10
#define blue_led 9

#define potansiyometre A1

void setup() {

  pinMode(buzzerpin,OUTPUT);

  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);


  led_off(red_led,green_led,blue_led);
  
  Serial.begin(9600);
  Serial.println("isiniyor");
  delay(10000);
  Serial.println("isinidi");

}



void loop() {

  delay(250);
  
  int sensorvalue = analogRead(gas_sensor_pin);
  int potvalue = analogRead(potansiyometre);

  int treshold1 = (potvalue + 300);
  int treshold2 = (potvalue + 400);
  int treshold3 = (potvalue + 500);

  
  Serial.print("sensorvalue: ");
  Serial.print(sensorvalue);
  Serial.print(" tresholdvalues: ");
  Serial.print(treshold1);
  Serial.print(" ");
  Serial.print(treshold2);
  Serial.print(" ");
  Serial.print(treshold3);
  Serial.print(" potvalue: ");
  Serial.print(potvalue);
  Serial.println();
  

  if(sensorvalue > treshold3){
    red(red_led,green_led,blue_led);
    alarm3();
  }
  else if(sensorvalue > treshold2){
    purple(red_led,green_led,blue_led);
    alarm2();
  }
  else if(sensorvalue > treshold1){
    blue(red_led,green_led,blue_led);
    alarm1();
  }
  else{
    green(red_led,green_led,blue_led);
  }

}



void red(int r, int g, int b){
  digitalWrite(r,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(b,HIGH);
}

void purple(int r, int g, int b){
  digitalWrite(r,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(b,LOW);
}

void green(int r, int g, int b){
  digitalWrite(r,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(b,HIGH);
}

void blue(int r, int g, int b){
  digitalWrite(r,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(b,LOW);
}

void led_off(int r, int g, int b){
  digitalWrite(r,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(b,HIGH);
}



void alarm1(){
  digitalWrite(buzzerpin,HIGH);
  delay(500);
  digitalWrite(buzzerpin,LOW);
  delay(500);
}

void alarm2(){
  digitalWrite(buzzerpin,HIGH);
  delay(250);
  digitalWrite(buzzerpin,LOW);
  delay(250);
}

void alarm3(){
  digitalWrite(buzzerpin,HIGH);
}
