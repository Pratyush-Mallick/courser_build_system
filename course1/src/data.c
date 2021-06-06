/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stdbool.h>
#include "platform.h"
#include "memory.h"
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{

  int i = 0;
  bool is_negative = false;
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (data == 0)
    {
        *(ptr + i++) = '0';
        *(ptr + i) = '\0';
        return 1;
    }
  
    if (data < 0 && base == 10)
    {
        is_negative = true;
        data = -1 * data;
    }

    while (data != 0) {
        int rem = data % base;
        *(ptr + i++) = (rem > 9)? (rem-10) + 'A' : rem + '0';
        data = data/base;
    }
 
    if (is_negative == true) {
        *(ptr + i++) = '-';
    }

    // reverse the string and return it
    my_reverse(ptr,i);

    *(ptr + i++) = '\0'; // null terminate string
  
    return i-1;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t num = 0;
    int8_t i = 0,sign = 1;
 
    // note sign of the number
    if (*ptr == '-') 
    {
      sign = -1;
      ptr++;
    }
        
    // run till the end of the string is reached, or the
    // current character is non-numeric
    while (i < digits)
    {
        num = num * 10 + (*(ptr + i) - '0');
        i++;
    }
 
    return sign * num;
}
