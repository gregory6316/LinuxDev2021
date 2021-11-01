INFILE="infile.txt"
OUTFILE="outfile.txt"
TEXTFILE="text.txt"
#test if program works correctly
cp $TEXTFILE $INFILE
./move $INFILE $OUTFILE
cmp $TEXTFILE $OUTFILE

#Test if infile open failed(not exists)
cp $TEXTFILE $INFILE
strace -e fault=openat:when=3:error=ENOENT ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 3 ]; then
	echo "Test if infile open failed(not exists) not passed"
	exit -1
fi && rm -f $OUTFILE 

#Test if infile open failed(no access)
cp $TEXTFILE $INFILE
strace -e fault=openat:when=3:error=EACCES ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 3 ] || [ ! -f $INFILE ]; then
	echo "Test if infile open failed(no access) not passed"
	exit -1
fi && rm -f $OUTFILE
  
#Test if outfile open failed(no access)
cp $TEXTFILE $INFILE
strace -e fault=openat:when=4:error=EACCES ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 4 ] || [ ! -f $INFILE ]; then
	echo "#Test if outfile open failed(no access) not passed"
	exit -1
fi && rm -f $OUTFILE 

#Test if closing outfile failed
cp $TEXTFILE $INFILE
strace -e fault=close:when=3:error=EPERM ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 8 ] || [ ! -f $INFILE ]; then
	echo "Test if closing outfile failed not passed"
	exit -1
fi && rm -f $OUTFILE

#Test if deleting outfile failed after read fail
cp $TEXTFILE $INFILE
strace -e fault=read:when=3:error=EPERM -e fault=unlink:when=1:error=EACCES  ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 10 ] || [ ! -f $INFILE ]; then
	echo "Test if deleting outfile failed after read fail not passed"
	exit -1
fi && rm -f $OUTFILE

#Test if deleting infile failed
cp $TEXTFILE $INFILE
strace -e fault=unlink:when=1:error=EACCES ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 7 ] || [ ! -f $INFILE ]; then
	echo "Test if deleting infile failed not passed"
	exit -1
fi && rm -f $OUTFILE 

#Test using same files
cp $TEXTFILE $INFILE
./move $INFILE $INFILE 2> /dev/null
if [ $? -ne 2 ] || [ ! -f $INFILE ]; then
	echo "Test using same files not passed"
	exit -1
fi && rm -f $OUTFILE

#Test if reading infile failed
cp $TEXTFILE $INFILE
strace -e fault=read:when=3:error=EPERM ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 5 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "Test if reading infile failed not passed"
	exit -1
fi && rm -f $OUTFILE

#Test if writing in outfile failed
cp $TEXTFILE $INFILE
strace -e fault=write:when=1:error=EPERM ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 6 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "Test if writing in outfile failed not passed"
	exit -1
fi && rm -f $OUTFILE

#Test with protected infile
cp $TEXTFILE PROTECT_infile.txt 
LD_PRELOAD=`pwd`/PROTECT.so ./move PROTECT_infile.txt $OUTFILE 2> /dev/null
if [ $? -ne 7 ] || [ ! -f PROTECT_infile.txt ] || [ -f $OUTFILE ]; then 
	echo "Test with protected infile not passed"
	exit -1
fi && rm -f $OUTFILE

echo "All tests passed succesfully!"


rm -rf $INFILE $OUTFILE
