/*
* Gesture Recognition Robot V1.1 - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* This program lets you to control your robot with gesture made by your hand


                                ADXL335
                           ———————————¬                                 
                          |Ø            Z   Ø|                                  
                          |      X<---•      |                   
                          |           |      |                                  
                          |           |Y     |                                  
                          |           ∨      |
                          |                  |
                          |                  |
                          | O  O  O  O  O  O |
                           ———————————¬
                            ST Z  Y  X  -  +
                                                                            Right
                                                                              ∧
                                                                              |
                                                                              |
                                                               Forward <------|------>Backward
                                                                              |
                                                                              |
                                                                              ∨
                                                                             Left
          FOLLOW THIS INSTRUCTION TO CALIBRATE ROBOT

1) Upload ADXL3xx Sketch from examples [ File >> Examples >> Sensor >> AdXL3xx ]
2] Connect the sensor to arduino       [ X --> PIN A3
                                         Y --> PIN A2
                                         Z --> PIN A1 ]
3) Open serial                         [Ctlr + Shift + M]
4) Tilt the sensor in +X, -X, +Y ,-Y direction (forward, backward, left, right) and note down the required x y 
5) Now change the 
      #define forward_val xxx with new +X value                                       
      #define backward_val xxx with new -X value
      #define left_val xxx with new +Y value
      #define right_val xxx with new -Y value
      
*/
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°//

#define forward_val 340       // Change this value to change senstivity for forward direction     /-Default 340-/  *X*
#define backward_val 400      // Change this value to change senstivity for backward direction   /-Default 400-/   *X*
#define left_val 340          // Change this value to change senstivity for left direction      /-Default 340-/    *Y*
#define right_val 400         // Change this value to change senstivity for right direction    /-Default 400-/     *Y*
                                                          
int GNDPin = A4; //Set Analog pin 4 as GND
int VccPin = A5; //Set Analog pin 5 as VCC
int xPin   = A3; //X axis input
int yPin   = A2; //Y axis input
int zPin   = A1; //Z axis input(not used)

int Q1=10,Q2=11,Q3=12,Q4=13; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC

long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
long z; //Variabe for storing Z coordinates
void setup()
{
  Serial.begin(9600);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
}
void loop()
{
  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates
  z = analogRead(zPin); //Reads Z coordinates (Not Used)
    if(x<forward_val)      // Change the value for adjusting sensitivity  
      forward();
    else if(x>backward_val) // Change the value for adjusting sensitivity
      backward();
    else if(y>right_val) // Change the value for adjusting sensitivity
      right();
    else if(y<left_val) // Change the value for adjusting sensitivity
      left();
    else
      stop_();
}

//Functions

void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,LOW);
}
void forward()
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}
void backward()
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
void left()
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}
void right()
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
