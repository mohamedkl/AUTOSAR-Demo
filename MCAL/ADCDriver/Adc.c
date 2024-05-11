#include "Adc.h"


/* Function API to start the ADC conversion */
void Adc_StartGroupConversion(Adc_GroupType Group)
{

    /* Code to start the ADC */

}

/* Function API to read the ADC value */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
    Adc_ValueGroupType readVal;
    if (Group == 1)
    {
        /* Assume someRegister is the register where the converted value is stored */
        readVal = someRegister;
        *DataBufferPtr = readVal;
    }

    /* Code for the rest of the groups shall be written after this */
}