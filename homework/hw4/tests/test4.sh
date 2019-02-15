#!/bin/bash
# msh runs script
 
# input
cat > temp-in.txt <<zzz
wc -l test1.sh
grep cat test2.sh
zzz
 
# correct output
cat > gold-out.txt <<zzz
4 test1.sh
cat > temp-in.txt <<zzz
cat > gold-out.txt <<zzz
zzz
 
# actual output
rm -f temp-out.txt
./msh temp-in.txt > temp-out.txt
 
diff -w temp-out.txt gold-out.txt > diffs.txt
