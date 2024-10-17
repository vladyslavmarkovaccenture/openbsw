// Copyright 2024 Accenture.

#ifndef GUARD_E0DBD384_81F9_4401_A99B_902E13DD49E8
#define GUARD_E0DBD384_81F9_4401_A99B_902E13DD49E8

#include "mcu/mcu.h"
#include "platform/estdint.h"

enum IOPort
{
    _PORTA_     = 0,
    _PORTB_     = 1,
    _PORTC_     = 2,
    _PORTD_     = 3,
    _PORTE_     = 4,
    _PORTS_MAX_ = 5,
    PA0         = 0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,
    PA8,
    PA9,
    PA10,
    PA11,
    PA12,
    PA13,
    PA14,
    PA15,
    PA16,
    PA17,
    PA25 = 25,
    PA26,
    PA27,
    PA28,
    PA29,
    PA30,
    PA31,
    PB0 = 0,
    PB1,
    PB2,
    PB3,
    PB4,
    PB5,
    PB6,
    PB7,
    PB8,
    PB9,
    PB10,
    PB11,
    PB12,
    PB13,
    PB14,
    PB15,
    PB16,
    PB17,
    PB18,
    PB20 = 20,
    PB21,
    PB22,
    PB23,
    PB25 = 25,
    PB27 = 27,
    PB28,
    PB29,
    PC0 = 0,
    PC1,
    PC2,
    PC3,
    PC4,
    PC5,
    PC6,
    PC7,
    PC8,
    PC9,
    PC10,
    PC11,
    PC12,
    PC13,
    PC14,
    PC15,
    PC16,
    PC17,
    PC19 = 19,
    PC23 = 23,
    PC27 = 27,
    PC28,
    PC29,
    PC30,
    PC31,
    PD0 = 0,
    PD1,
    PD2,
    PD3,
    PD4,
    PD5,
    PD6,
    PD7,
    PD8,
    PD9,
    PD10,
    PD11,
    PD12,
    PD13,
    PD14,
    PD15,
    PD16,
    PD17,
    PD18,
    PD19,
    PD22 = 22,
    PD23,
    PD24,
    PD27 = 27,
    PD28,
    PD29,
    PD30,
    PE0 = 0,
    PE1,
    PE2,
    PE3,
    PE4,
    PE5,
    PE6,
    PE7,
    PE8,
    PE9,
    PE10,
    PE11,
    PE12,
    PE13,
    PE14,
    PE15,
    PE16,
    PE19 = 19,
    PE20,
    PE21,
    PE22,
    PE23,
    PE24,
    PE25,
    NUM_PORTS = 0xff //, PORT_UNAVAILABLE = NUM_PORTS
};

#endif /* GUARD_E0DBD384_81F9_4401_A99B_902E13DD49E8 */