#/bin/bash
date

# function
find_you()
{
	echo "exec find_you function!"
	echo $1,$2
	return 1
}


find_you hello nihao
echo $?
FUNC_RESULT=`find_you`
echo $FUNC_RESULT

exit
NAME=Sundy
readonly AGE=12+12
echo $NAME $AGE
echo `expr 1 + 2 + 3`
if [ -x helloworld2.sh ]
then
	echo "true"
else
	echo "false"
fi


case $NAME in
"arron")
	echo "arron"
	;;
"sSundy")
	echo "Sundy"
	;;
*)
	echo "Other"
	;;
esac

#loop
for var in 1 2 3
do
	echo $var
done

var2=1
while [ $var2 -lt 10 ]
do
	echo "print $var2"
	var2=$[$var2 + 1]
done

exit
# print new value
VALUE=$[$[12 + 12] * 10]
VALUE2=`expr $VALUE + 12 \* 10`
echo $VALUE
echo $VALUE2

# print $
echo "\$0 = $0"
echo "\$1 = $1" 
echo "\$# = $#"
echo "\$@ = $@"
echo "\$* = $*"
echo "\$$ = $$"

#print env
echo $HOME
echo $PATH
echo $PWD
echo $PS1
