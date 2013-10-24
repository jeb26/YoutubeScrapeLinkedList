OBJS = list tokens readfile fgets array_mv
CC = gcc

all: list tokens readfile fgets array_mv

array_mv:
	$(CC) array_mv.c -o array_mv

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

