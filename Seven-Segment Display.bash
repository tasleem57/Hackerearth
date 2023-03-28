i=0
read t
while [ $i -lt $t ]
do
sum=0
j=0
read n
x=( $( echo $n | sed 's/\B\B/ /g' ) )
for j in ${!x[*]}
do
d="${x[$j]}"
if [ $d -eq 0 -o $d -eq 6 -o $d -eq 9 ]
then
sum=$(( $sum+6 ))
elif [ $d -eq 2 -o $d -eq 3 -o $d -eq 5 ]
then
sum=$(( $sum+5 ))
elif [ $d -eq 7 ]
then 
sum=$(( $sum+3 ))
elif [ $d -eq 4 ]
then
sum=$(( $sum+4 ))
elif [ $d -eq 8 ]
then
sum=$(( $sum+7 ))
else
sum=$(( $sum+2 ))
fi
done
while [ $(( $sum%2 )) -ne 0 ]
do
sum=$(( $sum-3 ))
echo -n "7"
done
k=0
while [ $k -lt $(( $sum/2 )) ]
do
echo -n "1"
k=$(( $k+1 ))
done
i=$(( $i+1 ))
echo 
done
