#!/usr/bin/awk -f

/Alloc/{
    a = substr($3, 7, length($3) - 7);
    if($5 >= 0){
        print a" 1";
    }else{
        print a" 0";
    }
}