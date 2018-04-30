long randNumber;

int ledPins[] = {4,5,6,7,8,9,10};
int buttonPin = 2;
int buttonState = 0;

int pin=0;
int latch=0;
int chosenPin=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  // initialize the pins as OUTPUT
  for(pin=0;pin<7;pin++){
    pinMode(ledPins[pin],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    if(latch==1){ // if button has been pressed
      buttonState = digitalRead(buttonPin);
      if(buttonState==HIGH){
        latch=0;
        TurnOffAll();
        delay(500);
      }else{}
    }else{
      for(pin=0;pin<10;pin++){
        randNumber = random(0,7);
        buttonState = digitalRead(buttonPin);
        digitalWrite(ledPins[randNumber],HIGH);
        delay(20);
        if(buttonState==HIGH){
          latch=1;
          TurnOffAll();
          digitalWrite(ledPins[randNumber],HIGH);
          delay(500);
          break;
        }else{
          digitalWrite(ledPins[randNumber], LOW);
          delay(20);
        }

      }
    }
    
  
}

void lightTest(){
  for(pin=0;pin<7;pin++){
    digitalWrite(ledPins[pin],HIGH);
  }
  delay(500);
  for(pin=0;pin<7;pin++){
    digitalWrite(ledPins[pin],LOW);
  }
  delay(500);
}

void TurnOffAll(){
  for(pin=0;pin<7;pin++){
    digitalWrite(ledPins[pin],LOW);
  }
}

