#!/usr/bin/awk -f

BEGIN {
	OFS = ","
	FS=","
}
{
	gsub("prob_desc", "comments",$0)

	gsub("3", "3_c", $2)
	gsub("1", "3_a", $2)
	gsub("2", "3_b", $2)
	gsub("4", "3_d", $2)
	gsub("5", "3_e", $2)

	if(i%5 == 1){
		gsub("0","10", $3)
	}else{
		gsub("0", "5", $3)
	}
	gsub(/1$/,"0",$3)
	if(/^[0-9]/){
		print "Participant " $0
	}else{
		print $0
	}
	i++
}
