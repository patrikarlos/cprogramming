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



all: $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3)  $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(TARGET8) $(TARGET9) $(TARGET10)

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


%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
