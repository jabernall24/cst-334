/* 
 * Test a sort algorithm for correctness
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "merge_sort.h"

// test merge sort
int main() {
  // size of test data array
    int n = 100;//10000;

  // initialize input
  float *x = (float *)malloc(n * sizeof(float));
  int i;
  for (i = 0; i < n; i++) {
    x[i] = drand48();
      printf("%f", x[i]);
  }
    

  merge_sort(x, n);
  
  // check the output for correctness
  float last = -1.0;
  for (i = 0; i < n; i++) {
    if (x[i] < last) {
      printf("sort error at element %d\n", i);
      exit(1);
    }
    last = x[i];
  }
  printf("output was sorted correctly\n");

  return 0;
}


