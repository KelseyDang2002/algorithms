#!/bin/bash

rm *.o
rm *.out

echo "bash: This is program <algorithms>"

echo "bash: Compiling ds.cpp..."
g++ -c -m64 -Wall -fno-pie -no-pie -std=c++17 -o ds.o ds.cpp

echo "bash: Linking the created object files..."
g++ -m64 -fno-pie -no-pie -std=c++17 -o run.out ds.o

echo "bash: Running program..."
echo ""
./run.out

echo ""
echo "bash: The bash script is now closing..."