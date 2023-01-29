#define MOTOR_SOAP 13
#define MOTOR_WATER 12

#define LED 10
#define LED_S 11
#define TRIG 8
#define ECHO 9
#define LOWER_RANGE 50
#define UPPER_RANGE 100


long duration = 0, duration_s = 0;
int distance = 0, distance_s = 0;
short int delayOnce = 0, delayCount = 0, handAway = 15;
void setup(){
	pinMode(LED, OUTPUT);
  	pinMode(LED_S, OUTPUT);
  	pinMode(TRIG, OUTPUT);
  	pinMode(ECHO, INPUT);
  	pinMode(ECHO, INPUT);
  	digitalWrite(MOTOR_SOAP, LOW);
  	digitalWrite(MOTOR_WATER, LOW);
  	Serial.begin(9600);
}

void loop(){
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  
  distance = duration * 0.034 / 2; 
  
  if((distance > LOWER_RANGE && distance < UPPER_RANGE) || handAway < 5){
    if (distance > LOWER_RANGE && distance < UPPER_RANGE){
    	handAway = 0;
    }else{handAway++;}
    Serial.println("Correct!!");
    delayCount++;
    if (delayCount <= 2){
    	Serial.println("Abhi Soap Chalega!");
      	digitalWrite(MOTOR_SOAP, HIGH);
      	digitalWrite(LED_S, HIGH);
      	delay(1000);
    }
    else if(delayCount <=4){delay(1000);}
    else if (delayCount <= 22){
    	Serial.println("Ab Water Chalega!");
      	digitalWrite(MOTOR_WATER, HIGH);
      	digitalWrite(LED, HIGH);
      	delay(1000);
    }else{
      delayCount = 0;
      delay(2000);
    }
  }else{
    if (handAway < 20){
      if (!(handAway < 10)){
        delayCount = 0;
      }else{
        delay(1000);
      }
      handAway++;
    }
  }
  
  
  	digitalWrite(MOTOR_SOAP, LOW);
    digitalWrite(LED_S, LOW);
  
  	digitalWrite(MOTOR_WATER, LOW);
  	digitalWrite(LED, LOW);
  
}
