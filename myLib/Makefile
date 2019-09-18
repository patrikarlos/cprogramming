all: static dynamic




myLib.o: myLib.c myLib.h
	gcc -Wall -fPIC -c myLib.c

static: myLib.o
	ar -rc libMy_static.a -o myLib.o

dynamic: myLib.o
	gcc -shared -Wl,-soname,libMy_dynamic.so -o libMy_dynamic.so myLib.o

clean:
	rm *.o *.a *.so
