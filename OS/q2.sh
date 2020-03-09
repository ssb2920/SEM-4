echo "Enter 3 numbers"
read a
read b
read c
if test $a -gt $b -a $a -gt $c
then echo "$a is greater"
else 
	if test $b -gt $c 
	then echo "$b is greater"
	else
		echo "$c is greater"
	fi
fi
