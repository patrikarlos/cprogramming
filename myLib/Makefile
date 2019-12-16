ifeq ($(OS),Windows_NT)
	uname_S := Windows
else
	uname_S := $(shell uname -s)
endif



ifeq ($(uname_S),Windows)
	dynTarget=My_dynamic.dll
else
	dynTarget=libMy_dynamic.so
endif

all: static dynamic





myLib.o: myLib.c myLib.h
	gcc -Wall -fPIC -c myLib.c

static: myLib.o
	ar -rc libMy_static.a -o myLib.o

dynamic: myLib.o
	gcc -shared -Wl,-soname,$(dynTarget) -o $(dynTarget) myLib.o

clean:
	rm *.o *.a *.so
