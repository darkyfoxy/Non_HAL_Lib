/**
  ******************************************************************************
  * @file       non_hal_conv.c
  * @brief      This file provides functions to convert numeric types to a
  * 						character string and vice versa.
  *
  *             This file include follow function types:
  *               - From numeric type:
  *             		+ int8_t   -> string with binary symbols (0 or 1)
  *             		+ int32_t  -> string with binary symbols (0 or 1)
  *             		+ uint8_t  -> string with decimal symbols (from 0 to 9)
  *             		+ int8_t   -> string with decimal symbols (from 0 to 9)
  *             		+ uint32_t -> string with decimal symbols (from 0 to 9)
  *             		+ int32_t  -> string with decimal symbols (from 0 to 9)
  *             		+ float    -> string with decimal symbols (from 0 to 9)
  *             	.
  *             	- From character string:
  *             		+ string with binary symbols (0 or 1)        -> int8_t
  *             		+ string with binary symbols (0 or 1)        -> int32_t
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
#include <string.h>
#include <stdlib.h>

/* Types ---------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/

/**@addtogroup Non_HAL_Converters_to_string
 * @{
 */

const uint32_t float_const_table[] =
{
  0xF0BDC21A,
  0x3DA137D5,
  0x9DC5ADA8,
  0x2863C1F5,
  0x6765C793,
  0x1A784379,
  0x43C33C19,
  0xAD78EBC5,
  0x2C68AF0B,
  0x71AFD498,
  0x1D1A94A2,
  0x4A817C80,
  0xBEBC2000,
  0x30D40000,
  0x7D000000,
  0x20000000,
  0x51EB851E,
  0xD1B71758,
  0x35AFE535,
  0x89705F41,
  0x232F3302,
  0x5A126E1A,
  0xE69594BE,
  0x3B07929F,
  0x971DA050,
  0x26AF8533,
  0x63090312,
  0xFD87B5F2,
  0x40E75996,
  0xA6274BBD,
  0x2A890926,
  0x6CE3EE76
}; /*!< The array of values for converting a float value to a character string */
/**
  * @}
  */

/* Macros --------------------------------------------------------------------*/
/* Functions -----------------------------------------------------------------*/

