#include"stdtypes.h"
#include"util.h"
#include"GPIO.h"
#include"ADC.h"

int main(void)
{
    u32 reading =0 ;
    ADC_PinInitialize(PE3);
    ADC_ModuleInitialize(ADC0);

    GPIO_Initialize_Port(PF);
    GPIO_Set_Port_Direction(PF, OUT);

    while(1){
        reading = ADC_Get_Data(PE3);

        if(reading > 0 && reading <= 500){
            GPIO_Write_Pin(PF, PIN1, HIGHV);
            GPIO_Write_Pin(PF, PIN2, LOWV);
            GPIO_Write_Pin(PF, PIN3, LOWV);
        }
        else if(reading > 500 && reading <= 1000){
            GPIO_Write_Pin(PF, PIN1, HIGHV);
            GPIO_Write_Pin(PF, PIN2, LOWV);
            GPIO_Write_Pin(PF, PIN3, LOWV);
        }
        else if(reading > 1000 && reading <= 1500){
            GPIO_Write_Pin(PF, PIN1, LOWV);
            GPIO_Write_Pin(PF, PIN2, HIGHV);
            GPIO_Write_Pin(PF, PIN3, LOWV);
        }
        else if(reading > 1500 && reading <= 2000){
            GPIO_Write_Pin(PF, PIN1, HIGHV);
            GPIO_Write_Pin(PF, PIN2, HIGHV);
            GPIO_Write_Pin(PF, PIN3, LOWV);
        }
        else if(reading > 2000 && reading <= 2500){
            GPIO_Write_Pin(PF, PIN1, LOWV);
            GPIO_Write_Pin(PF, PIN2, LOWV);
            GPIO_Write_Pin(PF, PIN3, HIGHV);
        }
        else if(reading > 2500 && reading <= 3000){
            GPIO_Write_Pin(PF, PIN1, HIGHV);
            GPIO_Write_Pin(PF, PIN2, LOWV);
            GPIO_Write_Pin(PF, PIN3, HIGHV);
        }
        else if(reading > 3000 && reading <= 3500){
            GPIO_Write_Pin(PF, PIN1, LOWV);
            GPIO_Write_Pin(PF, PIN2, HIGHV);
            GPIO_Write_Pin(PF, PIN3, HIGHV);
        }
        else if(reading > 3500){
            GPIO_Write_Pin(PF, PIN1, HIGHV);
            GPIO_Write_Pin(PF, PIN2, HIGHV);
            GPIO_Write_Pin(PF, PIN3, HIGHV);
        }

    }

    return 0 ;
}
