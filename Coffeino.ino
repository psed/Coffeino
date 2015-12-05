bool doBrewing;
bool brewDouble;

int pumpRelay = 4;
int heaterRelay = 5;
int makeSingleShotButton = 2;
int makeDoubleShotButton = 3;
int shotSizePotentiometer = 1;

void setup() 
{
  pinMode(pumpRelay, OUTPUT);
  pinMode(heaterRelay, OUTPUT);
  pinMode(makeSingleShotButton, INPUT);
  pinMode(makeDoubleShotButton, INPUT);
  pinMode(shotSizePotentiometer, INPUT);

  attachInterrupt(digitalPinToInterrupt(makeSingleShotButton), makeSingleShot, RISING);
  attachInterrupt(digitalPinToInterrupt(makeDoubleShotButton), makeDoubleShot, RISING);

  doBrewing = false;
  
  Serial.begin(9600);
}

void loop() {
  if (doBrewing)
  {
    brew(brewDouble);
  }
}

void makeSingleShot()
{
  Serial.println("Single shot button pressed...");
  if(!doBrewing)
  {
    brewDouble = false;
    doBrewing = true;
  }
}

void makeDoubleShot()
{
  Serial.println("Double shot button pressed...");
  if(!doBrewing)
  {
    brewDouble = true;
    doBrewing = true;
  }
}

void brew(bool makeDoubleSizeShot)
{
  Serial.print("Making shot");
  int shotSize = analogRead(shotSizePotentiometer) / 10;
  
  if(makeDoubleSizeShot)
  {
    shotSize = shotSize * 2;
  }
  
  Serial.print("Shot size = ");Serial.println(shotSize * 10);
  digitalWrite(pumpRelay, LOW);
  delay(shotSize * 100);
  digitalWrite(pumpRelay, HIGH);
  Serial.println("Brewed!");
  doBrewing = false;
}

