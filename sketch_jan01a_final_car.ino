#include <Ultrasonic.h>
Ultrasonic u =Ultrasonic (2,3);

#include <Servo.h>
Servo s = Servo ();

void setup() {
  // put your setup code here, to run once:
s.attach (4);
pinMode (11,OUTPUT);
pinMode (12,OUTPUT);
pinMode (13,OUTPUT);

pinMode (10,OUTPUT); 
pinMode (9,OUTPUT);
pinMode (8,OUTPUT);

pinMode (5,OUTPUT);
pinMode (6,OUTPUT);
pinMode (7,OUTPUT);


Serial.begin (9600);


}

void loop() {
  // put your main code here, to run repeatedly:

int x =Serial.read();

 if (x=='1'){
  //forward

  s.write (90);
  delay(300);

  int d = u.distanceRead();

  if(d > 30) {
    digitalWrite (12,LOW);
    digitalWrite (13,HIGH);

    digitalWrite (10,HIGH);
    digitalWrite (11,LOW);

    delay(1500);

    digitalWrite (12,LOW);
    digitalWrite (13,LOW);

    digitalWrite (10,LOW);
    digitalWrite (11,LOW);
  }
 }

 if (x=='3'){
  //turn right

   s.write (35);
   delay(300);

  int d = u.distanceRead();

  if(d > 15) {
    digitalWrite (12,LOW);
    digitalWrite (13,HIGH);

    digitalWrite (10,LOW);
    digitalWrite (11,HIGH);

    digitalWrite (6,HIGH);

    delay(400);

    digitalWrite (12,LOW);
    digitalWrite (13,LOW);

    digitalWrite (10,LOW);
    digitalWrite (11,LOW);

    digitalWrite (6,LOW);

    s.write (90);
    delay (200);
  }
 }
 
 if (x=='2'){
  //reverse
  
    digitalWrite (12,HIGH);
    digitalWrite (13,LOW);

    digitalWrite (10,LOW);
    digitalWrite (11,HIGH);

    delay(700);

    digitalWrite (12,LOW);
    digitalWrite (13,LOW);

    digitalWrite (10,LOW);
    digitalWrite (11,LOW);
 }

 if (x=='4'){
   s.write (143);
   delay(200);

  int d = u.distanceRead();

  if(d>15) {
    digitalWrite (12,HIGH);
    digitalWrite (13,LOW);

    digitalWrite (10,HIGH);
    digitalWrite (11,LOW);

    digitalWrite (9,HIGH);

    delay(400);

    digitalWrite (12,LOW);
    digitalWrite (13,LOW);

    digitalWrite (10,LOW);
    digitalWrite (11,LOW);

    digitalWrite (9,LOW);

    s.write (90);
    delay (200);
  }
 }
  digitalWrite (5,HIGH);
  digitalWrite (7,HIGH);
  delay (60);
  digitalWrite (7,LOW);
  delay (60);
  digitalWrite (8,HIGH);
  delay (60);
  digitalWrite (8,LOW);
  delay (60);
 
  
  
}
