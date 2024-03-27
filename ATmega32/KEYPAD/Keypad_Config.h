/***************************************
 * @author : Hossam Emad
 * @date : 
 * @SWC : Keypad
 * @about :
****************************************/

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/*============================================================================================*/
/*   SELECT MICROCONTROLERS PINS   */
/*============================================================================================*/
#define KEYPAD_R0_PIN            PC5_PIN
#define KEYPAD_R1_PIN            PC4_PIN
#define KEYPAD_R2_PIN            PC3_PIN
#define KEYPAD_R3_PIN            PC2_PIN

#define KEYPAD_C0_PIN            PD7_PIN
#define KEYPAD_C1_PIN            PD6_PIN
#define KEYPAD_C2_PIN            PD5_PIN
#define KEYPAD_C3_PIN            PD3_PIN

/*============================================================================================*/
/*   SELECT KEYPAD_DEBOUNCING_TIME IN MILLI SECOND   */
/*============================================================================================*/
#define KEYPAD_DEBOUNCING_TIME   20

/*============================================================================================*/
/*   SELECT KEYPAD MODEL   */
/*
     KEYPAD_MODEL_A :  { '7' , '8' , '9' , '+' }
			           { '4' , '5' , '6' , '-' }
					   { '1' , '2' , '3' , '*' }
					   { 'C' , '0' , '=' , '/' }

     KEYPAD_MODEL_B :  { '7' , '8' , '9' , '+' }
			    	   { '4' , '5' , '6' , '-' }
				  	   { '1' , '2' , '3' , '*' }
				   	   { 'C' , '0' , '=' , '/' }
 */
/*============================================================================================*/
#define KEYPAD_MODEL             KEYPAD_MODEL_A

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
