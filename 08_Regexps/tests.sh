#!/bin/bash

TEST=`echo "SAMPLETEXT" | sed -E "s/(SA[m-p]+).*(T[e-x]+)/==\1==\2==/"`
RES=`./esub "SAMPLETEXT" "(SA[m-p]+).*(T[e-x]+)" "==\(1)==\(2)=="`
if [[ $TEST != $RES ]]; then
	exit -1
fi

TEST=`echo "== Var01.field01 ==" | sed -E "s/([[:alnum:].]+)/==\1==/"`
RES=`./esub "== Var01.field01 ==" "([[:alnum:].]+)" "==\(1)=="`
if [[ $TEST != $RES ]]; then
	exit -1
fi

TEST=`echo "TEST to Check Escape symbols" | sed -E "s/(T.*T+)(.t.*k+)/\1\n\t\2/"`
RES=`./esub "TEST to Check Escape symbols" "(T.*T+)(.t.*k+)" "\(1)\n\t\(2)"`
if [[ $TEST != $RES ]]; then
	exit -1
fi

TEST=`echo "TEST to Check NO MATCH" | sed -E "s/(z.*)t/\1\n\t/"`
RES=`./esub "TEST to Check NO MATCH" "(z.*)t" "\(1)\n\t"`
if [[ $TEST != $RES ]]; then
	exit -1
fi



