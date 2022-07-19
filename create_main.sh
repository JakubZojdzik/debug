#!/bin/bash
cp ~/Templates/main.cpp ./
dt=`date +%d-%m-%Y`
sed -i "s/--DATE--/${dt}/" ./main.cpp
