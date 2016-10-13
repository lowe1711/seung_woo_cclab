

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  8;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState1 = 0;
void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(2);
  buttonState1 = digitalRead(3);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
      Serial.println("HIGH");
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
  } else {
    // turn LED off:
    Serial.println("LOW");
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
   if (buttonState1 == HIGH) {
    // turn LED on:
      Serial.println("HIGH");
      digitalWrite(11, HIGH);
     
  } else {
    // turn LED off:
    Serial.println("LOW");
    digitalWrite(11, LOW);
   
  }
}


