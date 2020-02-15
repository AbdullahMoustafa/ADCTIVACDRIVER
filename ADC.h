/*
 * ADC.h
 *
 *  Created on: Nov 25, 2019
 *      Author: Abdullah
 */

#ifndef ADC_H_
#define ADC_H_
#include"util.h"
#include"stdtypes.h"

//ADC0 module
#define ADC0_ADCACTSS (*((volatile unsigned long*)0x40038000))
#define ADC0_ADCEMUX (*((volatile unsigned long*)0x40038014))
#define ADC0_ADCSSMUX3 (*((volatile unsigned long*)0x400380A0))
#define ADC0_ADCSSCTL3 (*((volatile unsigned long*)0x400380A4))
#define ADC0_ADCPSSI (*((volatile unsigned long*)0x40038028))
#define ADC0_ADCISC (*((volatile unsigned long*)0x4003800C))
#define ADC0_ADCSSFIFO3 (*((volatile unsigned long*)0x400380A8))
#define ADC0_ADCSSFIFO3 (*((volatile unsigned long*)0x400380A8))
#define ADC0_ADCRIS (*((volatile unsigned long*)0x40038004))


//*******************************************************************************************************************
//ADC1 module
#define ADC1_ADCACTSS (*((volatile unsigned long*)0x40039000))
#define ADC1_ADCEMUX (*((volatile unsigned long*)0x40039014))
#define ADC1_ADCSSMUX3 (*((volatile unsigned long*)0x400390A0))
#define ADC1_ADCSSCTL3 (*((volatile unsigned long*)0x400390A4))
#define ADC1_ADCPSSI (*((volatile unsigned long*)0x40039028))
#define ADC1_ADCISC (*((volatile unsigned long*)0x4003900C))
#define ADC1_ADCSSFIFO3 (*((volatile unsigned long*)0x400390A8))
#define ADC1_ADCRIS (*((volatile unsigned long*)0x40039004))


//*******************************************************************************************************************
#define RCGCGPIO (*((volatile unsigned long*)0x400FE608))
#define RCGCADC (*((volatile unsigned long*)0x400FE638))


#define GPIOAFSEL_A (*((volatile unsigned long*)0x40004420))
#define GPIOAFSEL_B (*((volatile unsigned long*)0x40005420))
#define GPIOAFSEL_C (*((volatile unsigned long*)0x40006420))
#define GPIOAFSEL_D (*((volatile unsigned long*)0x40007420))
#define GPIOAFSEL_E (*((volatile unsigned long*)0x40024420))
#define GPIOAFSEL_F (*((volatile unsigned long*)0x40025420))
//*******************************************************************************************************************
#define GPIOMSEL_A (*((volatile unsigned long*)0x40004528))
#define GPIOMSEL_B (*((volatile unsigned long*)0x40005528))
#define GPIOMSEL_C (*((volatile unsigned long*)0x40006528))
#define GPIOMSEL_D (*((volatile unsigned long*)0x40007528))
#define GPIOMSEL_E (*((volatile unsigned long*)0x40024528))
#define GPIOMSEL_F (*((volatile unsigned long*)0x40025528))
//*******************************************************************************************************************
#define GPIODEN_A (*((volatile unsigned long*)0x4000451C))
#define GPIODEN_B (*((volatile unsigned long*)0x4000551C))
#define GPIODEN_C (*((volatile unsigned long*)0x4000651C))
#define GPIODEN_D (*((volatile unsigned long*)0x4000751C))
#define GPIODEN_E (*((volatile unsigned long*)0x4002451C))
#define GPIODEN_F (*((volatile unsigned long*)0x4002551C))
//*******************************************************************



typedef enum{
    PE3=0,
    PE2,
    PE1,
    PE0,
    PD3,
    PD2,
    PD1,
    PD0,
    PE5,
    PE4,
    PB4,
    PB5

}ADC_PIN_ID;

typedef enum{
    ADC0=0,
    ADC1

}ADC_ID;

void ADC_PinInitialize(ADC_PIN_ID PIN);
void ADC_ModuleInitialize(ADC_ID ADC);
u32 ADC_Get_Data(ADC_PIN_ID PIN);


#endif /* ADC_H_ */
