CC=gcc
CCFLAGS=-Wall -g -pg
LDFLAGS=-pg
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=loops
TARGET1=unlooped
TARGET2=loopcalc
TARGET3=minloopcalc
TARGET4=pointerloop
TARGET5=derefpointerloop
TARGET6=registerloop

all: $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)

$(TARGET): loops.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET1): unlooped.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET2): loopcalc.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET3): minloopcalc.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET4): pointerloop.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET5): derefpointerloop.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET6): registerloop.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<


clean:
	rm -f *.o $(TARGET)

