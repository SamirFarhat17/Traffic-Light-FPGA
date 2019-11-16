#include <stdio.h>
#include "platform.h"
#include "xil_types.h"
#include "gpio_init.h"
#include "seg7_display.h"

// assign starting colours to regions
u16 colour_0 = 0xF00;
u16 colour_1 = 0xFFF;
u16 colour_2 = 0xFFF;
u16 colour_4 = 0xF00;
u16 colour_6 = 0xF00;
u16 colour_7 = 0xFFF;
u16 colour_8 = 0xFFF;

// Initializes displays for LEDs and 7-Segment Display
u16 traffic_timer = 0;
u16 led_display = 0x2001;

// Initalize variables to detect pedestrian input
u16 pushBtnRightIn = 0;
int pedestrian_check = FALSE;

int main() {
	// Initialize code, GPios and Interrupt system
	init_platform();
	setUpInterruptSystem();
	initGpio();

	while (1)
	{
		// Writing colours to the respective regions
		// TR1
		XGpio_DiscreteWrite(&REGION_0_COLOUR, 1, colour_0);
		XGpio_DiscreteWrite(&REGION_1_COLOUR, 1, colour_1);
		XGpio_DiscreteWrite(&REGION_2_COLOUR, 1, colour_2);

		// PD
		XGpio_DiscreteWrite (&REGION_4_COLOUR, 1, colour_4);

		// TR2
		XGpio_DiscreteWrite(&REGION_6_COLOUR, 1, colour_6);
		XGpio_DiscreteWrite(&REGION_7_COLOUR, 1, colour_7);
		XGpio_DiscreteWrite(&REGION_8_COLOUR, 1, colour_8);

		// Seven Segment Display and LEDs
		displayNumber(traffic_timer);
		XGpio_DiscreteWrite(&LED_OUT, 1, led_display);

		// take input and tell control flow that pedestrian is waiting
		pushBtnRightIn = XGpio_DiscreteRead(&P_BTN_RIGHT, 1);
		if (pushBtnRightIn == 1) pedestrian_check = TRUE;

	}

	// terminate program
    cleanup_platform();
    return 0;
}
