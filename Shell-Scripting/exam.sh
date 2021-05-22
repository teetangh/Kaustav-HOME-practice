echo "Give number"
read number

temp=0
tempmax=0

while [ $number -gt 0 ]; do
    temp=$(expr $number % 10)
    if [ $(($temp > tempmax)) -a $(($temp % 2 == 0)) ]; then
        temporary=$temp
        temp=$tempmax
        tempmax=$temporary
    fi
    number = $(($number / 10))
done

echo $tempmax
