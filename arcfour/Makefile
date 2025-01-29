CC = gcc
CFLAGS = -Wall -O2 -fPIC
TARGET = example
LIB = libarcfour.so

all: $(LIB) $(TARGET)

$(TARGET): example.o
	$(CC) example.o -o $(TARGET) -L. -larcfour $(CFLAGS)

$(LIB): arcfour.o
	$(CC) -shared -o $(LIB) arcfour.o -ldl -D_GNU_SOURCE

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o *.so $(TARGET)
