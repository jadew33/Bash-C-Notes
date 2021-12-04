#!/bin/bash
pow(){
    x=$1
    y=$2
    res=$((x**y))
    echo $res
}

echo $(pow $1 $2)