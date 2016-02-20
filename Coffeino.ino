int pumpRelay = 4;
int heaterRelay = 2;
int thermalResistor = 7;
int brewButton = 3;

void setup() 
{
  pinMode(pumpRelay, OUTPUT);
  pinMode(heaterRelay, OUTPUT);
  pinMode(thermalResistor, INPUT);
  
  digitalWrite(pumpRelay, HIGH);
  digitalWrite(heaterRelay, HIGH);

  attachInterrupt(1, brew, HIGH);
    
  Serial.begin(9600);
}

void loop() 
{
  int temp = analogRead(thermalResistor);
}

void brew()
{
  Serial.println("BREWING");
  digitalWrite(pumpRelay, LOW);
  delay(100);
  digitalWrite(pumpRelay, HIGH);
}

void warmUp()
{
  Serial.println("Warming up...");
  int temp = analogRead(thermalResistor);
  do
  {
    digitalWrite(heaterRelay, LOW);
    delay(1000);
    temp = analogRead(thermalResistor) / 10;
    Serial.print("temp = ");Serial.println(temp * 10);
  }
  while(temp * 10 < 1000);
  Serial.println("Done warming up");
  digitalWrite(heaterRelay, HIGH);
}


