#! /bin/bash
echo "enter your lucky number"
read num
if [ $num -lt 10 ]
then
echo "you won 1st prize"
elif [ $num -ge 20 ] && [ $num -lt 100 ] 
then 
echo "you won 2 nd prize"
elif [ $num -gt 100 ]
then
echo "lost the game"
fi
