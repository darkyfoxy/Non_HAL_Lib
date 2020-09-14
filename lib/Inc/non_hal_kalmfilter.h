/**
  ******************************************************************************
  * @file       non_hal_kalmfilter.h
  * @brief      Header for non_hal_kalmfilter.c file.
  * 						This file defines functions to filter data with the fast
  *             Kalman filter.
  *
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

#ifndef NON_HAL_KALMFILTER_H_
#define NON_HAL_KALMFILTER_H_

/* Includes ------------------------------------------------------------------*/
#include "non_hal_def.h"

/* Types ---------------------------------------------------------------------*/

/**@defgroupNon_HAL_Kalman_filter_Structure Kalman filter structure
  * @brief Structure for the fast Kalman filter
  * @{
  */

/**
  * @brief Structure with main parameters for the fast Kalman filter
  */
typedef struct
{
	float errmeasure;		         /*!<A predicted error measure*/
	volatile float errestimate;  /*!<A error estimate*/
	float speed;                 /*!<A rate of change of values*/
	volatile float lastestimate; /*!<A previous value*/
	volatile float kalmangain;   /*!<The Kalman Gain*/
}Filter_Kalman_Struct;

/**
  * @}
  */

/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**@defgroup Non_HAL_Kalman_filter Kalman filter
  * @brief A filtering data with the fast Kalman filter
  * @{
  */

NON_HAL_StatusTypeDef Filt_Kalm_Init(Filter_Kalman_Struct *pData, float ErrMeasure, float Speed);
float Filt_Kalm(Filter_Kalman_Struct *pData, float value);

/**
  * @}
  */

#endif /* NON_HAL_KALMFILTER_H_ */
