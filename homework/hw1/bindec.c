#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max length input string
#define MAXSTR 25

// convert input binary string to a number

int main() {

   // user input string
   char s[MAXSTR+3]; 

   // prompt for input
   printf("> ");

   // read input string; at most MAXSTR+1 chars accepted
   // Note: this is tricky. If we accept only MAXSTR chars,
   // we can't see if user entered more chars and they are
   // being dropped by fgets.
   fgets(s, MAXSTR+3, stdin);

   // check input length; n does not include final carriage return
   int n = strlen(s)-1;  
   if (n > MAXSTR) {
     printf("input cannot be more than %d characters\n", MAXSTR);
     exit(1);
   }

   // convert s from a string in binary, to an int, and output
   
   // YOUR CODE HERE 
   int i;
   int multiplier = 1;
   int sum = 0;
   for(i = n-1; i >= 0; i--){
      if(s[i] == '1'){
	sum += multiplier;
      }else if(s[i] != '0'){
	printf("input must contain only zeros and ones\n");
        exit(1);
      }
      multiplier *= 2;
   }
   printf("%d\n", sum);
    return 0;
}

