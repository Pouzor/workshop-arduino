char pinLed = 5;
char pinLed2 = 7;
char pinLed3 = 9;
char pinLed4 = 11;
char pinButton = 6;
char pinButton2 = 8;
char pinButton3 = 10;
char pinButton4 = 12;
int arr[4];
int stack[50];
int randC;
int i = 0;
boolean hasToAddColor = true;

int lastButton = HIGH;
int lastButton2 = HIGH;
int lastButton3 = HIGH;
int lastButton4 = HIGH;

void setup()
{
  arr[0] = 5;
  arr[1] = 7;
  arr[2] = 9;
  arr[3] = 11;

  lastButton = HIGH;
  lastButton2 = HIGH;
  lastButton3 = HIGH;
  lastButton4 = HIGH;

  hasToAddColor = true;
  
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinButton2, INPUT_PULLUP);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinButton3, INPUT_PULLUP);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinButton4, INPUT_PULLUP);
  
  digitalWrite(pinLed, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
}

void loop()
{
  boolean buttonState = digitalRead(pinButton);
  boolean buttonState2 = digitalRead(pinButton2);
  boolean buttonState3 = digitalRead(pinButton3);
  boolean buttonState4 = digitalRead(pinButton4);



if ((buttonState != lastButton) || (buttonState2 != lastButton2) || (buttonState3 != lastButton3) || (buttonState4 != lastButton4)) {
  //TEST CORRECT

  hasToAddColor = true;
}


  if (hasToAddColor == true) {
    randC = random(0,4);

    stack[i] = randC;
    i++;


    for (int j = 0; j < i; j++) {
      digitalWrite(arr[stack[j]], HIGH);
      delay(1000);
      digitalWrite(arr[stack[j]], LOW);   
      delay(1000);   
    }

    hasToAddColor = false;
  }


  /*if (buttonState == LOW)
    digitalWrite(pinLed, HIGH);
  else
    digitalWrite(pinLed, LOW);
    
  if (buttonState2 == LOW)
    digitalWrite(pinLed2, HIGH);
  else
    digitalWrite(pinLed2, LOW);
    
  if (buttonState3 == LOW)
    digitalWrite(pinLed3, HIGH);
  else
    digitalWrite(pinLed3, LOW);
    
  if (buttonState4 == LOW)
    digitalWrite(pinLed4, HIGH);
  else
    digitalWrite(pinLed4, LOW);*/

}
