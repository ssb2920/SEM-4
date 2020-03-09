echo "enter a number"
read n
echo "enter the power"
read y
i=1
j=1
while test $i -le $y
do
j=`expr $j \* $n`
i=`expr $i + 1`
done
echo $j