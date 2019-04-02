#!/bin/bash
# make-roads-table
awk -f make-roads-table.awk csumb.osm > temp.txt
diff -w temp.txt test1.txt > diffs.txt
