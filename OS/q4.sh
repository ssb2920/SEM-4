echo "Enter amount"
read amt
if test $amt -lt 1000
then 
	tax=`expr $amt \* 2 / 100`
	discount=`expr $amt \* 10 / 1000`
else 
	tax=`expr $amt \* 5 / 100`
	discount=`expr $amt \* 20 / 100`
fi
total=`expr $amt + $tax - $discount`
echo "Total is $total"