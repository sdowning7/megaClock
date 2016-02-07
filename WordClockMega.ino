// Display output pin assignments

int ITIS = 22;
int MTEN  = 23;
int HALF  = 24;
int QUARTER = 25;
int TWENTY  = 26;
int MFIVE = 27;
int MINUTES = 28;
int PAST  = 29;

int TO  = 30;
int ONE = 31;
int TWO = 32;
int THREE = 33;
int FOUR  = 34;
int HFIVE = 35;
int SIX = 36;

int SEVEN = 37;
int EIGHT = 38;
int NINE  = 39;
int HTEN  = 40;
int ELEVEN  = 41;
int TWELVE  = 42;
int OCLOCK  = 43;


int  hour = 9, minute = 30, second = 00;
static unsigned long msTick = 0; // the number of Millisecond Ticks since we last

// incremented the second counter
int  count;
int selftestmode;



// hardware constants
int MinuteButtonPin = 2;
int HourButtonPin = 3;



void setup()
{
  // initialize the appropriate pins as outputs:
  pinMode(ITIS, OUTPUT);
  pinMode(MTEN, OUTPUT);
  pinMode(HALF, OUTPUT);
  pinMode(QUARTER, OUTPUT);
  pinMode(TWENTY,OUTPUT);
  pinMode(MFIVE,OUTPUT);
  pinMode(MINUTES,OUTPUT);
  pinMode(PAST,OUTPUT);
  pinMode(TO,OUTPUT);
  pinMode(ONE,OUTPUT);
  pinMode(TWO,OUTPUT);
  pinMode(THREE,OUTPUT);
  pinMode(FOUR,OUTPUT);
  pinMode(HFIVE,OUTPUT);
  pinMode(SIX,OUTPUT);
  pinMode(SEVEN,OUTPUT);
  pinMode(EIGHT,OUTPUT);
  pinMode(NINE,OUTPUT);
  pinMode(HTEN,OUTPUT);
  pinMode(ELEVEN,OUTPUT);
  pinMode(TWELVE,OUTPUT);
  pinMode(OCLOCK,OUTPUT);

  //pinMode(BrightnessPin, INPUT);
  pinMode(MinuteButtonPin, INPUT);
  pinMode(HourButtonPin, INPUT);
  digitalWrite(MinuteButtonPin, HIGH);  //set internal pullup
  digitalWrite(HourButtonPin, HIGH); //set internal pullup

  Serial.begin(9600);

  /*
    while(true){
    Serial.println("In: ");
    Serial.println(analogRead(0), DEC);
    Serial.println(", ");
    Serial.println(digitalRead(MinuteButtonPin), DEC);
    Serial.println(", ");
    Serial.println(digitalRead(HourButtonPin), DEC);
    Serial.println();
    }
  */

  msTick = millis();    // Initialise the msTick counter
  displaytime();        // display the current time
}



void ledsoff(void) {
  digitalWrite(ITIS, LOW);
  digitalWrite(MTEN, LOW);
  digitalWrite(HALF, LOW);
  digitalWrite(QUARTER, LOW);
  digitalWrite(TWENTY,LOW);
  digitalWrite(MFIVE,LOW);
  digitalWrite(MINUTES,LOW);
  digitalWrite(PAST,LOW);
  digitalWrite(TO,LOW);
  digitalWrite(ONE,LOW);
  digitalWrite(TWO,LOW);
  digitalWrite(THREE,LOW);
  digitalWrite(FOUR,LOW);
  digitalWrite(HFIVE,LOW);
  digitalWrite(SIX,LOW);
  digitalWrite(SEVEN,LOW);
  digitalWrite(EIGHT,LOW);
  digitalWrite(NINE,LOW);
  digitalWrite(HTEN,LOW);
  digitalWrite(ELEVEN,LOW);
  digitalWrite(TWELVE,LOW);
  digitalWrite(OCLOCK,LOW);
  
}

/*void WriteLEDs(void) {
  // Now we write the actual values to the hardware
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  digitalWrite(LEDStrobePin, HIGH);
  delay(2);
  digitalWrite(LEDStrobePin, LOW);


}*/

