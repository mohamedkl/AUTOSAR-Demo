#include <stdint.h>


typedef      unsigned int      Adc_GroupType;
typedef      unsigned int      Adc_ValueGroupType;
typedef      uint8_t           Std_ReturnType;

void Adc_StartGroupConversion(Adc_GroupType Group);
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);
