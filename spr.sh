#!/bin/bash

if [ -z $1 ]; then
  echo "Usage: spr.sh [input location] [executable] [output location]"
  exit
fi

inDir=$1
exe=$2
outDir=$3

if [ ! -f ./chk ]; then
    g++ chk.cpp -o chk -O3 -std=c++20 -static
fi

index=0
passed=1
for i in `find -type f -wholename "$inDir/*.in" | cut -d ' ' -f 1`
do
    index=$(( $index + 1 ))

    echo $i > ./spr/tmp
    name=`cut ./spr/tmp -d '.' -f 2`
    name2=`echo "$name" | rev | cut -d '/' -f 1 | rev`
    input=".$name.in"
    output="./$3/$name2.out"

    $exe < $input > ./spr/rpk.out 2> /dev/null
    cat $input > ./spr/chk.in
    cat $output >> ./spr/chk.in
    cat ./spr/rpk.out >> ./spr/chk.in
    ./chk < ./spr/chk.in > ./spr/chk.out
    if diff spr/chk.out spr/ok.out; then
        echo -ne "Test $index ($name2) ok \r"
    else
        echo "Test $index ($name2) nieok"
        passed=0
        break
    fi
done

if [ $passed -eq 1 ]; then
    echo -ne "                                                            \r"
    echo "All tests passed"
fi
