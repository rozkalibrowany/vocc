#!/bin/sh
# $1 - path to binary file
# $2 - path to folder containing installation file
# $3 - binary file name

PATH_BINARY=""
PATH_SOURCE=""
BINARY_FILE=""
TMP_FOLDER="tmp_vocc"
DEV="dev"
INSTALL_STAMP="[install] -"

if [ ! -z $1 ]; then
	PATH_BINARY=$1
	echo "$INSTALL_STAMP path to binary is $1"
else
	echo "$INSTALL_STAMP empty path to binary file! Aborted."
	return 1
fi	

if [ ! -z $2 ]; then
	PATH_SOURCE=$2
	echo "$INSTALL_STAMP path to binary is $2"
else
	echo "$INSTALL_STAMP empty path to source files! Aborted."
	return 1
fi

if [ ! -z $3 ]; then
	BINARY_FILE=$3
	echo "$INSTALL_STAMP binary file is $3"
else
	echo "$INSTALL_STAMP empty binary file name! Aborted."
	return 1
fi	

# go to binary file folder
cd $PATH_BINARY
echo "$INSTALL_STAMP now in folder $PATH_BINARY"

sleep 1s
# remove current binary
if [ -f $BINARY_FILE ]; then
	echo "$INSTALL_STAMP removing old binary $BINARY_FILE ..."
	rm $BINARY_FILE*
fi

sleep 1s

# go to source folder
cd $PATH_SOURCE
echo "$INSTALL_STAMP now in folder $PATH_SOURCE"

# remove old directory
if [ -d $TMP_NAME ]; then
	echo "$INSTALL_STAMP removing old directory..."
	rm -r $TMP_FOLDER*
fi

sleep 1s

# untar source files
echo "$INSTALL_STAMP extracting source files..."
mkdir $TMP_FOLDER && tar -zxvf $BINARY_FILE* -C $TMP_FOLDER

sleep 1s

# remove old files
echo "$INSTALL_STAMP removing old files..."
rm -r $BINARY_FILE*

# go to folder
cd $TMP_FOLDER
echo "$INSTALL_STAMP now in folder $TMP_FOLDER"

# go to dev
cd * && cd $DEV
echo "$INSTALL_STAMP now in folder $DEV"

sleep 1s

# qmake project
qmake "komp"*
echo "$INSTALL_STAMP qmaking project..."

# make 
make -j4

sleep 1s

# copy binary to project folder
cd ../bin 
cp $BINARY_FILE $PATH_BINARY/$BINARY_FILE

sleep 1s

# remove folder
echo "$INSTALL_STAMP removing source..."
cd $PATH_SOURCE && rm -r $TMP_FOLDER

sleep 1s

# go to binary folder
echo "$INSTALL_STAMP executing new application version..."
cd $PATH_BINARY
./$BINARY_FILE &



#mkdir cosik
