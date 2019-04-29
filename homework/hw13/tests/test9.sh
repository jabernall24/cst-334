#!/bin/bash
# test9.p
./prog < test9.p > temp.out 2>&1
diff -w temp.out test9.txt