void selftest(void) {
  Serial.println("TEST");

  digitalWrite(ITIS, HIGH);
  delay(500);
  digitalWrite(ITIS, LOW);
  digitalWrite(MTEN, HIGH);
  delay(500);
  digitalWrite(MTEN, LOW);
  digitalWrite(HALF, HIGH);
  delay(500);
  digitalWrite(HALF, LOW);
  digitalWrite(QUARTER, HIGH);
  delay(500);
  digitalWrite(QUARTER, LOW);
  digitalWrite(TWENTY,HIGH);
  delay(500);
  digitalWrite(TWENTY, LOW);
  digitalWrite(MFIVE,HIGH);
  delay(500);
  digitalWrite(MFIVE, LOW);
  digitalWrite(MINUTES,HIGH);
  delay(500);
  digitalWrite(MINUTES, LOW);
  digitalWrite(PAST,HIGH);
  delay(500);
  digitalWrite(PAST, LOW);
  digitalWrite(TO,HIGH);
  delay(500);
  digitalWrite(TO, LOW);
  digitalWrite(ONE,HIGH);
  delay(500);
  digitalWrite(ONE, LOW);
  digitalWrite(TWO,HIGH);
  delay(500);
  digitalWrite(TWO, LOW);
  digitalWrite(THREE,HIGH);
  delay(500);
  digitalWrite(THREE, LOW);
  digitalWrite(FOUR,HIGH);
  delay(500);
  digitalWrite(FOUR, LOW);
  digitalWrite(HFIVE,HIGH);
  delay(500);
  digitalWrite(HFIVE, LOW);
  digitalWrite(SIX,HIGH);
  delay(500);
  digitalWrite(SIX, LOW);
  digitalWrite(SEVEN,HIGH);
  delay(500);
  digitalWrite(SEVEN, LOW);
  digitalWrite(EIGHT,HIGH);
  delay(500);
  digitalWrite(EIGHT, LOW);
  digitalWrite(NINE,HIGH);
  delay(500);
  digitalWrite(NINE, LOW);
  digitalWrite(HTEN,HIGH);
  delay(500);
  digitalWrite(HTEN, LOW);
  digitalWrite(ELEVEN,HIGH);
  delay(500);
  digitalWrite(ELEVEN, LOW);
  digitalWrite(TWELVE,HIGH);
  delay(500);
  digitalWrite(TWELVE, LOW);
  digitalWrite(OCLOCK,HIGH);
  delay(500);
  digitalWrite(OCLOCK, LOW);

  
}


