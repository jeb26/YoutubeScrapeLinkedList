#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 100

struct clip *build_a_list();
void split_line();
struct clip *append();
int find_length();
void print_lst();

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
	struct clip *c = malloc(sizeof(struct clip));
	struct clip *h;
	char *f[5];
	char *l = "580781,Arnold Schwarzenegger,tBF0YllXKEk,Escape Plan - You Hit Like a Vegetarian";
	split_line(f,l);

	h = append(c, f);
	printf("%s\n", h->id);

	*/

	int cnt = 0;
	head = build_a_list("node_data.txt");
	cnt = find_length(head);

	printf("%d\n", cnt);


	/*
	int i;
	for(i = 0; i < 5; i++)
		printf("%s\n", f[i]);
	*/

	return 0;
}

struct clip *build_a_list(char *fn)
{
	FILE *fp = fopen(fn, "r");
	struct clip *hp, *final;
	char *fields[4];
	char line[LINE_LENGTH];
	int cnt = 0;
	hp = NULL;

	char *temp;
	while ( (temp = fgets(line, 100, fp)) != NULL)
	{
		split_line(fields, line);
		final = append(&hp, fields);
	}

	fclose(fp);
	return final;
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

int find_length(struct clip *hp)
{
	int cnt = 0;
	struct clip *curr = head;

	while(curr != NULL)
	{
		cnt++;
		curr = curr->next;
	}

	return cnt;
}
