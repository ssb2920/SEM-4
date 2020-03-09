echo "Enter number"
read n
y=`expr $n % 2`
if test $y -ne 1
then echo "$n is even"
else
	echo "$n is odd"
fi
