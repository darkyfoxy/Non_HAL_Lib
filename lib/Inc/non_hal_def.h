/**
  ******************************************************************************
  * @file       non_hal_def.h
  * @brief      This file contains Non HAL common defines, enumeration, macros
  * 						and structures definitions.
  *
  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.01
  * @date       29.08.2020
  *
  ******************************************************************************
  * @copyright	<h3>Copyright (c) 2020 Pavlov V.</h3>
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

#ifndef NON_HAL_DEF_H_
#define NON_HAL_DEF_H_

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>

/* Types ---------------------------------------------------------------------*/

/**@defgroup Non_HAL_Common_Def Non HAL common defines
  * @brief The group for Non HAL common defines
  * @{
  */

/**
  * @brief The Non HAL type for a returned status of library functions
  */
typedef enum
{
  NON_HAL_OK     = 0x0U,   /*!< 0x0U*/
  NON_HAL_ERROR  = 0x1U    /*!< 0x1U*/
} NON_HAL_StatusTypeDef;

/**
  * @}
  */

/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/


#endif /* NON_HAL_DEF_H_ */
