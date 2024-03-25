#!/bin/bash

SRC_PATH="./src" 

gcc "$SRC_PATH/main.c" "$SRC_PATH/input_parse.c" "$SRC_PATH/builtins.c" "$SRC_PATH/core.c" -o main -fsanitize=leak

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    ./main
else
    echo "Error during compilation."
fi
