
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LED_PIN 3

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);




int CurrentAnalogInputPin = A1;             // Which pin to measure current Value 
int relay_pin=2;

float current_threshold=30.0;

void setup() {
  pinMode(relay_pin, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);                         /* In order to see value in serial monitor */

  while(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
  
  digitalWrite(relay_pin, LOW);
  display.clearDisplay();
}
     
void loop() 

{
  digitalWrite(LED_PIN, HIGH);
  float current=read_current();

  if (current >= current_threshold){
    digitalWrite(relay_pin, LOW);
  }


  
  digitalWrite(LED_PIN, LOW);
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


