#!/usr/bin/awk -f

/Alloc/ {print substr($3, 7, length($3) - 7);}