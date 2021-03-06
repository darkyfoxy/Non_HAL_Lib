/**
  ******************************************************************************
  * @file       non_hal_lib.h
  * @brief      Non HAL main include file.
  *             This is the file of the Non HAL library initialization.
  *
  * @note       This file must be included in the main project (in main.h or
  *             main.c).
  *
  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.02
  * @date       04.08.2020
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef NON_HAL_LIB_H_
#define NON_HAL_LIB_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "non_hal_conv.h"
#include "non_hal_filter.h"

/* Types ---------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/

/**@defgroup Non_HAL_Debug_Tools Non HAL tools for a debuging
  * @brief The group debuging tools
  * @{
  */

/** @brief Enable the data watchpoint and trace unit(DWT) and enables the CYCCNT counter
  */
#define ENABLE_TIC_COUNTER()  do {CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; \
                                  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk; \
                                 }while(0)

#define CLOCK_CYCLE_COUNTER   (DWT->CYCCNT)      /*!< The clock cycle counter in DWT */

/** @brief Clear the CYCCNT register (the clock cycle counter in DWT)
  */
#define CLEAR_TIC_COUNTER()   (CLOCK_CYCLE_COUNTER = 0)



/**
  * @}
  */
/* Functions -----------------------------------------------------------------*/


#endif /* NON_HAL_LIB_H_ */
