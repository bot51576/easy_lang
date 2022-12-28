#!/bin/bash 
gcc -std=c11 -o main main.c

runtest() {
  output=$(./main "$1")
  if [ "$output" != "$2" ]; then 
    echo "$1: $2 expected, but got $output"
    exit 1
  fi 
  echo "$1 => $output"
}


runtest 0 0 
runtest 1 1 
runtest 99 99 
runtest '5-3' 2
runtest '6+3' 9
runtest '6- 2' 4
runtest '6 - 3' 3
runtest '6*5' 30
runtest '6/3' 2

echo OK
