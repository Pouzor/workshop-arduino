char pinLed = 5;
char pinLed2 = 7;
char pinLed3 = 9;
char pinLed4 = 11;
char pinButton = 6;
char pinButton2 = 8;
char pinButton3 = 10;
char pinButton4 = 12;

// Leds array mapping
int mapping[4];

// Pile des couleurs
int stack[50];
int randC;

// Index lecture + index joueur
int i = 0;
int current = 0;

boolean hasToAddColor = true;

int lastButton = HIGH;
int lastButton2 = HIGH;
int lastButton3 = HIGH;
int lastButton4 = HIGH;

void setup()
{
  // Pin mapping for led random choice
  mapping[0] = 5;
  mapping[1] = 7;
  mapping[2] = 9;
  mapping[3] = 11;

  // Var pour la game
  lastButton = HIGH;
  lastButton2 = HIGH;
  lastButton3 = HIGH;
  lastButton4 = HIGH;
  // If new color is the stack is needed
  hasToAddColor = false;

  // Configure led / button

  // TODO CONFIGURE PIN MODE

  // START SHUT DOWN ALL LED
  digitalWrite(pinLed, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);

  // START THE GAME
  addColor();
}

// Light on/off all led at the same time
void writeAll(int value) {  
  // TODO Light on/off all light
}

// Add random color to the pile
void addColor() {
  current = 0;
  randC = random(0,4);

  stack[i] = randC;
  i++;

  // TODO REPLAY ALL THE SEQUENCE WITH NEW COLOR AT THE END
}

void confirmPressure() {
  // Blink to confirm button pressure

  // TODO LIGHT LED TO CONFIRM BUTTON PRESSING
}


// End game action and reset
int failGame() {
  i = 0;
  current = 0;
  hasToAddColor = true;

  // TODO PLAY LED SEQUENCE TO CONFIRM THE ENDING GAME
}

// Main loop
void loop()
{
  // Read Input

  // TODO SET buttonState* with theirs respective values

  if ((buttonState != lastButton) || (buttonState2 != lastButton2) || (buttonState3 != lastButton3) || (buttonState4 != lastButton4)) {
    //TEST CORRECT
    if (buttonState != lastButton) {
      if (stack[current] == 0) {
        // GOOD PUSH
        current++;
        if (current == i) {
          // ALL GOOD CHOICE, ADD ONE COLOR
          hasToAddColor = true;
        }
      } else {
        // WRONG PUSH
        failGame();
      }
    }

    if (buttonState2 != lastButton2) {
      if (stack[current] == 1) {
        // GOOD PUSH
        current++;
        if (current == i) {
          // ALL GOOD CHOICE, ADD ONE COLOR
          hasToAddColor = true;
        }
      } else {
        // WRONG PUSH
        failGame();
      }
    }

    if (buttonState3 != lastButton3) {
      if (stack[current] == 2) {
        // GOOD PUSH
        current++;
        if (current == i) {
          // ALL GOOD CHOICE, ADD ONE COLOR
          hasToAddColor = true;
        }
      } else {
        // WRONG PUSH
        failGame();
      }
    }

    if (buttonState4 != lastButton4) {
      if (stack[current] == 3) {
        // GOOD PUSH
        current++;
        if (current == i) {
          // ALL GOOD CHOICE, ADD ONE COLOR
          hasToAddColor = true;
        }
      } else {
        // WRONG PUSH
        failGame();
      }
    }

    // RESET
    lastButton = HIGH;
    lastButton2 = HIGH;
    lastButton3 = HIGH;
    lastButton4 = HIGH;

    confirmPressure();

  }

  // At the end, if needed, add color
  if (hasToAddColor == true) {
    addColor();
    hasToAddColor = false;
  }
}
