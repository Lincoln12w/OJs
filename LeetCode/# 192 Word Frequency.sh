#!/bin/bash
# 2017-09-13 

cat words.txt | tr -cs a-z '\n' | sort -rn | uniq -c | sort -rn | awk '{print $2, $1}' 