#!/usr/bin/awk -f

$0 ~ "-- "ID{
	getline; print
}
