#include "Dio.h"

/* Function API to Read a Channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType readValue;

    // Assume Channel 10 is mapped to GPIOA port Pin 0
    if (ChannelId == 10)
    {
        // Read the mapped IO pin
        readValue = (GPIOA_IDR) & (GPIO_PIN_0);
        
        if (readValue == 0)
        {
            (void)readValue;
            // If pin state is low
            return STD_LOW;
        }

        else
        {
            (void)readValue;
            // If pin state is high
            return STD_HIGH;
        }
    }

    /* Code for other channels shall be continued here */
}

/* Function API to Set/Reset a pin state */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if (ChannelId == 10)
    {
        if (Level == STD_LOW)
        {
            GPIOA_ODR &= ~(GPIO_PIN_0);
        }
        else
        {
            GPIOA_ODR |= (GPIO_PIN_0);
        }
    }

    /* Code for other channels shall be continued here */
}