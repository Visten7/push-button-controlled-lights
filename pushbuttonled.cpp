// C++ code
//
int buttonstate=0;
int buttonpin=2;
int Ledpin=8;

void setup()
{
  pinMode(buttonpin,INPUT);
  pinMode(Ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
buttonstate=digitalRead(buttonpin);
 if (buttonstate==HIGH)
 {
   digitalWrite(Ledpin,HIGH);
 }
 else
 {
    digitalWrite(Ledpin,LOW);
 }
  Serial.println(buttonstate);
  delay(10);
 }