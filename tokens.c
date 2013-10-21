#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *line = "hoboken,bayonne,syracuse,jersey city";
	char str[255];
	strcpy(str,line);

	char *split, *token;
	split = strtok(str, ",");

	//split = strtok(NULL,",");
	token = split;
	printf("split is: %s token is: %s\n", split, token);
	/*
	while(split != NULL)
	{
		printf("%s\n", split);
		split = strtok(NULL, ",");
	}
	*/

	return 0;
}
