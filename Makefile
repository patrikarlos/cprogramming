CC=gcc
CCFLAGS=-Wall
LDFLAGS=
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

all: $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3)  $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) $(TARGET13) $(TARGET14) $(TARGET15) $(TARGET16) $(TARGET17)

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



%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

init:
	dd bs=1024 count=1024 if=/dev/urandom of=randfile
	echo "hello world! " > foobar
