GENERATES = prog README *.a *.so prog-a prog-so
TRASH = *.o *~ o.* *.txt

%.o:	%.c
	cc $< -c -o $@

all:	README prog prog-a prog-so

prog:	const.o fun.o prog.o
	cc $^ -o $@

prog-a:	prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@

prog-so:	prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

liboutput_static.a:	const.o fun.o
	ar -rcs $@ const.o fun.o

liboutput.so:	fun.o const.o
	cc -fPIC -c -o const.o const.c
	cc -fPIC -c -o fun.o fun.c
	cc -shared fun.o const.o -o liboutput.so

fun.o:	outlib.h

test_zero:	prog prog-a prog-so
	./prog > prog_0.txt 2> prog_0.txt
	./prog-a > prog_a_0.txt 2> prog_a_0.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so > prog_so_0.txt 2> prog_so_0.txt
	sed 's/prog/<prog_name>/' prog_0.txt > prog_0.txt
	sed 's/prog-a/<prog_name>/' prog_a_0.txt > prog_a_0.txt
	sed 's/prog-so/<prog_name>/' prog_so_0.txt > prog_so_0.txt

test_one:	prog prog-a prog-so
	./prog a > prog_1.txt 2> prog_1.txt
	./prog-a a > prog_a_1.txt 2> prog_a_1.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so a > prog_so_1.txt 2> prog_so_3.txt

test_three:	prog prog-a prog-so
	./prog a b c > prog_3.txt 2> prog_3.txt
	./prog-a a b c > prog_a_3.txt 2> prog_a_3.txt
	$ LD_LIBRARY_PATH=`pwd` ./prog-so a b c > prog_so_3.txt 2> prog_so_3.txt

test:	test_zero test_one test_three
	cmp prog_0.txt prog_a_0.txt
	cmp prog_a_0.txt prog_so_0.txt
	cmp prog_0.txt prog_so_0.txt
	cmp prog_1.txt prog_a_1.txt
	cmp prog_a_1.txt prog_so_1.txt
	cmp prog_1.txt prog_so_1.txt
	cmp prog_3.txt prog_a_3.txt
	cmp prog_a_3.txt prog_so_3.txt
	cmp prog_3.txt prog_so_3.txt

README:	prog
	./$< 2> $@

clean:
	rm -f $(TRASH)

distclean:	clean
	rm -rf $(GENERATES)