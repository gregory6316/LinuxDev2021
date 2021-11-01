move: move.c
	cc -O0 -o move move.c

lib_prot: PROTECT.c
	cc PROTECT.c -ldl -fPIC -shared -O0 -o PROTECT.so


test: tests.sh move lib_prot
	./tests.sh

clean:
	rm -rf PROTECT.so move infile.txt outfile.txt PROTECT_infile.txt
