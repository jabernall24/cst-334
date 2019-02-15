#!/bin/bash
# cd command works
 
# input
cat > temp-in.txt <<zzz
cd /home/CLASSES/brunsglenn
pwd
cd ..
pwd
exit
zzz
 
# correct output
cat > gold-out.txt <<zzz
/home/CLASSES/brunsglenn
/home/CLASSES
msh> msh> msh> msh> msh> 
zzz
 
# actual output
rm -f temp-out.txt
./msh < temp-in.txt > temp-out.txt
 
diff -w temp-out.txt gold-out.txt > diffs.txt
