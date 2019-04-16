BEGIN {
    rw = 1;
    ww = 1;
    maxr = 0;
    maxw = 0;
}

/sr/{
    if(w > 0) {
        rw = 0;
    }
    r++;
    if(r > maxr) {
        maxr = r;
    }
}

/dr/ {
    r--;
}

/sw/ {
    if(r > 0) {
        rw = 0;
    }
    if(w > 0) {
        ww = 0;
    }
    w++;
    if(w > maxw) {
        maxw = w;
    }
}

/dw/{
    w--;
}

END {
    print "maxr = " maxr ", maxw = " maxw;
    if(rw) {
        print "reader/writer test: PASS";
    }else {
        print "reader/writer test: FAIL";
    }
    if(ww) {
        print "writer/writer test: PASS";
    }else {
        print "writer/writer test: FAIL";
    }
}
