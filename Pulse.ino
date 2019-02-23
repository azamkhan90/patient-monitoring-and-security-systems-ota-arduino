    int PulseSensorPurplePin = 34;
    int UpperThreshold = 518;
    int LowerThreshold = 490;
    bool IgnoreReading = false;
    bool FirstPulseDetected = false;
    unsigned long FirstPulseTime = 0;
    unsigned long SecondPulseTime = 0;
    int i;
 
void pulsesense(){

      for(i=0; i<100; i++){
      reading = map(analogRead(PulseSensorPurplePin), 0, 4095, 0, 1023);
      
      // Heart beat leading edge detected.
      if(reading > UpperThreshold && IgnoreReading == false){
        if(FirstPulseDetected == false){
          FirstPulseTime = millis();
          FirstPulseDetected = true;
        }
        else{
          SecondPulseTime = millis();
          PulseInterval = SecondPulseTime - FirstPulseTime;
          FirstPulseTime = SecondPulseTime;
        }
        IgnoreReading = true;
      }

      // Heart beat trailing edge detected.
      if(reading < LowerThreshold){
        IgnoreReading = false;
      }  
      }
      BPM = (1.0/PulseInterval) * 60.0 * 1000;
     
}   
