#!/bin/bash

min=$1
max=$2
maxguesses=$3
num=0
count=0
#guess=$(read -p "Guess a number:" num )

number=$( echo ${RANDOM} % ${max} + ${min} | bc )

	while [ ${count} -lt ${maxguesses} ]; do
		read -p "Guess a number:" num
		count=$( echo ${count} + 1 | bc )
		if [ ${num} -ne ${number} ]; then
			echo "try again"

#		echo ${number}
#		echo ${count}
#		echo ${maxguesses}

			if [ ${num} -lt ${number} ]; then
				echo "Guess higher"

			elif [ ${num} -gt ${number} ]; then
				echo "Guess lower"
			fi

		elif [ ${num} -eq ${number} ]; then
			echo "You guessed the number in ${count} tries."
			break

		fi




	done

if [ ${num} -ne ${number} ]; then
	echo "You used too many attempts to guess the number."

fi


#final version

