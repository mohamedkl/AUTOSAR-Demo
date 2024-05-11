
/* Include RTE application header */
/* Generated from the RTE Generator with the .arxml configuration
   file of the SWC as input */
#include "Rte_TempHBridgeSWC.h"

void Function_ReadTemperature(void)
{
	Adc_ValueGroupType AdcResult;
	float pinVoltage, temperature;
	/* Start the ADC conversion and read the results */
	// Assume channel 1 is the ADC channel
	Adc_StartGroupConversion(1);
	
	/* Read back the value from the ADC through MCAL API */
	Adc_ReadGroup(1, &AdcResult);
	
	/* Assuming it's a 10 bit ADC with a voltage reference 2.5V */
	/* Convert ADC raw value to voltage */
	pinVoltage = (2.5/1024) * AdcResult;
	
	/* Convert the voltage to temperature */
	/* Note: this should be done by a SensorActuatorSWC
	in the ASW Layer */
	temperature = pinVoltage * 100;
	
	/* Write the temperature result to the RTE layer */
	
	/* Std_ReturnType
	Rte_[Byps_]Write_<p>_<o>([IN Rte_Instance <instance>],
	IN <data>,
	[OUT Rte_TransformerError transformerError]) */
	
	// This communicates the temperature information to
	// the upper layers through RTE
	Rte_Write_PP_Temperature_Temperature(Temperature);
}

/* Start Motor Runnable */
void Function_StartMotor(uint8_t FanSpeed)
{
	/* Assume that writing (10) to the IO pinS triggers the cooling
	   fan with half speed, and (11) triggers it to full speed */
	
	if (FanSpeed < 50)

	{
		/* Trigger cooling fan with half speed */
		Dio_WriteChannel(10, STD_HIGH);
		Dio_WriteChannel(11, STD_LOW);
	}
	else
	{
		/* Trigger cooling fan with half speed */
		Dio_WriteChannel(10, STD_HIGH);
		Dio_WriteChannel(11, STD_HIGH);
	}
}

/* Stop Motor Runnable */
void Function_StopMotor(uint8_t FanSpeed)
{
		/* H-Bridge pins settings (00) */
		Dio_WriteChannel(10, STD_LOW);
		Dio_WriteChannel(11, STD_LOW);
}