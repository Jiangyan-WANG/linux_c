#!/bin/bash
#

function test()
{
    varAdd=0
    varAdd=$(($1+varAdd))
    varAdd=$(($2+varAdd))
    echo "$varAdd"
    return 1
}

test $1 $2
