#! /bin/bash
echo "Md5 sample_text.txt" | ./rhasher > rhasher_res.txt
#readline
sed  -i -n '3p' rhasher_res.txt 
md5sum sample_text.txt > md5sum.txt
sed -i 's/ .*//' md5sum.txt
diff rhasher_res.txt md5sum.txt
if [ $? != "0" ]; then
	echo "Md5 sample_text.txt" | ./rhasher > rhasher_res.txt
	#getline
	sed  -i -n '2p' rhasher_res.txt
	diff rhasher_res.txt md5sum.txt
	if [ $? != "0" ]; then
		exit -1;
	fi
fi
echo "Sha1 sample_text.txt" | ./rhasher > rhasher_res.txt
#readline
sed  -i -n '3p' rhasher_res.txt 
sha1sum sample_text.txt > sha1sum.txt
sed -i 's/ .*//' sha1sum.txt
diff rhasher_res.txt sha1sum.txt
if [ $? != "0" ]; then
	#getline
	echo "Sha1 sample_text.txt" | ./rhasher > rhasher_res.txt
	sed  -i -n '2p' rhasher_res.txt
	diff rhasher_res.txt sha1sum.txt
	if [ $? != "0" ]; then
		exit -1;
	fi
fi
echo "All tests passed succesfully!"
rm -rf rhasher_res.txt md5sum.txt sha1sum.txt
