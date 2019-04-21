#!/bin/bash
# c file

# correct output
cat > gold-out.txt <<zzz
26
zzz

# actual output
rm -f temp-out.txt
./avg-line-len.awk < dotprod_serial.c > temp-out.txt

diff -w temp-out.txt gold-out.txt > diffs.txt
