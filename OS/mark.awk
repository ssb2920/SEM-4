BEGIN {
	FS=",";
}

{
	id[NR]=$1;
	name[NR]=$2;
	total[NR]=($3 + $4 + $5 +$6 + $7)
	if (($3 && $4 >= 30) && ($5 && $6 && $7 >= 40))
	result[NR]= "PASS"
	else
	result[NR]= "FAIL" 
}

END {
	print "Showing results for "FNR" students \n";
	i=1;
	while (i<= FNR) {
	printf("%d %-10s %.2f %s\n", id[i] , name[i] , total[i] , result[i++]);
	}
}