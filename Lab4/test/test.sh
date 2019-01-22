#!/bin/bash

failed=0

# Prelab
g++ prelab.cc -o prelab
compile=$?
./prelab
test=$?

if [ ${compile} -ne 0 ] || [ ${test} -ne 0 ]; then
  echo "[ FAILED ] prelab"
  failed=1
else
  echo "[ OK     ] prelab"
fi

g++ led.cc -o led
compile=$?
./led
test=$?

if [ ${compile} -ne 0 ] || [ ${test} -ne 0 ]; then
  echo "[ FAILED ] led"
  failed=1
else
  echo "[ OK     ] led"
fi

g++ switch.cc -o switch
compile=$?
./switch
test=$?

if [ ${compile} -ne 0 ] || [ ${test} -ne 0 ]; then
  echo "[ FAILED ] switch"
  failed=1
else
  echo "[ OK     ] switch"
fi

g++ push_button.cc -o push_button
compile=$?
./push_button
test=$?

if [ ${compile} -ne 0 ] || [ ${test} -ne 0 ]; then
  echo "[ FAILED ] push_button"
  failed=1
else
  echo "[ OK     ] push_button"
fi



if [ ${failed} == 1 ]; then
  exit 1
fi


