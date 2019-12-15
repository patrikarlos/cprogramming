CC=gcc
CCFLAGS=-Wall -g -pg
LDFLAGS=-pg
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=declarators
TARGET1=initialization
TARGET2=numbers
TARGET3=postfix
TARGET4=pointer
TARGET5=pointertopointer
TARGET6=functionpointer
TARGET7=qsorter
TARGET8=binary
TARGET9=useStaticLib
TARGET10=useDynamicLib
TARGET11=llio-open
TARGET12=memTest
TARGET13=llio-scatter
TARGET14=select
TARGET15=asyncio
TARGET16=memAllocation
TARGET17=diyMemory
TARGET18=threads
TARGET19=threads_arguments
TARGET20=threads_stacksize
TARGET21=threads_mutex
TARGET22=threads_cv
TARGET23=threads_scheduling
TARGET24=signal_simplereturn
TARGET25=dataTypes
TARGET26=AVX
TARGET27=asmHW
TARGET28=asmSum

all: $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3)  $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) $(TARGET17) $(TARGET18) $(TARGET19) $(TARGET20) $(TARGET21) $(TARGET22) $(TARGET23) $(TARGET24) $(TARGET25) $(TARGET26) $(TARGET27) $(TARGET28)

$(TARGET): declarators.o	
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET1): initialization.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET2): numbers.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET3): postfix.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET4): pointer.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET5): pointertopointer.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET6): functionpointer.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET7): qsorter.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET8): binary.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET9): useStaticLib.o
	$(CC) -o $@ $^ $(LDFLAGS) -LmyLib/ -lMy_static 

$(TARGET10): useDynamic.o
	$(CC) -o $@ $^ $(LDFLAGS) -LmyLib/ -lMy_dynamic 


useStaticLib.o: useStaticLib.c
	$(CC) -o $@ $^ -c $(LDFLAGS) -ImyLib

useDynamic.o: useStaticLib.c
	$(CC) -o $@ $^ -c $(LDFLAGS) -ImyLib

$(TARGET11): llio-open.o
	$(CC) -o  $@ $^ $(LDFLAGS)

$(TARGET12): deepCsecrets_malloc.o
	$(CC) -o  $@ $^ $(LDFLAGS)

$(TARGET13): llio-scatter.o
	$(CC) -o  $@ $^ $(LDFLAGS)

$(TARGET14): select.o
	$(CC) -o  $@ $^ $(LDFLAGS)

$(TARGET15): asyncio.o
	$(CC) -o $@ $^ $(LDFLAGS) -lrt -lpthread

$(TARGET16): memAllocation.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET17): diyMemory.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET18): threads.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET19): threads_arguments.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET20): threads_stacksize.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET21): threads_mutex.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET22): threads_cv.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET23): threads_scheduling.o
	$(CC) -o $@ $^ $(LDFLAGS) -lpthread

$(TARGET24): signal_simplereturn.o 
	$(CC) -o $@ $^ $(LDFLAGS) 

$(TARGET25): dataTypes.o
	$(CC) -o $@ $^ $(LDFLAGS) 

$(TARGET26): AVX_example.c
	$(CC) -std=c99 -mavx512vl -mtune=skylake -fwrapv -mavx  -ofno-strict-aliasing AVX_example.c -Wpsabi -o AVX_example	

$(TARGET27): helloworld.o
	ld -o $@ $^ 

$(TARGET28): callsum.c sum.s absum.s
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<


%.o: %.asm
	nasm -f elf64 -F stabs $^

clean:
	rm -f *.o $(TARGET)

init:
	dd bs=1024 count=1024 if=/dev/urandom of=randfile
	echo "hello world! " > foobar
