#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int shotSize = 30;
int pumpRelay = 22;
int heaterRelay = 24;

void setup() {
  pinMode(pumpRelay, OUTPUT);
  digitalWrite(pumpRelay, HIGH);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("    SHOT SIZE");
}

void loop() {
  readKeys();
  String shotSizeString = String(shotSize);
  int shotSizeStringSize = shotSizeString.length();
  int cursorPosition = (9 - shotSizeStringSize);
  lcd.setCursor(cursorPosition,1);
  lcd.print(shotSize);
}

void readKeys() {
    int x;
    x = analogRead(0);
    if (x < 60) {
    }
    else if (x < 200) {
      
      if (shotSize < 200) 
      {
        shotSize = shotSize + 10;
        delay(100);
        clearLine(1);
      }
      else
      {
        shotSize = 200;        
      }
    }
    else if (x < 400){
      if (shotSize > 20) 
      {
        shotSize = shotSize - 10;
        delay(100);
        clearLine(1);
      }
      else
      {
        shotSize = 20;
      }
    }
    else if (x < 600){
      lcd.print ("Left  ");
    }
    else if (x < 800){
      brew();
    }
}

void brew()
{
  clearScreen();
  lcd.setCursor(0,0);
  lcd.print ("    BREWING...");
  digitalWrite(pumpRelay, LOW);
  delay(shotSize * 50);
  digitalWrite(pumpRelay, HIGH);
  clearLine(0);
  lcd.setCursor(0,0);
  lcd.print("    SHOT SIZE");
}

void clearScreen() 
{
  clearLine(0);
  clearLine(1);
}

void clearLine(int lineNumber)
{
  lcd.setCursor(0, lineNumber);
  lcd.print("                ");
}
