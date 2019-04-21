#!/bin/bash
# scores.csv

# get output
rm -f temp-out.txt
./rearrange-csv.awk < scores1.csv > temp-out.txt
diff -w temp-out.txt test1.csv > diffs.txt
