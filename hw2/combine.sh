#!/bin/bash

#CSE 374 HW2
#Yijia Liu 1238339

if [ $# -lt  2 ]
then
	>&2 echo "Error: need at least two arguments"
	exit 1
fi

f1="$1"

if [ -a "$f1" ]
then
	>&2 echo "Error: first file exists"
	exit 1
fi

touch temp

shift
for f in "$@"
do
    cat "$f" >>temp 2>> "$f1"
done

cat temp

exit

 