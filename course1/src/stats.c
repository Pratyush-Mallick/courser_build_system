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
 * @file stats.c 
 * @brief Implementation of the statistics library
 *
 * This contains algorithms to implement the following operations:
 * Maximum, Minimum, Mean, Median, Sorting and Printing on a given data array
 *
 * @author Pratyush Mallick
 * @date 22-02-2021
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE   (40)

void stats(void) {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  unsigned int arr_len = SIZE;
  
  PRINTF("\r\nThe original array:\n\n");
  PRINTF(test, arr_len);
  PRINTF(test, arr_len);
  PRINTF("\r\nThe Sorted array:\n\n");
  PRINTF(test, arr_len);
  
}

/* Statistics and Printing Functions Go Here */

void print_statistics(unsigned char ptr[], unsigned int len)
{
PRINTF("\r\nMax = %d ",find_maximum(ptr,len));
PRINTF("\r\nMinimum = %d ",find_minimum(ptr,len));
PRINTF("\r\nMean = %d ",find_mean(ptr,len));
PRINTF("\r\nMedian = %d ",find_median(ptr,len));
}

void print_array(unsigned char ptr[], unsigned int len)
{
  #ifdef VERBOSE
	for(int i = 0; i < len; i++)
        {
           PRINTF("%3d  ", ptr[i]);
 	   if(((i+1)%8) == 0)
           {
             PRINTF("\n");
           }
	}
  #endif
}

unsigned char find_median(unsigned char ptr[], unsigned int len){
sort_array(ptr,len);
return (ptr[len/2]);
}

unsigned char find_mean(unsigned char ptr[], unsigned int len){
   __uint16_t mean = 0;
   
   for(unsigned int i = 0; i < len; i++) { 
         mean += ptr[i] ;
   }
return (mean/len);

}

unsigned char find_maximum(unsigned char ptr[], unsigned int len){
   unsigned char max = ptr[0];
   
   for(unsigned int i = 1; i < len; i++) {
      if( max < ptr[i] ) 
         max = ptr[i];
   }

return max;
}

unsigned char find_minimum(unsigned char ptr[], unsigned int len){
   unsigned char min = ptr[0];
   
   for(unsigned int i = 1; i < len; i++) {
      if( ptr[i] < min ) 
         min = ptr[i];
   }

return min;
}

void sort_array(unsigned char ptr[], unsigned int len){
unsigned char i,j;

for(i=0;i<len;i++){
for(j=0;j<len-i-1;j++){
if(ptr[j] < ptr[j+1]){
unsigned char temp = ptr[j];
ptr[j] = ptr[j+1];
ptr[j+1] = temp; 

} 
} 
}
}
