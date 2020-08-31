/**
  ******************************************************************************
  * @file       non_hal_conv.c
  * @brief      This file provides functions to convert numeric types to a
  * 						character string and vice versa.
  *
  *             This file include follow function types:
  *               + From numeric type:
  *             	  + int8_t   -> string with binary symbols (0 or 1)
  *             	  + int32_t  -> string with binary symbols (0 or 1)
  *             	  + uint8_t  -> string with decimal symbols (from 0 to 9)
  *             	  + int8_t   -> string with decimal symbols (from 0 to 9)
  *             	  + uint32_t -> string with decimal symbols (from 0 to 9)
  *             	  + int32_t  -> string with decimal symbols (from 0 to 9)
  *             	  + float    -> string with decimal symbols (from 0 to 9)
  *             	+ From character string
  *             	  + string with binary symbols (0 or 1)        -> int8_t
  *               	+ string with binary symbols (0 or 1)        -> int32_t
  *               	+ string with decimal symbols (from 0 to 9)  -> int8_t
  *               	+ string with decimal symbols (from 0 to 9)  -> uint8_t
  *               	+ string with decimal symbols (from 0 to 9)  -> int32_t
  *               	+ string with decimal symbols (from 0 to 9)  -> uint32_t
  *               	+ string with decimal symbols (from 0 to 9)  -> float
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


/* Includes ------------------------------------------------------------------*/
#include "non_hal_lib.h"

/* Types ---------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**
  * @brief	The function converts an int8_t value to a character string
  * 				with binary symbols (0 or 1)
  * @param  data the int8_t value to convert to the character string
  * @param  bitstr a pointer on the character string buffer
  * @param  sizebuf a size of the character string which must be least 9
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef MY_CON_Int_to_BinString_8bit(int8_t data, uint8_t *bitstr, uint8_t sizebuf)
{
	if(sizebuf > 8)
  {
		bitstr += 8;
		*bitstr-- = 0;
    for(int i=0; i<=8; i++)
    {
    	*bitstr-- = ((data >> i) & 1U) + '0';
    }
		return NON_HAL_OK;
	}
	else
	{
		return NON_HAL_ERROR;
	}
}

/**
  * @brief	The function to convert an int32_t value to a character string
  * 				with binary symbols (0 or 1)
  * @param  data the int32_t value to convert to the a character string
  * @param  bitstr a pointer on the character  string
  * @param  sizebuf a size of the character string which must be least 33
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef MY_CON_Int_to_BinString_32bit(int32_t data, uint8_t *bitstr, uint8_t sizebuf)
{
	if(sizebuf > 32)
  {
		bitstr += 32;
		*bitstr-- = 0;
    for(int i=0; i<=32; i++)
    {
    	*bitstr-- = ((data >> i) & 1U) + '0';
    }
		return NON_HAL_OK;
	}
	else
	{
		return NON_HAL_ERROR;
	}
}

/**
  * @brief	The function to convert an uint8_t value to a character string
  * 				with decimal symbols (from 0 to 9)
  * @param  data the uint8_t value to convert to the character string
  * @param  bitstr a pointer on the character string
  * @param  sizebuf a size of the character string which must be least 4
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef MY_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 3)
	{
		char first_zeroflag = 1;
		for(char i=100; i>0; i/=10)
		{
			*decstr = ((data/i)%10) + '0';
			if(*decstr != 0 + '0' || first_zeroflag == 0)
			{
				decstr++;
				first_zeroflag = 0;
			}
		}
		*decstr = 0;
		return NON_HAL_OK;
	}
	else
	{
		return NON_HAL_ERROR;
	}
}

/**
  * @brief	The function to convert an int8_t value to a character string
  * 				with decimal symbols (from 0 to 9)
  * @param  data the int8_t value to convert to the character string
  * @param  bitstr a pointer on the character string
  * @param  sizebuf a size of the character string which must be least 5
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef MY_CON_Int_to_DecString_8bit(int8_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 4)
	{
		char first_zeroflag = 1;
		if((data & 128U) != 0)
		{
			*decstr++ = '-';
			data = ~data + 1;
		}

		for(char i=100; i>0; i/=10)
		{
			*decstr = ((data/i)%10) + '0';
			if(*decstr != 0 + '0' || first_zeroflag == 0)
			{
				decstr++;
				first_zeroflag = 0;
			}
		}
		*decstr = 0;
		return NON_HAL_OK;
	}
	else
	{
		return NON_HAL_ERROR;
	}
}

/**
  * @brief	The function to convert an uint32_t value to a character string
  * 				with decimal symbols (from 0 to 9)
  * @param  data the uint32_t value to convert to the character string
  * @param  bitstr a pointer on the character string
  * @param  sizebuf a size of the character string which must be least 11
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef MY_CON_Int_to_DecString_32bit(uint32_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 4)
	{
		char first_zeroflag = 1;
		for(int32_t i=1000000000; i>0; i/=10)
		{
			*decstr = ((data/i)%10) + '0';
			if(*decstr != 0 + '0' || first_zeroflag == 0)
			{
				decstr++;
				first_zeroflag = 0;
			}
		}
		*decstr = 0;
		return NON_HAL_OK;
	}
	else
	{
		return NON_HAL_ERROR;
	}
}

