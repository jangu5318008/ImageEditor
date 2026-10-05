#!/bin/bash

PROGNAME="ImageEditor"
BYTELIMIT=4096
PROG="./${PROGNAME}"
SCRIPTHOME=$(ls -d ~/instructor/classes/*/ | head -n 1)

SCORE=0
TOTAL=16

if [ $# -gt 0 ]; then
	USERNAME="$1"
else
	USERNAME="$USER"
fi

echo
echo "Hello, thank you for the tasty code NOM NOM!"
echo

echo "Removing existing object files..."
rm *.o
rm "$PROG"

echo "Overwriting main.cpp.  This will only work for the instructor (ok if it fails)..."
cp ${SCRIPTHOME}main.cpp ./main.cpp

echo "Copying test images..."
cp ${SCRIPTHOME}*.png ./

echo "Testing makefile..."
make

if [ ! -f $PROG ]
then
	echo "Missing ${PROG}.  Unable to run code."
	exit 1
else
	echo "Makefile successfully created ${PROG}."
fi

if [ ! -f "main.o" ] || [ ! -f "ImageEditor.o" ]
then
	echo "Missing main.o or ImageEditor.o.  Aborting."
	exit 1
else
	echo "Makefile successfully created .o files."
fi

echo

timeout 20s "${PROG}" | head -c $BYTELIMIT
SCORE="$(cat score.txt)"

echo
echo "${pwd}"
echo "Score: $SCORE / $TOTAL"
echo
echo

echo "Removing object files..."
rm *.o
rm "$PROG"
rm score.txt

exit $SCORE
