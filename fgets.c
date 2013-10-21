#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_line();
struct clip *append();

struct clip {
	int views;
	char *user;
	char *id;
	char *title;
	struct clip *next;
} *head;

int main(void)
{
	/*
	char *path = "node_data.txt";
	FILE *f = fopen(path, "r");

	char line[100];

	char *temp;
	while ( (temp = fgets(line, 100, f)) != NULL)
	{
		//puts(temp);
		printf("%s",temp);
	}

	fclose(f);
	*/

	struct clip *c = malloc(sizeof(struct clip));
	struct clip *h;
	char *f[5];
	char *l = "580781,Arnold Schwarzenegger,tBF0YllXKEk,Escape Plan - You Hit Like a Vegetarian";
	split_line(f,l);

	h = append(c, f);
	printf("%s\n", h->id);

	/*
	int i;
	for(i = 0; i < 5; i++)
		printf("%s\n", f[i]);
	*/

	return 0;
}

void split_line(char **fields, char *line)
{
	int i = 0;
	char *token, *delim;
	delim = ",\n";

	char buffer[100];
	strcpy(buffer, line);

	token = strtok(buffer, delim);
	while(token != NULL)
	{
		//printf("%s\n",token);
		fields[i] = malloc(sizeof(char) * strlen(token));
		strcpy(fields[i], token);
		//printf("%s\n", fields[i]);
		token = strtok(NULL, delim);
		i++;
	}
}

struct clip *append(struct clip **hp, char **five)
{
	struct clip *cp, *tp;
	cp = *hp;
	tp = malloc(sizeof(struct clip));

	tp->views = atoi(*five);
	tp->user = malloc(sizeof(char) * strlen(five[1]));
	tp->id = malloc(sizeof(char) * strlen(five[2]));
	tp->title = malloc(sizeof(char) * strlen(five[3]));
	tp->next = NULL;

	strcpy(tp->user,five[1]);
	strcpy(tp->id,five[2]);
	strcpy(tp->title,five[3]);

	//length 0
	if(cp == NULL)
	{
		*hp = tp;
	}
	else {
		while(cp->next != NULL)
		{
			cp = cp->next;
		}
		cp->next = tp;
	}

	return *hp;
}
