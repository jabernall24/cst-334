#!/bin/bash
# test8.p
./prog < test8.p > temp.out 2>&1
diff -w temp.out test8.txt
