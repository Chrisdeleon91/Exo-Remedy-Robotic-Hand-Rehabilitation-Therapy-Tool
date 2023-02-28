#include <Servo.h>

Servo myServo;
Servo myServo2;

const int FLEX_PIN = A0;
const int FORCE_PIN = A1;
int FORCE_READ = 0;
const float VCC = 4.98;
const float R_DIV = 51022.0;
const float STRAIGHT_RESISTANCE = 90000.0;
const float BEND_RESISTANCE = 11000.0;
int countsFor10 = 500;
boolean forceApplied = false;
byte servoPos = 0;
int numb = 1;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(A3); 
  myServo2.attach(A4); 
  pinMode(FLEX_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  
  int left=12;
  int right=13; 
  dood(myServo2, left, right);
  forceApplied = false;
  left=10;
  right=11; 
 
  dood(myServo, left, right);
  Serial.println("hello");
  delay(100);
  exit(0); 
  
}

void dood(Servo myServo, int left, int right){
  pinMode(left,OUTPUT);
  pinMode(right,OUTPUT);
  int flexADC = analogRead(FLEX_PIN);
  float flexV = flexADC * VCC/1023.0;
  float flexR = R_DIV *(VCC/flexV - 1.0);
  
  //Serial.println("Resistance: " + String(flexR) + "ohms");

  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);
  angle = angle + 44.0;

  FORCE_READ = analogRead(FORCE_PIN);  
  
  //Serial.print("Force = ");
  //Serial.print(FORCE_READ);     // the raw analog reading
  //Serial.println();
  Serial.println("Bend: " + String(angle) + " degrees");
  if (forceApplied == false)  // only run once until force is applied
  {
    while (analogRead(FORCE_PIN) <= countsFor10)
    {
    //Serial.println("Bend: " + String(angle) + " degrees");
      myServo.write(servoPos);
      digitalWrite(left, LOW);
      digitalWrite(right, HIGH);
      delay(300);  // change delay to suit
      servoPos++;
      //Serial.println("Bend: " + String(angle) + " degrees");
      
    }
    forceApplied = true;
    

    
    digitalWrite(right, LOW);
    delay(100);
    Serial.println("========================================================");
    digitalWrite(left, HIGH);
    delay(100);
    Serial.println("Exiting routine 1");
  
    
  }
  delay(1000);
}
