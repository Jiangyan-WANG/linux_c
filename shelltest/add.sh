#!/bin/bash
#

sum=0
while [ -n "$1" ]
do
    sum=$(($1+sum))
    shift
done
echo "$sum"