/**
  * @brief	The function converts an int8_t value to a character string
  * 				with binary symbols (0 or 1)
  * @param  data an int8_t value to convert to a character string
  * @param  bitstr a pointer on a character string buffer
  * @param  sizebuf a size of a character string which must be least 9 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_BinString_8bit(int8_t data, uint8_t *bitstr, uint8_t sizebuf)
{
	if(sizebuf > 8)
  {
		bitstr += 8;
		*bitstr-- = 0;
    for(int i=0; i<8; i++)
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
  * @param  data an int32_t value to convert to a character string
  * @param  bitstr a pointer on a character  string
  * @param  sizebuf a size of character string which must be least 33 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_BinString_32bit(int32_t data, uint8_t *bitstr, uint8_t sizebuf)
{
	if(sizebuf > 32)
  {
		bitstr += 32;
		*bitstr-- = 0;
    for(int i=0; i<32; i++)
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
  * @param  data an uint8_t value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 4 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_UInt_to_DecString_8bit(uint8_t data, uint8_t *decstr, uint8_t sizebuf)
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
  * @param  data an int8_t value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 5 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_DecString_8bit(int8_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 4)
	{
		char first_zeroflag = 1;
		if((data & (1U << 7)) != 0)
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
  * @param  data an uint32_t value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 11 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_UInt_to_DecString_32bit(uint32_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 10)
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

/**
  * @brief	The function to convert an int32_t value to a character string
  * 				with decimal symbols (from 0 to 9)
  * @param  data an int32_t value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 12 (+1 for \0)
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_Int_to_DecString_32bit(int32_t data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf > 11)
	{
		char first_zeroflag = 1;
		if((data & (1U << 31)) != 0)
		{
		  *decstr++ = '-';
		  data = ~data + 1;
		}
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

/**
  * @brief	The function to convert a float value to a character string
  * 				with decimal symbols (from 0 to 9)
  * @note 	example: `3.40282346639e+38; 3.40282346639; 9.32998362376`.
  * @warning The function dosen't support subnormal numbers (subnormal number = 0)
  * @note		The function supports 0, nan, +inf, -inf also.
  * @note		The function faster then sptrinf() about 5-10 time.
  * @param  data a float value to convert to a character string
  * @param  bitstr a pointer on a character string
  * @param  sizebuf a size of a character string which must be least 14
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_Float_to_DecString(float data, uint8_t *decstr, uint8_t sizebuf)
{
	if(sizebuf < 14)
	{
		return NON_HAL_ERROR;
	}
	uint8_t precision = 8;
  uint8_t buffer[12];
  uint8_t *pbuffer = buffer;
  uint32_t value = *(uint32_t *)(&data);
  uint8_t exponent = (uint8_t)(value >> 23);
  uint32_t fraction = (value & 0x00ffffff) | 0x00800000;

	if(value & 0x80000000)
	{
	  *pbuffer++ = '-';
	}
	else
	{
	  *pbuffer++ = '+';
	}
	// check 0, nan, +inf, -inf (subnormal number = 0).
	if(exponent == 0 || exponent == 0xff)
	{
		if(exponent == 0)
		{
			decstr[0] = '0';
			decstr[1] = 0;
		}
		else
		{
		  if(fraction & 0x007fffff)
		  {
		  	decstr[0] = 'n';
		  	decstr[1] = 'a';
		  	decstr[2] = 'n';
		  	decstr[3] = 0;
		  }
		  else
			{
		  	decstr[0] = buffer[0];
		  	decstr[1] = 'i';
		  	decstr[2] = 'n';
		  	decstr[3] = 'f';
		  	decstr[4] = 0;
		  }
		}
		return NON_HAL_OK;
	}
	//if date isn't 0, nan, +inf, -inf.
	*pbuffer++ = '0'; //a free place for rounding

	int8_t intDigits=0, leadingZeros = 0;
	uint8_t *str_begin = &buffer[2];
	int32_t exp10 = ((((exponent>>3))*77+63)>>5) - 38;
  uint32_t temp_value = (((uint64_t)(fraction << 8) * float_const_table[exponent / 8]) >> 32) + 1;
  temp_value >>= 7 - (exponent & 7);
  uint8_t digit = temp_value >> 24;
	digit >>= 4;
	//removing leading zeros
  while(digit == 0)
  {
  	temp_value &= 0x0fffffff;
  	temp_value *= 10;
    digit = (uint8_t)(temp_value >> 28);
    exp10--;
  }
  //extracting digits
  for(uint8_t i = precision+1; i > 0; i--)
  {
		digit = (uint8_t)(temp_value >> 28);
    *pbuffer++ = digit + '0';
    temp_value &= 0x0fffffff;
    temp_value *= 10;
  }
  // rounding
	if(buffer[precision+2] >= '5')
	{
    buffer[precision+1]++;
	}
	pbuffer[-1] = 0;
	pbuffer-=2;
	for(uint8_t i = precision + 1; i > 1; i--)
	{
		if(buffer[i] > '9')
		{
		  buffer[i]-=10;
			buffer[i-1]++;
		}
	}
	//removing trailing zeros
	while(pbuffer[0] == '0')
	{
	  *pbuffer-- = 0;
	}
	//formatting return string
	if(buffer[1] != '0')
  {
    exp10++;
    str_begin--;
  }
  uint8_t digits = strlen((char *)str_begin);

	if(abs(exp10) >= precision)
	{
		intDigits = 1;
	}
	else if(exp10 >= 0)
	{
    intDigits = exp10+1;
    exp10 = 0;
	}
	else
	{
		intDigits = 0;
		leadingZeros = -exp10 - 1;
		exp10 = 0;
	}
	uint8_t fractDigits = digits > intDigits ? digits - intDigits : 0;
	if(intDigits)
	{
	  uint8_t count = intDigits > digits ? digits : intDigits;
		while(count--)
		{
			*decstr++ = *str_begin++;
		}
		int8_t tralingZeros = intDigits - digits;
    while(tralingZeros-- > 0)
    {
      *decstr++ ='0';
    }
	}
	else
	{
		*decstr++ = '0';
	}
	if(fractDigits)
	{
		*decstr++ = '.';
    while(leadingZeros--)
    {
      *decstr++ = '0';
    }
    while(fractDigits--)
    {
			*decstr++ = *str_begin++;
    }
	}
	if(exp10 != 0)
	{
		*decstr++ = 'e';
		uint8_t upow10;
		if(exp10 < 0)
		{
			*decstr++ = '-';
			upow10 = -exp10;
		}
		else
		{
			*decstr++ = '+';
			upow10 = exp10;
		}
		Non_HAL_CON_UInt_to_DecString_8bit(upow10, decstr, sizeof(buffer));
		return NON_HAL_OK;
	}
	*decstr = 0;
	return NON_HAL_OK;
}

/**
  * @brief	The function to convert character string with binary symbols (0 or 1) to
  * 				an int8_t value
  * @note		If the function get a string with non-binary symbols (0 or 1),
  * 				it return a NON_HAL_ERROR status
  * @param  bitstr a pointer on a character string
  * @param  data_out a pointer on an int8_t output value
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_BinString_to_Int_8bit(uint8_t *bitstr, int8_t *data_out)
{
	volatile int8_t data = 0;
	for(;*bitstr != 0; bitstr++)
	{
		if(*bitstr != '0' && *bitstr != '1')
		{
			return NON_HAL_ERROR;
		}
		if(*bitstr == '1')
		{
			data <<= 1;
			data = data | 1U;
		}
		else
		{
			data <<= 1;
		}
	}
	*data_out = data;
	return NON_HAL_OK;
}

/**
  * @brief	The function to convert character string with binary symbols (0 or 1) to
  * 				an int32_t value
  * @note		If the function get a string with non-binary symbols (0 or 1),
  * 				it return a NON_HAL_ERROR status
  * @param  bitstr a pointer on a character string
  * @param  data_out a pointer on an int32_t output value
  * @retval NON_HAL_StatusTypeDef
  */
NON_HAL_StatusTypeDef Non_HAL_CON_BinString_to_Int_32bit(uint8_t *bitstr, int32_t *data_out)
{
	volatile int32_t data = 0;
	for(;*bitstr != 0; bitstr++)
	{
		if(*bitstr != '0' && *bitstr != '1')
		{
			return NON_HAL_ERROR;
		}
		if(*bitstr == '1')
		{
			data <<= 1;
			data = data | 1U;
		}
		else
		{
			data <<= 1;
		}
	}
	*data_out = data;
	return NON_HAL_OK;
}

