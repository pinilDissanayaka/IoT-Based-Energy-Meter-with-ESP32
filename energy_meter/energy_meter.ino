
int CurrentAnalogInputPin = A1;             // Which pin to measure current Value 

void setup() {
  Serial.begin(9600);                         /* In order to see value in serial monitor */

}
     
void loop() 

{
  float current=read_current();

   
}



float read_current(){
  unsigned int x=0;
  float current_sensor_reading;
  float sum_of_current_sensor_reading=0.0;
  float avg_of_current_sensor_reading=0.0;
  float current=0.0;

  int num_of_interations=150;

  for (int x = 0; x < num_of_interations; x++){ //Get 150 samples
    current_sensor_reading = analogRead(CurrentAnalogInputPin);     //Read current sensor values   
    sum_of_current_sensor_reading = sum_of_current_sensor_reading + current_sensor_reading;  //Add samples together
    delay (3); // let ADC settle before next sample 3ms
  }

  avg_of_current_sensor_reading=sum_of_current_sensor_reading/num_of_interations; //Taking Average of Samples

  //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
  //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
  //out to be 2.5 which is out offset. If your arduino is working on different voltage than 
  //you must change the offset according to the input voltage)
  //0.066v(66mV) is rise in output voltage when 1A current flows at input
  current = (2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.066;

  Serial.print(current);//Print the read current on Serial monitor
  return current; 
  delay(50);
}


