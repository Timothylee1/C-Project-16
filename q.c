/*!
@file       q.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Assignment 10
@Assignment Dynamic Memory Allocation and Sorting
@date       25/11/2021
@brief      This file contains definitions that creates counts the number of grades stored
            in a text file that contains doubles and allocates appropriate memory into the 
            heap memory as a container for the contents of the file. This program then 
            provides the minimum, maximum, average, and median grades, variance and standard
            deviation of the grades and the percentage of the grades for each letter grade.
            E.g.
            Total number of grades: 10

            Letter Grade |  %age 
            ----------------------
                 A       | 10.00
                 B       |  0.00
                 C       | 10.00
                 D       | 50.00
                 F       | 30.00

            Maximum grade     :  95.95
            Minimum grade     :  34.78
            Average grade     :  63.50
            Variance          : 266.97
            Standard deviation:  16.34
            Median grade      :  64.67
*//*______________________________________________________________________________________*/

#include "q.h"

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
double* read_data(char const *file_name, int *ptr_cnt) {
    FILE *fptr = fopen(file_name, "r");
    if(fptr == NULL) {                                              //Unable to open/locate file
        exit(EXIT_FAILURE);
        return NULL;
    }
    fseek(fptr, 0, SEEK_END);                                       //Seeks from offset of file to end of file and points there
    size_t size = ftell(fptr) * sizeof(double);                     //ftell gets size of file which is the current value of the position indicated
    fseek(fptr, 0, SEEK_SET);                                       //points back to start of file
    double *file = malloc(size);                                    //Allocates memory size into heap memory
    double *sub = file;                                             //To return the pointer to the first element of the array
    int count = 0;                                                  //Declared as compiler flagged *ptr_cnt as unused when *(ptr_cnt)++ in the for loop
    for(; fscanf(fptr, "%lf", file++) != EOF; count++);
    *ptr_cnt = count;   
    fclose(fptr);
    return sub;
}

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the maximum value and return it.

@param  begin and end are functions parameters of a pointer to const double
        max is of type double

@return max 
*//*_______________________________________________________________________________________*/
double max(double const *begin, double const *end) {
    double max;
    for(max = 0.0; begin != end; begin++) 
        max = max < *begin ? *begin : max;                           //if max < *begin then max = *begin, else max = max;
    
    return max;
}

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the minimum value and return it.

@param  begin and end are functions parameters of a pointer to const double
        min is of type double

@return min 
*//*_______________________________________________________________________________________*/
double min(double const *begin, double const *end) {
    double min;
    for(min = 100.00; begin != end; begin++) 
        min = min > *begin ? *begin : min;                           //if min > *begin then min = *begin, else min = min;
    
    return min;
}

/*!
@brief  This function searches through the contents of the values stored in the begin memory
        location to find the total value and divides that value by the total number of 
        numbers present and returns the average.

@param  begin and end are functions parameters of a pointer to const double
        avg is of type double
        count is a data type of int

@return avg
*//*_______________________________________________________________________________________*/
double average(double const *begin, double const *end) {
    int count;
    double avg;
    for(count = 0, avg = 0.0; begin != end; begin++, count++) 
        avg += *begin;

    return avg / count;
}

/*!
@brief  This function calls the function that calculates the average value in the contents
        of the memory location of begin and calculates the variance between the numbers. It
        then returns the variance.

@param  begin and end are functions parameters of a pointer to const double
        var, num is of type double

@return var/(num-1) 
*//*_______________________________________________________________________________________*/
double variance(double const *begin, double const *end) {
    double var, num;
    double avg = average(begin, end);                                //calls the function average to get avg
    for(var = 0.0, num = var; begin != end; begin++, num++)
        var += pow((*begin - avg), 2);

    return var/(num-1);
}

/*!
@brief  This function calls the function that calculates the variance and returns the 
        standard deviation.

@param  begin and end are functions parameters of a pointer to const double
        var, std_dev are of type double

@return std_dev 
*//*_______________________________________________________________________________________*/
double std_dev(double const *begin, double const *end) {
    double var = variance(begin, end);                               //calls the function variance to get var
    double std_dev = sqrt(var);
    return std_dev;
}

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
double median(double *base, int size) {
    selection_sort(base, size);                                      //calls the function selection_sort to arrange the numbers in the array
    double num = (double) (size)/2;                                  //either decimal or whole int
    double median = 0.0;
    if (num == (int)num) {                                           //checks if num is a whole int
        median = ( *(base+(int)num) + *(base+(int)(num-1)) )/2;      //if 6/2 = 3, it'll take the 4th n 3rd elements' average
    } 
    else {
        median = *(base+(int)num);                                   //if 5/2 = 2.5 then cast num to int will be 2, and it'll take the 2nd element
    }
    return median;
}

/*!
@brief  This function sorts the size number of numbers of values of the array whose first 
        value is pointed to by base in an ascending order.

@param  base is a function parameter of a pointer to a type double
        size is a function parameter of type int
        ele, repeat are of type int
        tmp is of type double

@return nothing 
*//*_______________________________________________________________________________________*/
void selection_sort(double *base, int size) {
    int ele = 0;
    for(int repeat = 0; repeat < size; repeat++) {                   //reiterates through the seires multiple times 
        for(ele = 0; ele < size-1; ele++) {                          //compares left and right  
            if(*(base+ele) > *(base+ele+1) ) {                       //switches place of left and right elements
                double tmp = *(base+ele);
                *(base+ele) = *(base+ele+1);
                *(base+ele+1) = tmp;
            }
        }
    }
}

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
                    double *ltr_grades) {
    //percentage of values in the data file that map to a letter grade [0,100]
    int counts = 0;
    for(int num = 0; begin != end; begin++, counts++) {
        if (*begin >= 90)
            num = A_GRADE;
        else if (*begin >= 80)
            num = B_GRADE;
        else if (*begin >= 70)
            num = C_GRADE;
        else if (*begin >= 60)
            num = D_GRADE;
        else
            num = F_GRADE;
        ltr_grades[num]++;                                           //increment the double value in the subscript num 
    }

    for(int counter = 0; counter <= F_GRADE; counter++, ltr_grades++)
        *ltr_grades = (*ltr_grades*100)/counts;                      //Converts the element in ltr_grades to percentage of total number (counts)
}
