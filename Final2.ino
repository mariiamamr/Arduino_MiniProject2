
//The stepper motor after only it's first cycle retun one point before it's original location but it works normally then in all it's operation and return to it's original position

int angle;
void setup() {
  // put your setup code here, to run once:
  //for stepper
pinMode(A5,OUTPUT);
pinMode(A4,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A0,OUTPUT);
//for keypad
for(int i=1;i<5;i++){
 pinMode(i,INPUT); 
}
//for servo and leds
for(int j=5;j<13;j++){
 pinMode(j,OUTPUT); 
}

}

void loop() {
  // put your main code here, to run repeatedly
  
//  //intializing all valves into 0  
servofunction(0,5,500,true,false); //close to egg valve
servofunction(0,6,500,true,false); //close to vanilla valve
servofunction(0,7,500,true,false); //close to sugar valve
servofunction(0,8,500,true,false); //close to flour valve
  //Making the cake
 servofunction(180,5,500,true,false); //open to egg valve
 steppermotion(5,A5,A4,7); //start the mixer
 servofunction(180,6,100,true,true); //add vanilla
 steppermotion(4,A5,A4,7); //start the mixer again for 4 rotations 
 servofunction(180,7,200,true,false); //add sugar
 steppermotion(10,A5,A4,7); //start the mixer again for 10 rotations
 for(int i=0;i<3;i++){
  servofunction(180,8,100,true,false); //add flour
   steppermotion(4,A5,A4,7); //start the mixer again for 10 rotations
 }

 //Baking the cake
 steppermotion(1,A3,A2,7); //start the production line 
 leds(10,1000); //Cake now in the oven for one second
 steppermotion(1,A3,A2,7); //move the production line again one rotation
 
 delay(1000); //stop  everything for one second "the cake cool down"

 //Decoration stage
 bool choose=false;
 while(!choose){
//for keypad must put the return of the function in an integer then use it to check
int keypressed= checkkeypad();
if(keypressed==1){ //for the first design
  //assume raspberry is at angle 90
servofunction(0,9,100,false,false); //add rasbperry for the first decoration mode
delay(1000);
 ledsonnoff(11,true);
 steppermotion(1,A1,A0,7);
 ledsonnoff(11,false);
 delay(1000);
 steppermotion(1,A1,A0,7);
 //assume pineapple is at angle 90
 servofunction(90,9,100,false,false); //add pineapple for the first decoration mode
 delay(1000);
 ledsonnoff(12,true);
 steppermotion(1,A1,A0,7);
 ledsonnoff(12,false);
 delay(1000);
 steppermotion(1,A1,A0,7);
 choose=true;
}
else if(keypressed==2){ //for the second design
//assume raspberry is at angle 90
   servofunction(0,9,100,false,false); //add rasbperry for the decoration
  ledsonnoff(11,true);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(11,false);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(11,true);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(11,false);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  steppermotion(1,A1,A0,7);
  //assume pineapple is at angle 
    servofunction(90,9,100,false,false); //add pineapple for the decoration
  ledsonnoff(12,true);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(12,false);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(12,true);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  ledsonnoff(12,false);
  delay(1000);
  steppermotion(1,A1,A0,1.75);
  delay(1000);
  steppermotion(1,A1,A0,7); 
  choose=true;
}


else if(keypressed==3){
  //assume raspberry is at angle 90
   servofunction(0,9,100,false,false); //add rasbperry for the decoration
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
   leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
   steppermotion(1,A1,A0,0.25);
  leds(11,1000);
  delay(1000);
  steppermotion(1,A1,A0,7);
  steppermotion(1,A1,A0,7);
  //assume pineapple at angle 90
      servofunction(90,9,100,false,false); //add pineapplefor the decoration
  leds(12,2000);
  choose=true;
 }
else if(keypressed==4){
   servofunction(0,9,100,false,false); //add rasbperry for the decoration
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(12,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(12,1000);
  steppermotion(1,A1,A0,0.5);
   leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(12,1000);
  steppermotion(1,A1,A0,0.5);
  leds(11,1000);
  steppermotion(1,A1,A0,0.5);
  leds(12,1000);
  steppermotion(1,A1,A0,0.25);
  leds(11,1000);
  delay(1000);
  steppermotion(1,A1,A0,7);
  steppermotion(1,A1,A0,7);
  //assume pineapple at angle 90
    servofunction(90,9,100,false,false); //add pineapplefor the decoration
  leds(11,8000); 
  choose=true;
}
 }
}


void steppermotion(int cycles,int pin1,int pin2,float iteration){
  //pin1 for A+/A-
  //pin2 for B+/B-
for(int i=0;i<cycles;i++) {
int x=0;  
while(x<=iteration){ //iterations
 digitalWrite(pin1,1);
 digitalWrite(pin2,0);
delay(1000/(7*cycles)); //speed (1000 "one second" / 7* "no of rotations revolutions")
  digitalWrite(pin1,0);
 digitalWrite(pin2,1);
 delay(1000/(7*cycles)); 
 x++;
 }
}

}
void servomotion (int servo, int angle,bool forvanilla)
{
 digitalWrite(servo, HIGH);
 delayMicroseconds((angle*11) + 500);
 digitalWrite(servo, LOW);
 if(!forvanilla){
  delay(50);                   // Refresh cycle of servo "speed of servo"
 }
 }
void servofunction(int toangle,int servopin,int delayvalue,bool returntozero,bool forvanilla){
  //to go to certain angle
  for (angle = 0; angle <= toangle; angle += 5)  {
   servomotion(servopin, angle,forvanilla);}
   
   
   //to return to zero or not depend on the boolen
   if(returntozero){
    delay(delayvalue);
    for (angle = toangle; angle >= 0; angle -= 5)  {
   servomotion(servopin, angle,forvanilla);  }
   }
 }
 //for leds
void leds(int pinno,int timer){
  digitalWrite(pinno,HIGH);
  delay(timer);
  digitalWrite(pinno,LOW);
 }
void ledsonnoff(int pins,bool on){
  if(on){
    digitalWrite(pins,HIGH);
  }
  else {
    digitalWrite(pins,LOW);
  }
}
//for keypad
int checkkeypad(){
if(digitalRead(3)==HIGH){
  return 1;
}
 else if (digitalRead(2) == HIGH) {
   return 2;
  }
  else if (digitalRead(1) == HIGH) {
   return 3;
  }
  else if (digitalRead(4) == HIGH) {
   return 4;
  }
  return -1;
}
