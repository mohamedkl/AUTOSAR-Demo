#include <stdint.h>

typedef     uint8_t             Dio_LevelType;
typedef     unsigned int        Dio_ChannelType;

#define     STD_LOW             0x00
#define     STD_HIGH            0x01


#define     AHB_BASE_ADDR       (0x40020000U)
#define     GPIOA_PORT_ADDR     (AHB_BASE_ADDR + 0)
#define     GPIOA_IDR_ADDR      (GPIOA_PORT_ADDR + 0x10U)   
#define     GPIOA_ODR_ADDR      (GPIOA_PORT_ADDR + 0x14U)
#define     GPIOA_IDR           (*(uint32_t*)GPIOA_IDR_ADDR)
#define     GPIOA_ODR           (*(uint32_t*)GPIOA_ODR_ADDR)
#define     GPIO_PIN_0          (1 << 0)
#define     GPIO_PIN_1          (1 << 1)
#define     GPIO_PIN_10         (1 << 10)

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);