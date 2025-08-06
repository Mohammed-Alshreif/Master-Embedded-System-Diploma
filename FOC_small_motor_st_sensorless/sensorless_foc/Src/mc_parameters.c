
/**
  ******************************************************************************
  * @file    mc_parameters.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file provides definitions of HW parameters specific to the
  *          configuration of the subsystem.
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "parameters_conversion.h"

#include "ics_g4xx_pwm_curr_fdbk.h"

/* USER CODE BEGIN Additional include */

/* USER CODE END Additional include */

#define FREQ_RATIO 1                /* Dummy value for single drive */
#define FREQ_RELATION HIGHEST_FREQ  /* Dummy value for single drive */

  const ICS_Params_t ICS_ParamsM1 =
{
/* Dual MC parameters --------------------------------------------------------*/
  .FreqRatio =				FREQ_RATIO,
  .IsHigherFreqTim =		FREQ_RELATION,

/* Current reading A/D Conversions initialization -----------------------------*/
  .ADCx_1 = ADC1,
  .ADCx_2 = ADC2,
  .ADCConfig1 =   (MC_ADC_CHANNEL_1 << ADC_JSQR_JSQ1_Pos) | LL_ADC_INJ_TRIG_EXT_RISING | LL_ADC_INJ_TRIG_EXT_TIM1_TRGO,
  .ADCConfig2 =   (MC_ADC_CHANNEL_2 << ADC_JSQR_JSQ1_Pos) | LL_ADC_INJ_TRIG_EXT_RISING | LL_ADC_INJ_TRIG_EXT_TIM1_TRGO,

/* PWM generation parameters --------------------------------------------------*/
  .RepetitionCounter =	REP_COUNTER,
  .TIMx               =	TIM1,

/* PWM Driving signals initialization ----------------------------------------*/
  .LowSideOutputs =	(LowSideOutputsFunction_t)LOW_SIDE_SIGNALS_ENABLING,
  .pwm_en_u_port      = MC_NULL,
  .pwm_en_u_pin       = (uint16_t) 0,
  .pwm_en_v_port      = MC_NULL,
  .pwm_en_v_pin       = (uint16_t) 0,
  .pwm_en_w_port      = MC_NULL,
  .pwm_en_w_pin       = (uint16_t) 0,

/* Emergengy signal initialization ----------------------------------------*/
  .BKIN2Mode           = NONE,

};

/* USER CODE BEGIN Additional parameters */

/* USER CODE END Additional parameters */

/******************* (C) COPYRIGHT 2019 STMicroelectronics *****END OF FILE****/
