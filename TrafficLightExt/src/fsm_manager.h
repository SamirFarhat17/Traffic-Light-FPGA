// holds variables for fms_manager.c
#ifndef FSM_MANAGER_H_
#define FSM_MANAGER_H_

// interrupt flow variables
u16 interrupt_counter = 0;
int interrupt_complete = 0;

// traffic light flow variables (TR1 goes first)
int tf1_done = FALSE;
int tf2_done = TRUE;

// taken from main for fsm manager
extern u16 traffic_timer;
extern u16 led_display;

// traffic light colours
u16 red = 0xF00;
u16 yellow = 0xFF0;
u16 green = 0x0F0;
u16 blank = 0xFFF;
u16 light_1 = 0;
u16 light_2 = 0;

// taken from main for fsm manager
extern u16 colour_0;
extern u16 colour_1;
extern u16 colour_2;
extern u16 colour_4;
extern u16 colour_6;
extern u16 colour_7;
extern u16 colour_8;
extern u16 colour_9;
extern u16 colour_10;

// variables for pedestrian waiting and crossing
extern u16 pushBtnRightIn;
extern int pedestrian_check;
int let_pedestrian = FALSE;
int pedestrian_passed = FALSE;

// variable to check LEDs are displaying the right number
int added = FALSE;

// variable to take input from slide switches and manipulate
extern u16 traffic_amount;
int currently_green = FALSE;
u16 tf1_congestion = 0;
u16 tf2_congestion = 0;
u16 traffic_ratio_1 = 0;
u16 traffic_ratio_2 = 0;

#endif
