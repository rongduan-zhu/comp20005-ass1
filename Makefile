CC=gcc
CFLAGS=-Wall -ansi -c
LINKERS=-lm

all: executable

executable: main helper polygon
	$(CC) main.o helper.o polygon.o -o main.exe $(LINKERS)

main:
	$(CC) $(CFLAGS) main.c

helper:
	$(CC) $(CFLAGS) helper.c

polygon:
	$(CC) $(CFLAGS) polygon.c

clean:
	rm *o *exe
