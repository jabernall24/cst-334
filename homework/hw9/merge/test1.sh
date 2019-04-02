#!/bin/bash
# par_merge
gcc -o pmsort test_sort.c par_merge.c -pthread -Wall
./pmsort
