#include "gpio_init.h"

XStatus initGpio(void)
{
	XStatus status;

	// Seven Segment Digit (in xparameters.h labelled as 0)
	status = XGpio_Initialize(&SEG7_HEX_OUT, 0);
	if (status != XST_SUCCESS)
		{
			return XST_FAILURE;
		}

	// Seven Segment Display (in xparameters.h labelled as 1)
	status = XGpio_Initialize(&SEG7_SEL_OUT, 1);
	if (status != XST_SUCCESS)
		{
			return XST_FAILURE;
		}

	// Right Button (in xparameters.h labelled as 5)
	status = XGpio_Initialize(&P_BTN_RIGHT, 5);
	if (status != XST_SUCCESS)
		{
			return XST_FAILURE;
		}

	// LEDs (in xparameters.h labelled as 2)
	status = XGpio_Initialize(&LED_OUT, 2);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 0 (in xparameters.h labelled as 7)
	status = XGpio_Initialize(&REGION_0_COLOUR, 7);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 1 (in xparameters.h labelled as 10)
	status = XGpio_Initialize(&REGION_1_COLOUR, 10);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 2 (in xparameters.h labelled as 11)
	status = XGpio_Initialize(&REGION_2_COLOUR, 11);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 3 (in xparameters.h labelled as 12)
	status = XGpio_Initialize(&REGION_3_COLOUR, 12);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 4 (in xparameters.h labelled as 13)
	status = XGpio_Initialize(&REGION_4_COLOUR, 13);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 5 (in xparameters.h labelled as 14)
	status = XGpio_Initialize(&REGION_5_COLOUR, 14);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 6 (in xparameters.h labelled as 15)
	status = XGpio_Initialize(&REGION_6_COLOUR, 15);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 7 (in xparameters.h labelled as 16)
	status = XGpio_Initialize(&REGION_7_COLOUR, 16);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 8 (in xparameters.h labelled as 17)
	status = XGpio_Initialize(&REGION_8_COLOUR, 17);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 9 (in xparameters.h labelled as 18)
	status = XGpio_Initialize(&REGION_9_COLOUR, 18);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 10 (in xparameters.h labelled as 8)
	status = XGpio_Initialize(&REGION_10_COLOUR, 8);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// Region 11 (in xparameters.h labelled as 9)
	status = XGpio_Initialize(&REGION_11_COLOUR, 9);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}
