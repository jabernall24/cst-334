#!/bin/bash
# test11.p
./prog < test11.p > temp.out 2>&1
diff -w temp.out test11.txt
