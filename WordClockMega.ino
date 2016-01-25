// Display output pin assignments
int MTEN  = 11;
int HALF  = 12;
int QUARTER = 13;
int TWENTY  = 14;
int MFIVE = 15;
int MINUTES = 16;
int PAST  = 17;

int TO  = 20;
int ONE = 21;
int TWO = 22;
int THREE = 23;
int FOUR  = 24;
int HFIVE = 25;
int SIX = 26;

int SEVEN = 27;
int EIGHT = 28;
int NINE  = 29;
int HTEN  = 30;
int ELEVEN  = 31;
int TWELVE  = 32;
int OCLOCK  = 33;


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
  pinMode(FIVE,OUTPUT);
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
  digitalWrite(FIVE,LOW);
  digitalWrite(SIX,LOW);
  digitalWrite(SEVEN,LOW);
  digitalWrite(EIGHT,LOW);
  digitalWrite(NINE,LOW);
  digitalWrite(HTEN,LOW);
  digitalWrite(ELEVEN,LOW);
  digitalWrite(TWELVE,LOW);
  digitalWrite(OCLOCK,LOW);
  
}

void WriteLEDs(void) {
  // Now we write the actual values to the hardware
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  shiftOut(LEDDataPin, LEDClockPin, MSBFIRST, );
  digitalWrite(LEDStrobePin, HIGH);
  delay(2);
  digitalWrite(LEDStrobePin, LOW);


}

void selftest(void) {
  Serial.println("TEST");

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
  digitalWrite(FIVE,HIGH);
  delay(500);
  digitalWrite(FIVE, LOW);
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

  // now we display the appropriate minute counter
  if ((minute > 4) && (minute < 10)) {
    MFIVE;
    MINUTES;
    Serial.println("Five Minutes ");
  }
  if ((minute > 9) && (minute < 15)) {
    MTEN;
    MINUTES;
    Serial.println("Ten Minutes ");
  }
  if ((minute > 14) && (minute < 20)) {
    QUARTER;
    Serial.println("Quarter ");
  }
  if ((minute > 19) && (minute < 25)) {
    TWENTY;
    MINUTES;
    Serial.println("Twenty Minutes ");
  }
  if ((minute > 24) && (minute < 30)) {
    TWENTY;
    MFIVE;
    MINUTES;
    Serial.println("Twenty Five Minutes ");
  }
  if ((minute > 29) && (minute < 35)) {
    HALF;
    Serial.println("Half ");
  }
  if ((minute > 34) && (minute < 40)) {
    TWENTY;
    MFIVE;
    MINUTES;
    Serial.println("Twenty Five Minutes ");
  }
  if ((minute > 39) && (minute < 45)) {
    TWENTY;
    MINUTES;
    Serial.println("Twenty Minutes ");
  }
  if ((minute > 44) && (minute < 50)) {
    QUARTER;
    Serial.println("Quarter ");
  }
  if ((minute > 49) && (minute < 55)) {
    MTEN;
    MINUTES;
    Serial.println("Ten Minutes ");
  }
  if (minute > 54) {
    MFIVE;
    MINUTES;
    Serial.println("Five Minutes ");
  }



  if ((minute < 5))
  {
    switch (hour) {
      case 1:
        ONE;
        Serial.println("One ");
        break;
      case 2:
        TWO;
        Serial.println("Two ");
        break;
      case 3:
        THREE;
        Serial.println("Three ");
        break;
      case 4:
        FOUR;
        Serial.println("Four ");
        break;
      case 5:
        HFIVE;
        Serial.println("Five ");
        break;
      case 6:
        SIX;
        Serial.println("Six ");
        break;
      case 7:
        SEVEN;
        Serial.println("Seven ");
        break;
      case 8:
        EIGHT;
        Serial.println("Eight ");
        break;
      case 9:
        NINE;
        Serial.println("Nine ");
        break;
      case 10:
        HTEN;
        Serial.println("Ten ");
        break;
      case 11:
        ELEVEN;
        Serial.println("Eleven ");
        break;
      case 12:
        TWELVE;
        Serial.println("Twelve ");
        break;
    }
    OCLOCK;
    Serial.println("O'Clock");
  }
  else if ((minute < 35) && (minute > 4))
  {
    PAST;
    Serial.println("Past ");
    switch (hour) {
      case 1:
        ONE;
        Serial.println("One ");
        break;
      case 2:
        TWO;
        Serial.println("Two ");
        break;
      case 3:
        THREE;
        Serial.println("Three ");
        break;
      case 4:
        FOUR;
        Serial.println("Four ");
        break;
      case 5:
        HFIVE;
        Serial.println("Five ");
        break;
      case 6:
        SIX;
        Serial.println("Six ");
        break;
      case 7:
        SEVEN;
        Serial.println("Seven ");
        break;
      case 8:
        EIGHT;
        Serial.println("Eight ");
        break;
      case 9:
        NINE;
        Serial.println("Nine ");
        break;
      case 10:
        HTEN;
        Serial.println("Ten ");
        break;
      case 11:
        ELEVEN;
        Serial.println("Eleven ");
        break;
      case 12:
        TWELVE;
        Serial.println("Twelve ");
        break;
    }
  }
  else
  {
    // if we are greater than 34 minutes past the hour then display
    // the next hour, as we will be displaying a 'to' sign
    TO;
    Serial.println("To ");
    switch (hour) {
      case 1:
        TWO;
        Serial.println("Two ");
        break;
      case 2:
        THREE;
        Serial.println("Three ");
        break;
      case 3:
        FOUR;
        Serial.println("Four ");
        break;
      case 4:
        HFIVE;
        Serial.println("Five ");
        break;
      case 5:
        SIX;
        Serial.println("Six ");
        break;
      case 6:
        SEVEN;
        Serial.println("Seven ");
        break;
      case 7:
        EIGHT;
        Serial.println("Eight ");
        break;
      case 8:
        NINE;
        Serial.println("Nine ");
        break;
      case 9:
        HTEN;
        Serial.println("Ten ");
        break;
      case 10:
        ELEVEN;
        Serial.println("Eleven ");
        break;
      case 11:
        TWELVE;
        Serial.println("Twelve ");
        break;
      case 12:
        ONE;
        Serial.println("One ");
        break;
    }
  }



  WriteLEDs();

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
  analogWrite(PWMPin, 255);

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
