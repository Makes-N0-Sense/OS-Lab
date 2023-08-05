echo "Enter Number 1: "
read num1
echo "Enter Number 2: "
read num2
echo "Enter Number 3: "
read num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
echo "$num1 is Greater"
else if [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
echo "$num2 is Greater"
else
echo "$num3 is Greater"
fi 
fi