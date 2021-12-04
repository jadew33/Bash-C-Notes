#!/bin/bash
test(){
    param1=$1
    param2=$2
    param3=$3
    echo "$# arguments passed to function"
    echo "param1 = ${param1}"
    echo "param2 = ${param2}"
    echo "param3 = ${param3}"
}

test
test a
test a b 
test a b c
test a b c d
