#ifndef __GPIO_INIT_H_
#define __GPIO_INIT_H_

#include "xgpio.h"		// Added for xgpio object definitions

XStatus initGpio(void);

// Added input and output objects (Screen Region, Colour in Region , 7-Segment Display, LED display and Sliders)

XGpio SEG7_HEX_OUT;
XGpio SEG7_SEL_OUT;
XGpio P_BTN_RIGHT;
XGpio LED_OUT;
XGpio SLIDE_SWITCHES;
XGpio REGION_0_COLOUR;
XGpio REGION_1_COLOUR;
XGpio REGION_2_COLOUR;
XGpio REGION_3_COLOUR;
XGpio REGION_4_COLOUR;
XGpio REGION_5_COLOUR;
XGpio REGION_6_COLOUR;
XGpio REGION_7_COLOUR;
XGpio REGION_8_COLOUR;
XGpio REGION_9_COLOUR;
XGpio REGION_10_COLOUR;
XGpio REGION_11_COLOUR;

#endif
