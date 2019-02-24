#!/usr/bin/awk -f

$0 ~ "-- "ID{
	part = $0
}
$0 !~ "-- "ID{
	if(part != ""){
		print $0
		part = ""
	}
}
