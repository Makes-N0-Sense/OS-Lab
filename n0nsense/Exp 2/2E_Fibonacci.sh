echo "Enter Limit: "
read lim
a=0
b=1
echo "$a"
echo "$b"
i=1
while [ $i -le `expr $lim - 2` ]
do
c=`expr $a + $b`
a=$b
b=$c
echo "$c"
i=`expr $i + 1`
done