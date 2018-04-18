// prog1.c - file name
/****************************************************************************/
/*PROGRAM DOCUMENTATION
 
 AUTHOR: Jessica Fernandez-Rubio
 
 Programming III. Fifth Assignment
 
 PROGRAM DESCRIPTION: 
 
 INPUT: Accepts one input through the Command Line. Reads a file called 
 "dates.dat" and gets line by line to validate the lines in the file, 
 making sure they are in the correct format mm/dd/yyyy and making sure the 
 relation of month day and year are correct. Once dates are validated, they
 get printed according to the initial number input. If the input is 1 then one
 line gets printed, if its 0 then all valid dates get printed, if its 2 two 
 valid dates get printed and so on.   
 
 OUTPUT: Valid dates. Input number defines how many valid dates get printed. 
 
 Compilation: make 
 
 Execute:./prog1out.o < dates.dat "number"    //run program 1 by itself  
         ./prog1out.o < dates.dat "number" | ./prog2out.o > output.dat

        Note: Where it says number it goes the input. Just enter the number 
              without the quotations. 

 I hereby certify that this collective work is my own and none of it,
 is the work of any other person or entity.

 */
/******************************************************************************/
#include "prog.h" //Including the header file

int main(int argc, char *argv[])
{
    int counter = 0;
    char line [MAX_CHAR_LINE];
    int month;
    int day;
    long long int year;
    int r_month;
    int r_year;  
    int r_day;
    int valid_result;
    int count = 0;
    int function_result = 0;
    int input;

    valid_result = validate_entries(argc, ENTERED_VAL);
    if (valid_result == VALID){
       input = atoi (ENTERED_VAL);
      
        while( fgets (line, MAX_CHAR_LINE, stdin)!= NULL && ((!input || (count < input)))){
          counter = sscanf(line,"%2d/%2d/%lld", &month, &day, &year);
          if (counter == DATE_PARAMETERS){
             r_month = validate_month(month);
             r_year = validate_year(year);
             r_day = validate_day(month, r_year,day);
             if (r_month == VALID && (r_year == VALID || r_year == LEAP) &&
                    r_day == VALID) {
                printf("%d/%d/%lld\n", month, day, year);
                count++;
	     }
          }
       }
    }
    return VALID;
}


/********************************************************************************/
/**Function: validate_entries
 This function checks if the command line inputs are right. It checks if argc is
 2 which is the number of expected arguments, one for program name and one for 
 input. 
 
 Returns: The return is 0 (VALID) if valid or 1(INVALID) if not valid.
 */
/********************************************************************************/
int validate_entries (int total_arguments, char *input){
    int v_input;
    if (total_arguments != EXP_ARGUMENTS){
       return INVALID;
    }
    else {
       v_input = atoi(input);
       if (v_input < 0){
          return INVALID;
       } 
       else return VALID;
    }
}


/********************************************************************************/
/**Function: validate_month
 This fucntion checks if an integer value is in the range from 1 to 12 which are
 the bounds of months. 

 Returns: Returns valid if the number is within the range, returns invalid 
 otherwise. 
 */
/********************************************************************************/
int validate_month(int month){
    if ((month >= MIN_MONTH) && (month <= MAX_MONTH))
       return VALID;
    else 
       return INVALID;  
}


/********************************************************************************/
/**Function: validate_year
 This function receives a long long int value and checks if its greater than the 
 minimum integer and smaller or equal to the max int in the limits.h library. This
 is to make sure there is no overflow. After it checks this, then it checks if the 
 year is leap, for a year to be leap has to be divisible by 4, (year%4 == 0), 
 except the years that complying with this condition, are divisible by 100, but 
 are not divisible by 400. 

 Returns: Returns valid if year is valid but not leap, returns invalid if year is
 invalid and leap which means is valid and leap. 
 */
/********************************************************************************/
int validate_year (long long int year) {
    if ((year >= INT_MIN) && (year <= INT_MAX)){ 
       if ((year % 4) == 0){
          if ((year % 100) == 0 && (year % 400) != 0){

          }
          else {return LEAP;} 
       }
       else {return VALID;}
    }
    else {return INVALID;}
}


/********************************************************************************/
/**Function: validate_day
 This function has three parameters. the month the day and the result of year (
 weather is valid invalid or leap). It calls the arrays days_year []  if year
 return is valid and ldays_year [] is year is leap. An checks if the day is 
 correct according to the month and the type of year.


 Returns: Returns either valid or invalid for the cases of the day being valid
 or invalid. 
 */
/********************************************************************************/
int validate_day ( int month, int year_return, int day){
    if(year_return == VALID){
       if (day > 0 && day <= days_year[month]){
           return VALID;
       }
       else
           return INVALID;
    }
    else
       if (year_return == LEAP){
        if (day > 0 && day <= days_lyear[month]){ 
           return VALID;
       }
       else
           return INVALID;
       }
}
