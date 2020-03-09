echo "enter number"
read num
i=2
while [ $i -lt $num ]
do
k=`expr $num % $i`
if [ $k -eq 0 ]
then
echo "number is not prime"
exit
fi
i=`expr $i + 1`
done
echo "number is prime"
