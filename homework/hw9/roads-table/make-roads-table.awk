# extract road information from an OSM file

# YOUR CODE HERE
BEGIN {
    print "road,way_id,seq_num,node_id"
}
/<way/ {
    count = 0;
    id = substr($2, 5, length($2) - 5);

    getline;
    while($1 ~ "<nd") {
        node_id = substr($2, 6, length($2) - 8);
        some[++count] = node_id;
        getline;
    }

    name = "";
    while($1 ~ "<tag") {
        if($2 ~ "k=\"name\""){
            name = substr($0, index($0, $3));
            name = substr(name, 4, length(name) - 6);
            break;
        }
        getline; 
    }
    
    if (name == ""){
        name = "unnamed";
    }

    for(i = 1; i <= count; i++) {
        print name "," id "," i "," some[i];
    }
}