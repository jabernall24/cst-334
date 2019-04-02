# extract node information from an OSM file

# YOUR CODE HERE
BEGIN {
    print "node_id,lat,long";
}
/<node/ {
    print substr($2, 5, length($2) - 5) "," substr($3, 6, length($3) - 6) "," substr($4, 6, length($4) - 6);
}