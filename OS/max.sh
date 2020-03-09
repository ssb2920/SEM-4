a=$1
b=$2
c=$3
if test $# -ne 3
then echo "Insufficient arguments"
exit
fi
if test $a -gt $b -a $a -gt $c
then echo "$a is greater"
else 
	if test $b -gt $c 
	then echo "$b is greater"
	else
		echo "$c is greater"
	fi
fi
