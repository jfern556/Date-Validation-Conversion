// prog.h - file name
/******************************************************************************/
/*PROGRAM DEFINES*/

#include <stdio.h>
#include <limits.h>          //To be able to use LONG_MIN and LONG_MAX

#define INVALID -1           //Returning value when invalid
#define VALID 0              //Returning value when valid
#define LEAP 4               //Returning value when year is leap
#define MAX_CHAR_LINE 80     //Maximum number of characters per line
#define MIN_MONTH 1          //Minimum month, 1 or January
#define MAX_MONTH 12         //Maximum month, 12 or december
#define EXP_ARGUMENTS 2      //Correct number of arguments in the command line
#define DATE_PARAMETERS 3    //Correct number of parameters of a date m, d & y 
#define ENTERED_VAL argv[1]  //argv[1]
/******************************************************************************/

int days_year[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

int days_lyear[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

const char* months[] = {"ZERO","JAN","FEB", "MAR", "APR",
                        "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

/*******************************************************************************/
/*FUNCTIONS PROTOTYPES*/

int validate_entries (int, char *);
int validate_month (int);
int validate_year (long long int);
int validate_day (int, int, int);
