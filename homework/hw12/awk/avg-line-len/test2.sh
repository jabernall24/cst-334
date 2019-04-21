#!/bin/bash
# file with blank lines
# input
cat > temp-in.txt <<zzz
1234 6789

1234 67
zzz

# correct output
cat > gold-out.txt <<zzz
8
zzz

# actual output
rm -f temp-out.txt
./avg-line-len.awk < temp-in.txt > temp-out.txt

diff -w temp-out.txt gold-out.txt > diffs.txt
