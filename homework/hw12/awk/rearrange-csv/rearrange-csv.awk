#!/usr/bin/awk -f
# output columns prob_id, score, Identifier of input file,
# in that order

# YOUR CODE HERE
BEGIN {
    FS = ",";
}

{
    if(count != 0) {
        print $line["prob_id"] "," $line["score"] "," $line["Identifier"];
    }else {
        print "prob_id,score,Identifier";
        for(i = 1; i <= NF; i++) {
            if($i == "prob_id" || $i == "score" || $i == "Identifier") {
                line[$i] = i;
            }
        }
        
        count++;
    }
}