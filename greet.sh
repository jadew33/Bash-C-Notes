#!/bin/bash

greet(){
    local var=greet
    echo "Hello, var is ${var}"
    leave
}

leave(){
    echo "Goodbye, var is ${var}"
}

var=global
greet
echo "var is ${var}"