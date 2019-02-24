/returned/{
	if($5 ~ -1){
		cnt["failures"]++
	}else{
		cnt["successes"]++
	}
}
END {
	for(name in cnt) print "num " name ": " cnt[name] ";"
}
