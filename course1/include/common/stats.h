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
 * @file stats.h 
 * @brief Statistics library header
 *
 * This file contains all the function declarations for performing  maximum, 
 * minimum, mean, median, sorting and printing operation on a input array of  
 * unsigned char data items 
 *
 * @author Pratyush Mallick
 * @date 22-02-2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints statistics to the console 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, prints out the the maximum, minimum, mean, 
 * and median of the input data array to the console. 
 *
 * @param prt Unsigned character pointer to the array to be analysed
 * @param len Length of the data array
 *
 * @return None
 */

void print_statistics(unsigned char ptr[], unsigned int len);

/**
 * @brief Prints input array to the console 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, prints out the data array to the console. 
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data array
 *
 * @return None
 */

void print_array(unsigned char ptr[], unsigned int len);

/**
 * @brief Performs median operation on a input data array 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, perform median operation and returns the 
 * result.
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data array
 *
 * @return Median value of the data array
 */

unsigned char find_median(unsigned char ptr[], unsigned int len);

/**
 * @brief Performs the mean operation on a input data array 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, perform mean operation and returns the 
 * result. 
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data array
 *
 * @return Mean value of the data array
 */

unsigned char find_mean(unsigned char ptr[], unsigned int len);

/**
 * @brief Finds out the maximum element in a input data array 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, finds the element having the maximum value 
 * and returns it. 
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data array
 *
 * @return Maximum value in the data array
 */

unsigned char find_maximum(unsigned char ptr[], unsigned int len);

/**
 * @brief Finds out the minimum element in a input data array 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, finds the element having the minimum value 
 * and returns it. 
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data array
 *
 * @return Minimum value in the data array
 */

unsigned char find_minimum(unsigned char ptr[], unsigned int len);

/**
 * @brief Sorts the input array in descending order. 
 *
 * This function takes as an pointer to the unsigned character array and length
 * of the array as input parameters, performs bubble sort operation on the 
 * elements of the array.
 *
 * @param prt Unsigned character pointer to the array to be printed
 * @param len Length of the data arra
 *
 * @return None
 */

void sort_array(unsigned char ptr[], unsigned int len);

#endif /* __STATS_H__ */
