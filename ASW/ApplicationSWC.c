
/* Generated RTE APIs from the .arxml configurations */
#include "Rte_ApplicationSWC.h"



void App_TemperatureControl()
{
	float temperature;
	
	/* Read the temperature data from the ECU Abstraction layer
	   through RTE */
	Rte_Call_RP_Tmeperature_Temperature(&temperature);
	
	/* Control Logic */
	if ((temperature > 50) && (temperature < 75))
	{
		Rte_Call_RP_StartMotor_StartMotor(25);
	}
	else if (temperature > 75)
	{
		Rte_Call_RP_StartMotor_StartMotor(100);
	}
	else if (temperature < 50)
	{
		Rte_Call_RP_StopMotor_StopMotor();
	}	
}