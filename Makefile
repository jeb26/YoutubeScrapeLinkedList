OBJS = list tokens readfile
CC = gcc

all: list tokens readfile

readfile:
	$(CC) readfile.c -o readfile

tokens:
	$(CC) tokens.c -o tokens

list:
	$(CC) list.c -o list

clean:
	rm -rf $(OBJS)

