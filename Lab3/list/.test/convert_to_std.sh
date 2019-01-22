#!/bin/bash

for dir in ./*/
do
  cd ${dir}
  mv out out_std
  mv err err_std
  cd ..
done
