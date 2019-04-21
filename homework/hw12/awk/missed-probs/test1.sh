#!/bin/bash
# scores.csv

# get output
rm -f temp-out.txt
./missed-probs.awk < scores.csv > temp-out.txt
diff -w temp-out.txt test1.csv > diffs.txt
