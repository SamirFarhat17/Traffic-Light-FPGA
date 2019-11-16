#include <stdio.h>
#include "platform.h"
#include "xil_types.h"
#include "gpio_init.h"
#include "fsm_manager.h"

// interrupt manager
void hwTimerISR(void *CallbackRef) {
	// initialize interrupt every 4 ms
	interrupt_complete = FALSE;

	// check if its the pedestrians turn
	if(let_pedestrian) {
		// 6 second timer
		traffic_timer = 6 - (interrupt_counter/250);
		// blink 5 times from 2 second onwards
		if(interrupt_counter < 1000) colour_4 = green;
		if(interrupt_counter == 1000) colour_4 = blank;
		if(interrupt_counter == 1050) colour_4 = green;
		if(interrupt_counter == 1100) colour_4 = blank;
		if(interrupt_counter == 1150) colour_4 = green;
		if(interrupt_counter == 1200) colour_4 = blank;
		if(interrupt_counter == 1250) colour_4 = green;
		if(interrupt_counter == 1300) colour_4 = blank;
		if(interrupt_counter == 1350) colour_4 = green;
		if(interrupt_counter == 1400) colour_4 = blank;
		if(interrupt_counter == 1450) colour_4 = green;
		if(interrupt_counter == 1500) colour_4 = blank;
		// pedestrian crossed, revert back to regular traffic flow
		if (traffic_timer == 0) {
			let_pedestrian = FALSE;
			pedestrian_check = FALSE;
			colour_4 = red;
			interrupt_counter = 0;
			led_display = led_display - 0x0100;
			added = FALSE;
			pedestrian_passed = TRUE;
		}
	}
	// else proceed to 3 second timer for cars
	else traffic_timer = 3 - (interrupt_counter/250);

	// display timer
	displayDigit();

	// 250 interrupts is 1 second
	interrupt_counter++;

	// turn on right-middle LED as soon as pressed
	if(pedestrian_check == 1 && !added) {
		led_display = led_display + 0x0100;
		// avoids LED adding once light transitions
		added = TRUE;
	}

	// regular traffic flow proceeds to next state
	if(interrupt_counter == 750 & !let_pedestrian) {
		updateState();
		interrupt_counter = 0;
	}

	interrupt_complete = TRUE;
}

void updateState() {
	// if pedestrian waiting, a pedestrian hasn't just passed and TR2 has just completed. Allow pedestrian to go
	if(tf2_done && colour_7 != yellow && colour_1 != yellow && colour_0 == red && colour_6 == red && pedestrian_check && !pedestrian_passed) let_pedestrian = TRUE;

	// TR1 flow
	if(tf2_done && !let_pedestrian) {
		light_1 = ((light_1 + 1) % 4);
		trafficLight();
		if(light_1 == 0) {
			tf1_done = TRUE;
			tf2_done = FALSE;
			pedestrian_passed = FALSE;
		}
	}
	// TR2 flow
	else if(tf1_done && !let_pedestrian) {
		light_2 = ((light_2 + 1) % 4);
		trafficLight2();
		if(light_2 == 0) {
			tf1_done = FALSE;
			tf2_done = TRUE;
			pedestrian_passed = FALSE;
		}
	}

	// display LEDs of new state
	trafficLEDs();

}

// TR1 flow
void trafficLight() {
	switch(light_1) {
		case 0:
			colour_0 = red;
			colour_1 = blank;
			colour_2 = blank;
			break;
		case 1:
			colour_0 = red;
			colour_1 = yellow;
			colour_2 = blank;
			break;
		case 2:
			colour_0 = blank;
			colour_1 = blank;
			colour_2 = green;
			break;
		case 3:
			colour_0 = blank;
			colour_1 = yellow;
			colour_2 = blank;
			break;
	}

}

// TR2 flow
void trafficLight2() {
	switch(light_2) {
		case 0:
			colour_6 = red;
			colour_7 = blank;
			colour_8 = blank;
			break;
		case 1:
			colour_6 = red;
			colour_7 = yellow;
			colour_8 = blank;
			break;
		case 2:
			colour_6 = blank;
			colour_7 = blank;
			colour_8 = green;
			break;
		case 3:
			colour_6 = blank;
			colour_7 = yellow;
			colour_8 = blank;
			break;
	}
}

// LEDs flow (if pedestrian waiting simply display same flow but right-middle LED on)
void trafficLEDs() {
	if(light_1 == 0 && light_2 == 0) {
		if(pedestrian_check == 1) led_display = 0x2001 + 0x0100;
		else led_display = 0x2001;
	}

	if(light_1 == 1 && light_2 == 0) {
		if(pedestrian_check == 1) led_display = 0x6001 + 0x0100;
		else led_display = 0x6001;
	}

	if(light_1 == 2 && light_2 == 0) {
		if(pedestrian_check == 1) led_display = 0x8001 + 0x0100;
		else led_display = 0x8001;
	}

	if(light_1 == 3 && light_2 == 0) {
		if(pedestrian_check == 1) led_display = 0x4001 + 0x0100;
		else led_display = 0x4001;
	}

	if(light_1 == 0 && light_2 == 1) {
		if(pedestrian_check == 1) led_display = 0x2003 + 0x0100;
		else led_display = 0x2003;
	}

	if(light_1 == 0 && light_2 == 2) {
		if(pedestrian_check == 1) led_display = 0x2004 + 0x0100;
		else led_display = 0x2004;
	}

	if(light_1 == 0 && light_2 == 3) {
		if(pedestrian_check == 1) led_display = 0x2002 + 0x0100;
		else led_display = 0x2002;
	}
}
