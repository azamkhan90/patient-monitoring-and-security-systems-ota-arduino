int TempSensPin = 39;

void TempReading() {
int value = analogRead(TempSensPin);
float millivolts = (value/2048.0) * 3300;
temp = millivolts/10;
}
