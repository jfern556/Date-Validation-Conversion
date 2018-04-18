// prog2.c - file name
/****************************************************************************/
/*PROGRAM DOCUMENTATION

 AUTHOR: Jessica Fernandez-Rubio

 Programming III. Fifth Assignment

 PROGRAM DESCRIPTION: This program will be getting lines form stdin and reading 
 them. The lines will be valid dates in the format mm/dd/yyyy. It will read 
 these dates and transform them to  the format dd "month" yyyy being the month
 a string with the first three characters of the name of the month. 

 INPUT: N/A

 OUTPUT: It will create a file with the new formatted dates  and the original 
 appended. 

 Compilation: make

 Execute: ./prog1out.o < dates.dat "number" |./prog2out.o > output.dat

 I hereby certify that this collective work is my own and none of it,
 is the work of any other person or entity.

 */
/******************************************************************************/

#include "prog.h" //Including the header file

int main (){
   char line [MAX_CHAR_LINE];
   long long int month, day, year;
   
   FILE *file_in;
   FILE *file_out;

   file_in = fopen ("dates.dat", "r");
   file_out = fopen ("output.dat", "a");
 
   while (fgets(line,sizeof(line), stdin) != NULL){
      sscanf(line,"%lld/%lld/%lld", &month, &day, &year);
      printf("%lld %s %lld\n", day, months[month], year);
   }

   fflush(stdout);
   
   while (fgets(line,sizeof(line), file_in) != NULL){
      fprintf(file_out, "%s\n", line);
   }

   fclose(file_in);
   fclose(file_out);

   return  VALID;
}

