#!/bin/bash

#CSE 374 HW3
#Yijia Liu 1238339

i=1

while read line
do
    echo Performing measurement on $line
    temp=$(./perform-measurement.sh $line)
    if [ $temp -eq 0 ] ; then
        echo "...failed"
    else
        echo "...success"
        echo "$i" "$line" "$temp" >> "$2"
    fi
    ((i=$i+1))
done < "$1"

exit