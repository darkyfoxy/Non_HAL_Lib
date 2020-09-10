/**
  ******************************************************************************
  * @file       non_hal_conv.h
  * @brief      Header for non_hal_conv.c file.
  * 						This file defines functions to convert numeric types to a
  * 						character string and vice versa.
  *
  * @author     darkyfoxy [*GitHub*](https://github.com/darkyfoxy)
  * @version    0.01
  * @data       29.08.2020
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

#ifndef NON_HAL_CONV_H_
#define NON_HAL_CONV_H_

/* Includes ------------------------------------------------------------------*/
#include "non_hal_def.h"

/* Types ---------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**@defgroup Non_HAL_Converters_to_string Converters to a string
  * @brief Converters from numeric types to a character string
  * @{
  */

NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_BinString_8bit(int8_t data, uint8_t *bitstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_BinString_32bit(int32_t data, uint8_t *bitstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_DecString_8bit(int8_t data, uint8_t *decstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_UInt_to_DecString_32bit(uint32_t data, uint8_t *decstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_DecString_32bit(int32_t data, uint8_t *decstr, uint8_t sizebuf);
NON_HAL_StatusTypeDef Non_HAL_CON_Float_to_DecString(float data, uint8_t *decstr, uint8_t sizebuf);

/**
  * @}
  */

/**@defgroup Non_HAL_Converters_to_string Converters to a string
  * @brief Converters from numeric types to a character string
  * @{
  */

NON_HAL_StatusTypeDef Non_HAL_CON_BinString_to_Int_8bit(uint8_t *bitstr, int8_t *data_out);
NON_HAL_StatusTypeDef Non_HAL_CON_BinString_to_Int_32bit(uint8_t *bitstr, int32_t *data_out);

/**
  * @}
  */
#endif /* NON_HAL_CONV_H_ */
