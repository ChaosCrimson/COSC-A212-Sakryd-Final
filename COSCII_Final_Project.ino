//Arduino Final Project
//Use 3 I/O devices with an arduino and a breadboard
//Evan Sakryd
//5/9/24

/*
Apparently I forgot to grab a button, pretty sure my debounce code works,
haven't been able to test it, everything else works

In my photos I partially covered the LED with my finger because it was too bright
*/


const int a=7; 
const int b=6; 
const int c=5; 
const int d=13;   //11 
const int e=12;   //10
const int f=8;    
const int g=9; 
const int dp=4;

const int button = 2; 

const int red= 3;
const int green = 10;
const int blue = 11;

int buttonState;
int lastButtonState = LOW;
int btn = 0;
int counter = 0;

long lastDebounceTime = 0;
long debounceDelay = 50;
///////////////////////////////////////////////////
void setColor(int redValue, int greenValue,  int blueValue)
{
  analogWrite(red, redValue);
  analogWrite(green,  greenValue);
  analogWrite(blue, blueValue);
}

void clearDisplay(void) 
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(g,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);  
  digitalWrite(e,LOW);  
  digitalWrite(f,LOW);
}
//display 1
void display1(void) 
{
  clearDisplay();
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
} 
//display 2
void display2(void) 
{
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
}
  
// display 3
void display3(void) 
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(g,HIGH);
} 
// display 4
void display4(void) 
{
  clearDisplay();
  digitalWrite(f,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  
} 
// display 5
void display5(void)
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
} 
// display 6
void
  display6(void) 
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);  
} 
// display 7
void display7(void)
{
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}
  
// display 8
void display8(void) 
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(e,HIGH);  
  digitalWrite(f,HIGH);
}

void display9(void)  
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(f,HIGH);
}
// display 0
void display0(void) 
{ 
  clearDisplay();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);  
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);  
} 
//////////////////////////////////////////////////////

void setup() 
{ 
  for (int i=4; i<=9; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(red, OUTPUT);              
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT);
} 
void loop() 
{
  int reading = digitalRead(button);    //Check to see if the button is pressed
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();    // Reset timer
  }
  if ((millis() - lastDebounceTime) > debounceDelay)    //Prevent reading the same input multiple times (has happened before)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      if (buttonState == HIGH)    // only increment if the new state is HIGH
      {
        counter++;
      }
    }
  }

  if (counter == 0)               // Maybe I should get rid of the delays
    {
      display0();
      setColor(255, 0, 0);  //Red
      delay(1000);
    }
    else if(counter == 1)
    {
      display1();
      setColor(255, 125, 0);  //Orange
      delay(1000);
    }
    else if(counter == 2)
    {
      display2();
      setColor(255, 255, 0);  //Yellow
      delay(1000);
    }
    else if(counter == 3)
    {
      display3();
      setColor(128, 255, 0);  //Light Green
      delay(1000);
    }
    else if(counter == 4)
    {
      display4();
      setColor(0, 255, 0);  //Green
      delay(1000);
    }
    else if(counter == 5)
    {
      display5();
      setColor(0, 255, 255);  //Light Blue
      delay(1000);
    }
    else if(counter == 6)
    {
      display6();
      setColor(0, 0, 255);  //Blue
      delay(1000);
    }
    else if(counter == 7)
    {
      display7();
      setColor(153, 0, 153);  //Purple
      delay(1000);
    }
    else if(counter == 8)
    {
      display8();
      setColor(255, 153, 204);  //Pink
      delay(1000);
    }
    else      //if(counter == 9)
    {
      display9();
      setColor(255, 255, 255);  //White
      delay(1000);
    }

  lastButtonState = reading;



    
}