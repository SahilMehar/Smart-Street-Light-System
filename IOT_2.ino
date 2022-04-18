//tig 6
//echo 7


//a0 ---ldr 
//a1---ir
//.....................leds PIN define.................
#define led1 11
#define led2 10
#define led3 9


//.....................sensors PIN var define.................
int LDR=A0;
int IR=4;

//.......................storing varables.................
int irvalue=0;
int ldrvalue=0;
long distvalue=0;



//.....................sensors ultrasonic PIN var define.................

int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo


long duration, cm, inches;      //var


//..................................INITAL OR STATUP SECTION...........................
void setup() {

  Serial.begin (9600);  //for seial and debiging purpose

  //......................pin defines...............
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LDR,INPUT);
  pinMode(IR, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


}
//...................................................................................




//.......................................CHECKING LOOP .................................
void loop() {

  //delay(100 );
distvalue= distance();      //DISTANCE FUN CALL
ldrvalue= ldr();            //LDR FUNCTION CALL
irvalue=ir();               //IR FUNCTION CALL

//ldr on led1 on 

//...................................DESGION MAKING PART.....................



//**************************LDR OPEN**************************************
if(ldrvalue>150)
  {digitalWrite(led1, 0);}              
else
  {digitalWrite(led1, 1);



  
        //**************************IR
      if(irvalue>0)
        {digitalWrite(led2, 1);}
      else
        {digitalWrite(led2,0);}




      //**************************DISTANCE
      if(distvalue<15)
        {digitalWrite(led3, 1);}
      else
        {digitalWrite(led3, 0);}

    }
//**************************LDR CLOSE**************************************



  
  //Serial.print();

 
}
//.........................................LOOP CLOSE...............................







//...........................................
int ir(){
  
   int IRVal=0;
   IRVal = digitalRead(IR);
   Serial.print("IR sensor = ");
   Serial.print(IRVal);
 

   return(IRVal);
}
//.............................................


int ldr(){
 
    int LDRVal=0;
    LDRVal= analogRead(LDR);
    LDRVal = map(LDRVal, 700, 0, 255,0);
    Serial.print("Ldr sensor = ");
    Serial.println(LDRVal);
  return(LDRVal);
}





long distance(){
  
 digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  //Serial.print(inches);
 // Serial.print("in, ");
  Serial.print("  , distance =");
  Serial.print(cm);
  Serial.print("cm ,");
  
  return(cm);
delay(1);
  }
  
