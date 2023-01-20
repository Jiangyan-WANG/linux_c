#!/bin/bash

curPath=$(cd `dirname $0`;pwd)
echo $curPath
date >> $curPath/date.txt
