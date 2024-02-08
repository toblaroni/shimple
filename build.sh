#!/bin/bash

g++ shimple.cpp -o shimple

if [ $? -ne 0 ]; then
   exit
fi

if [[ "$1" == "-r" ]]; then
   ./shimple
fi
