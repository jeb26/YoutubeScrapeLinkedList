#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DELIMITER ,

struct node {
	int data;
	struct node *next;
};

struct node* create()
{
	//define head pointers
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	//allocate memory
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	//setup fields
	//assign links
	head->data = 15;
	head->next = second;

	second->data = 20;
	second->next = third;

	third->data = 25;
	third->next = NULL;

	return head;
}

int length(struct node *head)
{
	int cnt = 0;
	struct node *current = head;

	while(current != NULL)
	{
		cnt++;
		current = current->next;
	}

	return cnt;
}

void push(struct node** head, int d)
{
	struct node *new_node = malloc(sizeof(struct node));

	new_node -> data = d;
	new_node -> next = *head;

	*head = new_node;
}

struct node *append(struct node **head, int d)
{
	struct node *current = *head;
	struct node *new;

	new = malloc(sizeof(struct node));
	new->data = d;
	new->next = NULL;

	//length 0
	if (current == NULL)
	{
		*head = new;
	}
	else {
		//find last node
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}

int main(int argc, const char *argv[])
{
	int size;
	struct node *head = NULL;

	head = create();	

	push(&head, 67);
	push(&head, 11);
	append(&head, 60);

	size = length(head);

	printf("size of linked list is: %d\n", size);

	struct node *curr = head;
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	return 0;
}
