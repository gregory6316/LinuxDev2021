AM_FLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c


TESTS=testing.sh

testing.sh:
	cat tests.sh > testing.sh
	chmod +x testing.sh

gitclean:
	git clean -df
