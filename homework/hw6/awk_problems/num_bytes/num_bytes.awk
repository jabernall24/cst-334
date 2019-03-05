#!/usr/bin/awk -f

/Alloc/ {
    if($3 ~ /[^0-9]*/){
        print substr($3, 7, length($3) - 7);
    }
}