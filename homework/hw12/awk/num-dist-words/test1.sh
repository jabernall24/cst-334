#!/bin/bash
# small file
# input
cat > temp-in.txt <<zzz
1234 6789
1234
zzz

# correct output
cat > gold-out.txt <<zzz
2
zzz

# actual output
rm -f temp-out.txt
./num-dist-words.awk < temp-in.txt > temp-out.txt

diff -w temp-out.txt gold-out.txt > diffs.txt
