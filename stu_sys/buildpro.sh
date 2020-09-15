#!/bin/bash

mkdir $1
cd $1
mkdir bin obj include src
touch README.txt Makefile src/Makefile obj/Makefile
