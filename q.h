/*!
@file       q.h
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Assignment 10
@Assignment Dynamic Memory Allocation and Sorting
@date       25/11/2021
@brief      This header file contains declarations to perform the task of q.c. Overall, the 
            description of q.h is to provide a file of declarations for the driver source 
            file to be able to identify and call the functions.
*//*______________________________________________________________________________________*/
#include <stdio.h>  //fscanf
#include <math.h>   //math functions; pow, sqrt
#include <stdlib.h> //exit macro

// provide enumeration type declaration - the enumeration type must be anonymous - that is,
// the enumeration type must not have an enumeration tag.
#define A_GRADE 0
#define B_GRADE 1
#define C_GRADE 2
#define D_GRADE 3
#define F_GRADE 4
#define TOT_GRADE 5

/*!
@brief  This function opens the data file specified by the parameter file_name and determines
        the count of grades in the file and writes the count to the location pointed to by 
        parameter ptr_cnt. It then allocates enough heap memory to contain the contents of 
        the data file and copies the grades from the file to this heap memory. If it is 
        unable to open or read the file, the program returns a NULL; otherwise it returns the 
        address of the first byte of the previously allocated heap memory containing the 
        values read from the file.

@param  file_name is a function parameters of a pointer to const char
        ptr_cnt is a function parameter of a pointer to an int
        fptr is a pointer to the type file
        size is a data type of long unsigned int or size_t
        file and sub are pointers of type double
        count is of data type int

@return sub 
*//*_______________________________________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt);

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the maximum value and return it.

@param  begin and end are functions parameters of a pointer to const double
        max is of type double

@return max 
*//*_______________________________________________________________________________________*/
double max(double const *begin, double const *end);

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the minimum value and return it.

@param  begin and end are functions parameters of a pointer to const double
        min is of type double

@return min 
*//*_______________________________________________________________________________________*/
double min(double const *begin, double const *end);

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the total value and divides that value by the total number of 
        numbers present and returns the average.

@param  begin and end are functions parameters of a pointer to const double
        avg is of type double
        count is a data type of int

@return avg
*//*_______________________________________________________________________________________*/
double average(double const *begin, double const *end);

/*!
@brief  This function calls the function that calculates the average value in the contents
        of the memory location of begin and calculates the variance between the numbers. It
        then returns the variance.

@param  begin and end are functions parameters of a pointer to const double
        var, num is of type double

@return var/(num-1) 
*//*_______________________________________________________________________________________*/
double variance(double const *begin, double const *end);

/*!
@brief  This function calls the function that calculates the variance and returns the 
        standard deviation.

@param  begin and end are functions parameters of a pointer to const double
        var, std_dev are of type double

@return std_dev 
*//*_______________________________________________________________________________________*/
double std_dev(double const *begin, double const *end);

/*!
@brief  This function calls the function that sorts he values in the memory location of base 
        and returns the median or middle number in the contents of the base parameter.
         0  1  2   3   4    5
        {1, 6, 18, 39, 86} median is 18
        {1, 18, 39, 39, 86, 128} median is 39+39/2

@param  base is a function parameter of a pointer to a type double
        size is a function parameter of type int
        num and median are of type double

@return median  
*//*_______________________________________________________________________________________*/
double median(double *base, int size);

/*!
@brief  This function sorts the size number of numbers of values of the array whose first 
        value is pointed to by base in an ascending order.

@param  base is a function parameter of a pointer to a type double
        size is a function parameter of type int
        ele, repeat are of type int
        tmp is of type double

@return nothing 
*//*_______________________________________________________________________________________*/
void selection_sort(double *base, int size);

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to assign the number of times each value is catergorized as per the grading 
        system.
        90 and above is A_Grade
        80 to less than 90 is B_Grade
        70 to less than 80 is C_Grade
        60 to less than 70 is D_Grade
        less than 60 is F_Grade

@param  begin and end are functions parameters of a pointer to const double
        ltr_grades is a pointer to a data type of double
        counts, num, counter are data type of int

@return nothing
*//*_______________________________________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end,
                    double *ltr_grades);

