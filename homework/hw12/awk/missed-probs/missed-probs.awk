#!/usr/bin/awk -f
# for *every* problem ID in input, give number of incorrect (non-0) answers

# YOUR CODE HERE
BEGIN {
    FS = ",";
}

{
    if(int($1)) {
        if(problem[substr($4, 13)] == 0) {
            problem[substr($4, 13)] = 0;
        }

        if($3 != 0) {
            problem[substr($4, 13)]++;
        }
    }
}

END {
    print "prob_id,num_missed";
    for(i = 1; i <= length(problem); i++) {
        print i","problem[i];
    }
}