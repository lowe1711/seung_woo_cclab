
//tmp36 Pin variables
int temperaturePin = 0;
int ledPin= 9;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  float temperature = getVoltage(temperaturePin);
  
  temperature = (temperature -.5)*100;

  Serial.println(temperature);
  delay(100);
  if (temperature > 25){
    brightness = 255;
  }
  else{
    brightness = 0;
  }
  //brightness = map(temperature, 23, 30, 0, 200);
  analogWrite(ledPin, brightness);
  // put your main code here, to run repeatedly:

}

float getVoltage(int pin){
  return (analogRead(pin)*.004882814);
  

}

