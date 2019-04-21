#!/usr/bin/awk -f
# return average length of line in input file

# YOUR CODE HERE
{
    if(length($0) != 0) {
        sum += length($0);
        totalLines++;
    }
}

END {
    print int(sum / totalLines);
}