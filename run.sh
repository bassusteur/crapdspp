#!/bin/bash
rm main
g++ main.cpp -o main -lGL -lglfw -lfftw3
echo "done"
sleep 1
./main
