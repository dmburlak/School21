#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error: Incorrect input"
    exit 1
else
    if [[ $1 =~ ^[0-9]+$ ]]; then
        echo "Error: Incorrect input"
        exit 1
    else
        echo $1
    fi
fi
