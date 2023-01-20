#!/bin/bash

varname="hello"
#echo $varname
#echo ${varname}
export envVar="enviromnent variable"
function test()
{

    globalVar="world"

    local localVar="local"
    echo $globalVar

    echo $localVar

}

echo $varname
#echo $globalVar
#echo $localVar

test

./subshell.sh
