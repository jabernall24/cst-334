#!/usr/bin/awk -f
# return number of distinct words in the input file

# YOUR CODE HERE
{
    for(i = 1; i <= NF; i++) {
        words[$i]++;
    }
}

END {
    for(n in words) { 
        count++;
    }

    print count;
}