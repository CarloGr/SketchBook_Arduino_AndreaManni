/*
 *  Alternating switch
 */

int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the last button state
int buttonPresses = 0;          // Counter for the button

void setup() {
  pinMode(switchPin, INPUT_PULLUP);    // Set the switch pin as input

  Serial.begin(9600);           // Set up serial communication at 9600bps
  buttonState = digitalRead(switchPin);   // read the initial state
}


void loop(){
  val = digitalRead(switchPin);      // read input value and store it in val
  delay(100);                        // Debounce
  if ((val != buttonState) && (val == HIGH)) {     // check if the button is pressed
    buttonPresses++ ;
    Serial.print("Button has been pressed ");
    Serial.print(buttonPresses);
    Serial.println(" times.");
  }
  buttonState = val;                 // save the new state in our variable
}


