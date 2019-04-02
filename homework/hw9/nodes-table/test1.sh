#!/bin/bash
# make-nodes-table
awk -f make-nodes-table.awk csumb.osm > temp.txt
diff -w temp.txt test1.txt > diffs.txt
