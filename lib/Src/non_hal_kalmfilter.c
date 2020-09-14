/**
  ******************************************************************************
  * @file       non_hal_kalmfilter.c
  * @brief      This file provides functions to filter data with the fast
  *             Kalman filter.
  *
  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.01
  * @date       13.09.2020
  *
  ******************************************************************************
  * @copyright  <h3>Copyright (c) 2020 Pavlov V.</h3>
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE.
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "non_hal_lib.h"
#include "math.h"

/* Types ---------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**
  * @brief  The function to initial parameters for the fast Kalman filter
  * @param  pData a pointer on a empty Filter_Kalman_Struct structure
  * @param  ErrMeasure a predicted input date standard deviation
  * @param  Speed a rate of change of output values (from 0,001 to 1)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Filt_Kalm_Init(Filter_Kalman_Struct *pData, float ErrMeasure, float Speed)
{
  pData->errmeasure = ErrMeasure;
  pData->errestimate = ErrMeasure;
  pData->speed = Speed;
  pData->lastestimate = 0.0;
  pData->kalmangain = 0.0;
  return NON_HAL_OK;
}

/**
  * @brief  The function to filter data with the fast Kalman filter.
  * @param  pData a pointer on a empty Filter_Kalman_Struct structure
  * @param  value a input value
  * @retval currentestimate a output value past the fast Kalman filtering
  */
float Filt_Kalm(Filter_Kalman_Struct *pData, float value)
{
  volatile float currentestimate;
  pData->kalmangain = pData->errestimate / (pData->errestimate + pData->errmeasure);
  currentestimate = pData->lastestimate + pData->kalmangain * (value - pData->lastestimate);
  pData->errestimate =  (1.0 - pData->kalmangain) * pData->errestimate +\
                        fabs(pData->lastestimate - currentestimate) * pData->speed;
  pData->lastestimate = currentestimate;
  return currentestimate;
}
