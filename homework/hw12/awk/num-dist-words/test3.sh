#!/bin/bash
# c file

# correct output
cat > gold-out.txt <<zzz
179
zzz

# actual output
rm -f temp-out.txt
./num-dist-words.awk < dotprod_serial.c > temp-out.txt

diff -w temp-out.txt gold-out.txt > diffs.txt
