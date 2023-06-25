echo "Enter Number: "
read num
if [ `expr $num % 2` -eq 0 ]
then
echo "Number is Even"
else
echo "Number is Odd"
fi