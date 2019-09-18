all: static dynamic

foo.o: foo.c foo.h
	gcc -Wall -fPIC -c foo.c

static: foo.o
	ar -rc libfoo_static.a -o foo.o

dynamic: foo.o
	gcc -shared -Wl,-soname,libfoo_dynamic.so -o libfoo_dynamic.so foo.o


main.o: main.c
	gcc -c 

test-stat: foo.o main.c
	gcc -L. -Wall -o test-stat main.c -lfoo_static

test-dynamic: foo.o main.c
	gcc -L. -Wall -o test-stat main.c -lfoo_dynamic

clean:
	rm *.o *.a *.so *.exe
