#!/bin/bash

g++ ../list.cc -o list

failed=0
for dir in ./*/
do
    dir=${dir%*/}
    cd ${dir}
    echo "Test input ${dir}" 
    ../list <in >out 2>err

    diff out out_std
    step1=$?

    # diff err err_std
    # step2=$?
    step2=0

    if [ ${step1} -ne 0 ] || [ ${step2} -ne 0 ]; then
      echo "[ FAILED ]"
      failed=1
    else
      echo "[ OK     ]"
    fi

    cd ..
done

if [ ${failed} == 1 ]; then
  exit 1
fi

