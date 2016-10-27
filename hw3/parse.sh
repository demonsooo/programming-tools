#!/bin/bash

#CSE 374 HW3
#Yijia Liu 1238339

if [ $# -lt 2 ]
then
>&2 echo "Error: need at least two arguments"
exit 1
fi

if [ ! -a "$f1" ]
then
>&2 echo "Error: html file doesn't exist"
exit 1
fi

grep -Eo '<strong><a href.*' "$1" > temp

sed -e 's/.*\(http:.*\)".*/\1/' temp > "$2"

rm temp

exit