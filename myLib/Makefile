all: libMy_static.a libMy_dynamic.so


myLib.o: myLib.c myLib.h
	gcc -Wall -fPIC -c myLib.c

libMy_static.a: myLib.o
	ar -rc libMy_static.a -o myLib.o

libMy_dynamic.so: myLib.o
	gcc -shared -Wl,-soname,libMy_dynamic.so -o libMy_dynamic.so myLib.o

clean:
	rm *.o *.a *.so
