#!/bin/bashclearch=0lines=0total=0coord=""while IFS= read -r linedo	len=${#line} 	while [ "$ch" -lt "$len" ]	do		if [ "${line:ch:1}" = "" ] || [ "${line:ch:1}" = " " ] 		then			ch=$(($ch+1))			continue		fi		total=$(($total+1))		coord=`echo ${coord} ${line:ch:1}`		coord=`echo ${coord} ${lines}`		coord=`echo ${coord} ${ch}`		ch=$(($ch+1))	done	ch=0	lines=$(($lines+1))donemax=$linesfor i in `seq "$total" | shuf`do	lines=`echo ${coord} | cut -d' ' -f$((($i-1)*3+2))`	ch=`echo ${coord} | cut -d' ' -f$((($i-1)*3+3))`	p=`echo ${coord} | cut -d' ' -f$((($i-1)*3+1))`	let "colour=$RANDOM % 256"	tput cup "$lines" "$ch" 	echo -e "\e[38;5;${colour}m$p"	if [ "$#" -gt 0 ]  		then sleep "$1"	fidonetput cup "$max" 0echo
