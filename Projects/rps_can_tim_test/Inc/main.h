/*
 * main.h
 *
 *  Created on: 14.12.2016
 *      Author: hantrun
 */

#ifndef MAIN_H_
#define MAIN_H_

void sendMSG(uint32_t, uint32_t, uint8_t);
void rps_interrupt(void);

#endif /* TRANSMITTER_H_ */






/*
 * transmitter.c
 *
 *  Created on: 14.12.2016
 *      Author: hantrun
 *
#include "transmitter.h"
#include "canid.h"
#include "stm32f4xx_hal.h"
extern TIM_TypeDef htim3;
extern uint_fast32_t calculation_intervall;
extern uint8_t interation;
extern uint32_t timerValue;
extern uint32_t tooth_[];
void sendMSG(uint32_t MSG, uint32_t ID, uint8_t DLC) {
	hcan1.pTxMsg->StdId = ID;
	hcan1.pTxMsg->DLC = DLC;
	hcan1.pTxMsg->Data[0] = 123;
	HAL_CAN_Transmit(&hcan1, 1);
}
void rps_interrupt(){
	  timerValue = __HAL_TIM_GetCounter(&htim3);
	      if (interation <= calculation_intervall && interation >= 0){
	          tooth_[interation] = (__HAL_TIM_GetCounter(&htim3) - timerValue);
	          interation++;
	      }else{
	  		//using a loop takes a bit of time, but it allows us to calculate rps with like 100tooth, yeah i know it kinda useless
	  		uint32_t subtotal = 0;
	  		for(int i = 0; i < calculation_intervall; i++){
	  			subtotal = subtotal + tooth_[i];
	  		}
	      uint32_t USec = 1000/((subtotal / calculation_intervall) * 20);
	      interation = 0;
	  	sendMSG(USec, CAN_ID_ECU_N_RPM_R, 1);
	      }
}
*/
