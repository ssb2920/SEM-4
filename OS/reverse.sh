#!/bin/sh
echo "enter number"
read n
sum=0
while test $n -ne 0
do  rem=`expr $n % 10`
	sum=`expr $rem + $sum \* 10`
	n=`expr $n / 10`
done 
echo "reverse is $sum"