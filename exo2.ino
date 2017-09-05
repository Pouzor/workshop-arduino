char pinLed = 8;
char pinButton = 12;

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);
  
  digitalWrite(pinLed, LOW);
}

void loop()
{
  boolean buttonState = digitalRead(pinButton);
  digitalWrite(pinLed, buttonState);
}
