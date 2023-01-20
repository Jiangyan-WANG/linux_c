#!/bin/bash
#

for FRUIT in banana apple orange
do
    touch "$FRUIT.txt"
done

varSum=0

for i in {1..100}
do
    varSum=$((varSum+i))
done
echo $varSum


for FILE in $(ls)
do
    if [ -f $FILE ]
    then
        echo "$FILE 是一个普通文件"
    else
        echo "$FILE 是一个目录"

    fi
done

sum=0
count=0
while [ $count -le 100 ]
do
    sum=$((sum+count))

    count=$((count+1))
done

echo "$sum"

