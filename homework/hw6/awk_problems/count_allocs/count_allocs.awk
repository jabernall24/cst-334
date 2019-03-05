#!/usr/bin/awk -f

/returned/{
	if($5 ~ -1){
		cnt["failures"]++;
	}else if($5 ~ 0){
		cnt["successes"]++;
	}
}
END {

	print "num successes: " cnt["successes"] "; num failures: "cnt["failures"];
}
