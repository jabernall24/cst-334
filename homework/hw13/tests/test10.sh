#!/bin/bash
# test10.p
./prog < test10.p > temp.out 2>&1
diff -w temp.out test10.txt
