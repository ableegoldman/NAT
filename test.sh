#!/bin/bash

##
## A simple script to test the NAT program (executable "main")
## Compares the OUTPUT file created by main against a sample file with the expected output
##
##  To run type ./test.sh
##

PROGRAM_OUTPUT="OUTPUT"          # The actual output file created by the NAT program
SAMPLE_OUTPUT="SAMPLE_OUTPUT"    # File containing the expected output of our program


./main

difference=$(diff $PROGRAM_OUTPUT $SAMPLE_OUTPUT)

if [ $? -eq 0 ]
then
    echo "NAT program worked!"
else
    echo "Error in NAT program"
    echo "Output differed from expected:"
    echo "$difference"
fi
