/*
 * Copyright: Beijing Jiaotong University, 2018-2022.
 * Filename: led.c
 * Author: Hongchao Wang <hcwang@bjtu.edu.cn>, Yipeng Cun <cunyipeng@bjtu.edu.cn>
 * Date: Jan 5th, 2018
 * Function: the source/header of the project
 */

//=========================== include =========================================
#include "led.h"
//=========================== define ==========================================

//=========================== typedef =========================================

//=========================== variables =======================================

//=========================== prototypes ======================================

//=========================== main ============================================

//=========================== public ==========================================
void led_init()
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  LD5_RCC_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_PIN, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED2_Pin */
  GPIO_InitStruct.Pin = LD5_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD5_GPIO_Port, &GPIO_InitStruct);

  
  /* Turn off LED2*/
  led_off();
}

void led_on()
{
	HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_PIN, GPIO_PIN_SET);
}

void led_off()
{
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_PIN, GPIO_PIN_RESET);
}

void led_toggle()
{
  led_t led_state;
  
  led_state   = HAL_GPIO_ReadPin(LD5_GPIO_Port, LD5_PIN);
  
  if (led_state)
  {
	  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_PIN, GPIO_PIN_RESET);
  }
  else
  {
	  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_PIN, GPIO_PIN_SET);
  }
}


//=========================== private =========================================

//=========================== interrupt handlers ==============================
