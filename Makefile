OBJS = list tokens readfile fgets
CC = gcc

all: list tokens readfile fgets

fgets:
	$(CC) fgets.c -o fgets

readfile:
	$(CC) readfile.c -o readfile

tokens:
	$(CC) tokens.c -o tokens

list:
	$(CC) list.c -o list

clean:
	rm -rf $(OBJS)