void displaytime(void) {

  // start by clearing the display to a known state
  ledsoff();
  
  Serial.println("It is ");
  digitalWrite(ITIS, HIGH);

  // now we display the appropriate minute counter
  if ((minute > 4) && (minute < 10)) {
    digitalWrite(MFIVE, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Five Minutes ");
  }
  if ((minute > 9) && (minute < 15)) {
    digitalWrite(MTEN, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Ten Minutes ");
  }
  if ((minute > 14) && (minute < 20)) {
    digitalWrite(QUARTER, HIGH);
    Serial.println("Quarter ");
  }
  if ((minute > 19) && (minute < 25)) {
    digitalWrite(TWENTY, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Twenty Minutes ");
  }
  if ((minute > 24) && (minute < 30)) {
    digitalWrite(TWENTY, HIGH);
    digitalWrite(MFIVE, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Twenty Five Minutes ");
  }
  if ((minute > 29) && (minute < 35)) {
    digitalWrite(HALF, HIGH);
    Serial.println("Half ");
  }
  if ((minute > 34) && (minute < 40)) {
    digitalWrite(TWENTY, HIGH);
    digitalWrite(MFIVE, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Twenty Five Minutes ");
  }
  if ((minute > 39) && (minute < 45)) {
    digitalWrite(TWENTY, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Twenty Minutes ");
  }
  if ((minute > 44) && (minute < 50)) {
    digitalWrite(QUARTER, HIGH);
    Serial.println("Quarter ");
  }
  if ((minute > 49) && (minute < 55)) {
    digitalWrite(MTEN, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Ten Minutes ");
  }
  if (minute > 54) {
    digitalWrite(MFIVE, HIGH);
    digitalWrite(MINUTES, HIGH);
    Serial.println("Five Minutes ");
  }



  if ((minute < 5))
  {
    switch (hour) {
      case 1:
        digitalWrite(ONE, HIGH);
        Serial.println("One ");
        break;
      case 2:
        digitalWrite(TWO, HIGH);
        Serial.println("Two ");
        break;
      case 3:
        digitalWrite(THREE, HIGH);
        Serial.println("Three ");
        break;
      case 4:
        digitalWrite(FOUR, HIGH);
        Serial.println("Four ");
        break;
      case 5:
        digitalWrite(HFIVE, HIGH);
        Serial.println("Five ");
        break;
      case 6:
        digitalWrite(SIX, HIGH);
        Serial.println("Six ");
        break;
      case 7:
        digitalWrite(SEVEN, HIGH);
        Serial.println("Seven ");
        break;
      case 8:
        digitalWrite(EIGHT, HIGH);
        Serial.println("Eight ");
        break;
      case 9:
        digitalWrite(NINE, HIGH);
        Serial.println("Nine ");
        break;
      case 10:
        digitalWrite(HTEN, HIGH);
        Serial.println("Ten ");
        break;
      case 11:
        digitalWrite(ELEVEN, HIGH);
        Serial.println("Eleven ");
        break;
      case 12:
        digitalWrite(TWELVE, HIGH);
        Serial.println("Twelve ");
        break;
    }
    digitalWrite(OCLOCK, HIGH);
    Serial.println("O'Clock");
  }
  else if ((minute < 35) && (minute > 4))
  {
    digitalWrite(PAST, HIGH);
    Serial.println("Past ");
    switch (hour) {
      case 1:
        digitalWrite(ONE, HIGH);
        Serial.println("One ");
        break;
      case 2:
        digitalWrite(TWO, HIGH);
        Serial.println("Two ");
        break;
      case 3:
        digitalWrite(THREE, HIGH);
        Serial.println("Three ");
        break;
      case 4:
        digitalWrite(FOUR, HIGH);
        Serial.println("Four ");
        break;
      case 5:
        digitalWrite(HFIVE, HIGH);
        Serial.println("Five ");
        break;
      case 6:
        digitalWrite(SIX, HIGH);
        Serial.println("Six ");
        break;
      case 7:
        digitalWrite(SEVEN, HIGH);
        Serial.println("Seven ");
        break;
      case 8:
        digitalWrite(EIGHT, HIGH);
        Serial.println("Eight ");
        break;
      case 9:
        digitalWrite(NINE, HIGH);
        Serial.println("Nine ");
        break;
      case 10:
        digitalWrite(HTEN, HIGH);
        Serial.println("Ten ");
        break;
      case 11:
        digitalWrite(ELEVEN, HIGH);
        Serial.println("Eleven ");
        break;
      case 12:
        digitalWrite(TWELVE, HIGH);
        Serial.println("Twelve ");
        break;
    }
  }
  else
  {
    // if we are greater than 34 minutes past the hour then display
    // the next hour, as we will be displaying a 'to' sign
    digitalWrite(TO, HIGH);
    Serial.println("To ");
    switch (hour) {
      case 1:
        digitalWrite(TWO, HIGH);
        Serial.println("Two ");
        break;
      case 2:
        digitalWrite(THREE, HIGH);
        Serial.println("Three ");
        break;
      case 3:
        digitalWrite(FOUR, HIGH);
        Serial.println("Four ");
        break;
      case 4:
        digitalWrite(HFIVE, HIGH);
        Serial.println("Five ");
        break;
      case 5:
        digitalWrite(SIX, HIGH);
        Serial.println("Six ");
        break;
      case 6:
        digitalWrite(SEVEN, HIGH);
        Serial.println("Seven ");
        break;
      case 7:
        digitalWrite(EIGHT, HIGH);
        Serial.println("Eight ");
        break;
      case 8:
        digitalWrite(NINE, HIGH);
        Serial.println("Nine ");
        break;
      case 9:
        digitalWrite(HTEN, HIGH);
        Serial.println("Ten ");
        break;
      case 10:
        digitalWrite(ELEVEN, HIGH);
        Serial.println("Eleven ");
        break;
      case 11:
        digitalWrite(TWELVE, HIGH);
        Serial.println("Twelve ");
        break;
      case 12:
        digitalWrite(ONE, HIGH);
        Serial.println("One ");
        break;
    }
  }



  //WriteLEDs();

}


void incrementtime(void) {
  // increment the time counters keeping care to rollover as required
  second = 0;
  if (++minute >= 60) {
    minute = 0;
    if (++hour == 13) {
      hour = 1;
    }
  }
  // debug outputs
  Serial.println();
  Serial.println(hour);
  Serial.println(",");
  Serial.println(minute);
  Serial.println(",");
  Serial.println(second);

}


void loop(void)
{

  //selftest();

  //Uncomment the following line and comment the next one in order to
  //  enable dimming via a potentiometer connected to pin 0:
  //analogWrite(PWMPin, analogRead(1)/4);
  //analogWrite(PWMPin, 255);

  // heart of the timer - keep looking at the millisecond timer on the Arduino
  // and increment the seconds counter every 1000 ms
  if ( millis() - msTick > 999) {
    msTick = millis();
    second++;
    // Flash the onboard Pin13 Led so we know something is hapening!
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
  }



  //test to see if we need to increment the time counters
  if (second == 60)
  {
    incrementtime();
    displaytime();
  }

  // test to see if a forward button is being held down
  // for time setting
  if ( (digitalRead(MinuteButtonPin) == 1 ) && second != 1)
    // the forward button is down
    // and it has been more than one second since we
    // last looked
  {
    minute = (((minute / 5) * 5) + 5);
    second = 0;
    incrementtime();
    second++;  // Increment the second counter to ensure that the name
    // flash doesnt happen when setting time
    displaytime();
  }

  // test to see if the back button is being held down
  // for time setting
  if ((digitalRead(HourButtonPin) == 1 ) && second != 1)
  {
    /*
      minute=(((minute/5)*5) -5);
      second=0; // decrement the minute counter
      if (minute<0) {
      minute=55;
      if (--hour <0) hour=12;
      }
    */
    minute = (minute / 5) * 5; //round minute down to previous 5 min interval
    if (++hour == 13) {
      hour = 1;
    }
    incrementtime();
    second++;  // Increment the second counter to ensure that the name
    // flash doesnt happen when setting time
    displaytime();
  }

}
