/******************************************************************************
* FILE: dotprod_serial.c
* DESCRIPTION:
*   This is a simple serial program which computes the dot product of two 
*   vectors.  The threaded version can is dotprod_mutex.c.
* SOURCE: Vijay Sonnad, IBM
* LAST REVISED: 01/29/09 Blaise Barney
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*   
  The following structure contains the necessary information  
  to allow the function "dotprod" to access its input data and 
  place its output so that it can be accessed later. 
*/

typedef struct {
  double      *a;
  double      *b;
  double     sum; 
  int    veclen; 
} DOTDATA;

#define VECLEN 100000
DOTDATA dotstr; 

/*
  We use a function (dotprod) to perform the scalar product. 
  All input to this routine is obtained through a structure of 
  type DOTDATA and all output is written into
  this same structure.  While this is unnecessarily restrictive 
  for a sequential program, it will be useful when
  we modify the program to compute in parallel.
*/

void dotprod() {
  double *x, *y;

  int start=0;
  int end = dotstr.veclen;
  x = dotstr.a;
  y = dotstr.b;

  /*
    perform the dot product and assign the result
    to the appropriate variable in the structure 
  */
  int i;
  double mysum = 0;
  for (i = start; i < end ; i++) {
    mysum += (x[i] * y[i]);
  }
  dotstr.sum = mysum;
}

// initialize data, call dotprd(), and print the result
int main (int argc, char *argv[])
{
  int i,len;
  double *a, *b;
   
  /* assign storage and initialize values */
  len = VECLEN;
  a = (double*) malloc (len*sizeof(double));
  b = (double*) malloc (len*sizeof(double));
  
  for (i = 0; i < len; i++) {
    a[i] = 1;
    b[i] = a[i];
  }

  dotstr.veclen = len; 
  dotstr.a = a; 
  dotstr.b = b; 
  dotstr.sum = 0;

  dotprod ();

  /* print result and release storage */ 
  printf ("Sum =  %f \n", dotstr.sum);
  free(a);
  free(b);
}
