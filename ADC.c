/*
 * ADC.c
 *
 *  Created on: Nov 25, 2019
 *      Author: Abdullah
 */
#include"ADC.h"
#include"util.h"
#include"stdtypes.h"
#include"GPIO.h"

unsigned long delay_ADC0;
unsigned long delay_ADC1;

unsigned long delay_B;
unsigned long delay_D;
unsigned long delay_E;


void ADC_ModuleInitialize(ADC_ID ADC){

    if (ADC<=ADC1){
        switch(ADC){
        case ADC0:
            SET_BIT(RCGCADC,0);           //Enable CLK for ADC1
            CLR_BIT(RCGCADC,1);           //Disable CLK for ADC0
            delay_ADC0 = RCGCADC;
            delay_ADC0 = RCGCADC;
            delay_ADC0 = RCGCADC;

            CLR_BIT(ADC0_ADCACTSS, 3 );   //Disable SS3 during configuration
            CLR_BIT(ADC0_ADCEMUX , 12);   //Software trigger configuration
            CLR_BIT(ADC0_ADCEMUX , 13);
            CLR_BIT(ADC0_ADCEMUX , 14);
            CLR_BIT(ADC0_ADCEMUX , 15);
            SET_BIT(ADC0_ADCSSCTL3,1);     //Take one sample at a time and set flag for 1st sample
            SET_BIT(ADC0_ADCSSCTL3,2);
            CLR_BIT(ADC0_ADCSSCTL3,0);
            CLR_BIT(ADC0_ADCSSCTL3,4);
            SET_BIT(ADC0_ADCACTSS, 3 );   //Enable SS3 after configuration
            break;
        case ADC1:
            SET_BIT(RCGCADC,1);           //Enable CLK for ADC1
            CLR_BIT(RCGCADC,0);           //Disable CLK for ADC0
            delay_ADC1 = RCGCADC;
            delay_ADC1 = RCGCADC;
            delay_ADC1 = RCGCADC;

            CLR_BIT(ADC1_ADCACTSS, 3 );   //Disable SS3 during configuration

            CLR_BIT(ADC1_ADCEMUX , 12);   //Software trigger configuration
            CLR_BIT(ADC1_ADCEMUX , 13);
            CLR_BIT(ADC1_ADCEMUX , 14);
            CLR_BIT(ADC1_ADCEMUX , 15);
            SET_BIT(ADC1_ADCSSCTL3,1);     //Take one sample at a time and set flag for 1st sample
            SET_BIT(ADC1_ADCSSCTL3,2);
            CLR_BIT(ADC1_ADCSSCTL3,0);
            CLR_BIT(ADC1_ADCSSCTL3,4);
            SET_BIT(ADC1_ADCACTSS, 3 );   //Enable SS3 after configuration
            break;
        }
    }
}
void ADC_PinInitialize(ADC_PIN_ID PIN){
    if (PIN <= PB5){
        switch(PIN){
        case PE3:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,3);     //Enable Alternate function for PE3
            CLR_BIT(GPIODEN_E,3);       //Disable Digital function for PE3
            SET_BIT(GPIOMSEL_E,3);      //Enable Analog PE3
            break;
        case PE2:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,2);     //Enable Alternate function for PEX
            CLR_BIT(GPIODEN_E,2);       //Disable Digital function for PEX
            SET_BIT(GPIOMSEL_E,2);      //Enable Analog PEX
            break;
        case PE1:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,1);     //Enable Alternate function for PEX
            CLR_BIT(GPIODEN_E,1);       //Disable Digital function for PEX
            SET_BIT(GPIOMSEL_E,1);      //Enable Analog PEX
            break;
        case PE0:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,0);     //Enable Alternate function for PEX
            CLR_BIT(GPIODEN_E,0);       //Disable Digital function for PEX
            SET_BIT(GPIOMSEL_E,0);      //Enable Analog PEX
            break;
        case PD3:
            SET_BIT(RCGCGPIO,3);        //Enable CLK for GPIO (PD)
            delay_D = RCGCGPIO;
            SET_BIT(GPIOAFSEL_D,3);     //Enable Alternate function for PDX
            CLR_BIT(GPIODEN_D,3);       //Disable Digital function for PDX
            SET_BIT(GPIOMSEL_D,3);      //Enable Analog PDX
            break;

        case PD2:
            SET_BIT(RCGCGPIO,3);        //Enable CLK for GPIO (PD)
            delay_D = RCGCGPIO;
            SET_BIT(GPIOAFSEL_D,2);     //Enable Alternate function for PDX
            CLR_BIT(GPIODEN_D,2);       //Disable Digital function for PDX
            SET_BIT(GPIOMSEL_D,2);      //Enable Analog PDX
            break;

        case PD1:
            SET_BIT(RCGCGPIO,3);        //Enable CLK for GPIO (PD)
            delay_D = RCGCGPIO;
            SET_BIT(GPIOAFSEL_D,1);     //Enable Alternate function for PDX
            CLR_BIT(GPIODEN_D,1);       //Disable Digital function for PDX
            SET_BIT(GPIOMSEL_D,1);      //Enable Analog PDX
            break;
        case PD0:
            SET_BIT(RCGCGPIO,3);        //Enable CLK for GPIO (PD)
            delay_D = RCGCGPIO;
            SET_BIT(GPIOAFSEL_D,0);     //Enable Alternate function for PDX
            CLR_BIT(GPIODEN_D,0);       //Disable Digital function for PDX
            SET_BIT(GPIOMSEL_D,0);      //Enable Analog PDX
            break;
        case PE5:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,5);     //Enable Alternate function for PEX
            CLR_BIT(GPIODEN_E,5);       //Disable Digital function for PEX
            SET_BIT(GPIOMSEL_E,5);      //Enable Analog PEX
            break;
        case PE4:
            SET_BIT(RCGCGPIO,4);        //Enable CLK for GPIO (PE)
            delay_E = RCGCGPIO;
            SET_BIT(GPIOAFSEL_E,4);     //Enable Alternate function for PEX
            CLR_BIT(GPIODEN_E,4);       //Disable Digital function for PEX
            SET_BIT(GPIOMSEL_E,4);      //Enable Analog PEX
            break;
        case PB4:
            SET_BIT(RCGCGPIO,2);        //Enable CLK for GPIO (PB)
            delay_B = RCGCGPIO;
            SET_BIT(GPIOAFSEL_B,4);     //Enable Alternate function for PBX
            CLR_BIT(GPIODEN_B,4);       //Disable Digital function for PBX
            SET_BIT(GPIOMSEL_B,4);      //Enable Analog PBX
            break;
        case PB5:
            SET_BIT(RCGCGPIO,2);        //Enable CLK for GPIO (PB)
            delay_B = RCGCGPIO;
            SET_BIT(GPIOAFSEL_B,5);     //Enable Alternate function for PBX
            CLR_BIT(GPIODEN_B,5);       //Disable Digital function for PBX
            SET_BIT(GPIOMSEL_B,5);      //Enable Analog PBX
            break;

        }
    }
}


u32 ADC_Get_Data(ADC_PIN_ID PIN){

    volatile u32 result;

    SET_BIT(ADC0_ADCPSSI,3);    //Start conversion
    ADC0_ADCSSMUX3 &= 0xFFF0;
    ADC0_ADCSSMUX3 = PIN;      //Get data from Channel
    while(GET_BIT(ADC0_ADCRIS,3) == 0);
    result = ADC0_ADCSSFIFO3;
    SET_BIT(ADC0_ADCISC,3);      //Reset flag
    return result;
}





