#!/usr/bin/awk -f

/Free List/{
    split($0, n, " ");
    i = 9;
    a = "";
    while(n[i] != ""){
        b = substr(n[i], 4, length(n[i] - 4));
        a = a " "b;
        i += 4;
    }
    print a;
}