CC=gcc
CFLAGS=-Wall -ansi -c

all: executable

executable: main helper polygon
	gcc main.o helper.o polygon.o -o main.exe

main:
	$(CC) $(CFLAGS) main.c

helper:
	$(CC) $(CFLAGS) helper.c

polygon:
	$(CC) $(CFLAGS) polygon.c

clean:
	rm *o *exe
