#!/bin/bash
./run-tests.sh > temp.out 2>&1
diff -w temp.out expected-output.txt
