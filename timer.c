//www.diyusthad.com
#include <LiquidCrystal.h>

// Settings for initializing the lcd display
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Timer functions
int randTime;

// Buzzer and button pins
const int startButtonPin = 8;
const int buzzerPin = 9;

void endTimer() {
  digitalWrite(buzzerPin, HIGH);
  delay(3000);
  lcd.begin(16,2);
  lcd.print("All Done!");
  lcd.setCursor(0,1);
  lcd.print("Wipe and Wash");
}


void startTimer() {
  // Generate a random number of seconds between 3 and 5 minutes
  randTime = random(180,300);
  lcd.begin(16,2);
  lcd.print("Time Remaining:");
  while(randTime > 0) {
    randTime -= 1;
    lcd.print("Time Remaining:");    
    lcd.setCursor(0,1);
    lcd.print(randTime);
    delay(1000);
    lcd.clear();
  }
  if(randTime == 0) {
    endTimer();
  }
}


void setup() {
  lcd.begin(16, 2);
  lcd.print("Flora's Timer");
  lcd.setCursor(0,1);
  lcd.print("Press to Start");
  pinMode(startButtonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  randomSeed(analogRead(0));
}
void loop() {
  byte buttonState = digitalRead(startButtonPin);
  if (buttonState == LOW) {
    startTimer();
  }
  




}

