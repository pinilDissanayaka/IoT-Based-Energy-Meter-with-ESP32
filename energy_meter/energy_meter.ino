int decimalPrecision = 2;                   // decimal places for all values shown in LED Display & Serial Monitor
int VoltageAnalogInputPin = A2;             // Which pin to measure voltage Value (Pin A0 is reserved for button function)
float voltageSampleRead  = 0;               /* to read the value of a sample in analog including voltageOffset1 */
float voltageLastSample  = 0;               /* to count time for each sample. Technically 1 milli second 1 sample is taken */
float voltageSampleSum   = 0;               /* accumulation of sample readings */
float voltageSampleCount = 0;               /* to count number of sample. */
float voltageMean ;                         /* to calculate the average value from all samples, in analog values*/ 
float RMSVoltageMean ;                      /* square roof of voltageMean without offset value, in analog value*/
float adjustRMSVoltageMean;
float FinalRMSVoltage;                      /* final voltage value with offset value*/
float voltageOffset1 =0.00 ;          // to Offset deviation and accuracy. Offset any fake current when no current operates. 
float voltageOffset2 = 0.00;          // too offset value due to calculation error from squared and square root 
              


void setup() {
  Serial.begin(9600);                             /* In order to see value in serial monitor */

}
     
void loop() 

{
  float voltage=read_voltage();
  
   
}

float read_voltage(){
  /* 1- AC Voltage Measurement */
  if(micros() >= voltageLastSample + 1000 )                                                                      /* every 0.2 milli second taking 1 reading */
    {
      voltageSampleRead = (analogRead(VoltageAnalogInputPin)- 512)+ voltageOffset1;                             /* read the sample value including offset value*/
      voltageSampleSum = voltageSampleSum + sq(voltageSampleRead) ;                                             /* accumulate total analog values for each sample readings*/
      
      voltageSampleCount = voltageSampleCount + 1;                                                              /* to move on to the next following count */
      voltageLastSample = micros() ;                                                                            /* to reset the time again so that next cycle can start again*/ 
    }

  if(voltageSampleCount == 1000)                                                                                /* after 4000 count or 800 milli seconds (0.8 second), do the calculation and display value*/
    {
      voltageMean = voltageSampleSum/voltageSampleCount;                                                        /* calculate average value of all sample readings taken*/
      RMSVoltageMean = (sqrt(voltageMean))*1.5;                                                                 // The value X 1.5 means the ratio towards the module amplification.      
      adjustRMSVoltageMean = RMSVoltageMean + voltageOffset2;                                                   /* square root of the average value including offset value */                                                                                                                                                       /* square root of the average value*/                                                                                                             
      FinalRMSVoltage = RMSVoltageMean + voltageOffset2;                                                        /* this is the final RMS voltage*/

      if(FinalRMSVoltage <= 2.5){                                                                             /* to eliminate any possible ghost value*/
        FinalRMSVoltage = 0;
      }

      Serial.print(" The Voltage RMS value is: ");
      Serial.print(FinalRMSVoltage,decimalPrecision);
      Serial.println(" V ");
  
      voltageSampleSum =0;                                                                                      /* to reset accumulate sample values for the next cycle */
      voltageSampleCount=0;                                                                                     /* to reset number of sample for the next cycle */

      return FinalRMSVoltage;
    }

}
