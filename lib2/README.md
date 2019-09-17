g++ -c mydll.cc
g++ -shared -o mydll.dll mydll.o
But when I type:

g++ -o myprog myprog.cc -L./ -lmydll



## .so will not work on Cygwin, dll will
gcc -c -Wall -Werror -fpic foo.c
#Build shared lib, name it foo.dll
gcc -shared -o foo.dll foo.o
## On Cygwin this links "-lfoo" --> foo.dll
gcc -L. -Wall -o test main.c -lfoo


#Build shared lib, name it libfoo.so
 gcc -shared -o libfoo.so foo.o
 ## On Linux this links "-lfoo" --> libfoo.so
 gcc -L. -Wall -o test main.c -lfoo

https://stackoverflow.com/questions/39136010/cygwin-linking-shared-library
https://medium.com/@Cu7ious/the-power-of-a-book-or-how-to-use-static-libraries-in-c-a20cf26b5483
https://medium.com/@Cu7ious/how-to-use-dynamic-libraries-in-c-46a0f9b98270
https://stackoverflow.com/questions/31421616/c-creating-static-library-and-linking-using-a-makefile
https://stackoverflow.com/questions/12637841/what-is-the-soname-option-for-building-shared-libraries-for
https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html
