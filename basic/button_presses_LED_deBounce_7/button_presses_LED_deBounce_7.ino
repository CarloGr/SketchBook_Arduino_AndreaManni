/*
 *  Alternating switch
 */

int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int valBounce ;                 // variable for debouncing
int buttonState;                // variable to hold the last button state
int lightMode = 0;              // State of the light
int LED = 12;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);    // Set the switch pin as input
  pinMode(LED, OUTPUT);

  buttonState = digitalRead(switchPin);   // read the initial state

}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(10);                        // Debounce
  valBounce = digitalRead(switchPin);      // read input value and store it in val

  if ((val == valBounce) && (val != buttonState) && (val == HIGH)) {     // check if the button is pressed
    lightMode = 1 -lightMode ;    // Now with DeBounce
  }
  digitalWrite(LED,lightMode);
  buttonState = val;                 // save the new state in our variable
}




