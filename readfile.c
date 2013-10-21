#include <stdio.h>
#include <stdlib.h>

long getFileSize(FILE*);
char *readAllText(char*);

int main(int argc, char **argv)
{
	char *data = readAllText("node_data.txt");

	puts(data);
	free(data);

	return 0;
}

long getFileSize(FILE *file_ptr)
{
	long size;
	fseek(file_ptr, 0, SEEK_END);
	size = ftell(file_ptr);
	rewind(file_ptr);
	return size;
}

char *readAllText(char * path)
{
	FILE *f = fopen(path, "r");
	int size = getFileSize(f);
	char *buffer = (char*)malloc(sizeof(char) * size + 1);
	fread(buffer, 1, size, f);
	fclose(f);

	return buffer;
}

