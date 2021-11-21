AM_FLAGS = -Wall -O0 -g

bin_PROGRAMS=esub

esub_SOURCES=esub.c


TESTS=testing.sh

testing.sh:
	cat tests.sh > testing.sh
	chmod +x testing.sh

gitclean:
	git clean -df
