set num=23  
echo "hello age is : $(num)"
echo $#
echo $*
echo $0
for day in mon sun thu the
do
	echo $day
done
read keypress
case $keypress in
	[a-z] echo "lowercase"
	[A-Z] echo "uppercase"
	[0-9] echo "digit"
esac
