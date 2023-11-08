#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
	struct node *next;
};

struct node *creation(int size)
{
	int item;
	struct node *top, *new_node;
	if (size > 0)
	{
		printf("Enter the value -\n");

		top = (struct node *)malloc(sizeof(struct node));
		top = NULL;
		for (int i = 0; i < size; i++)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &item);
			new_node->data = item;
			new_node->next = top;
			top = new_node;
		}
	}
	return top;
}

void traversel(struct node *topptr)
{
	struct node *curr;
	curr = topptr;
	while (curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->next;
	}
}
int isempty(struct node *topptr)
{
	if (topptr != NULL)
	{
		printf("\nStack is not empty");
		return 0;
	}
	else
	{
		printf("\nStack is empty");
		return 1;
	}
}

struct node *push(struct node *topptr)
{
	struct node *temp;
	int value, n;
	printf("\nHow many  new element you want to push\n");
	scanf("%d", &n);
	if (n > 0)
	{
		printf("enter value\n");
		for (int i = 0; i < n; i++)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &value);
			temp->data = value;
			temp->next = topptr;
			topptr = temp;
		}
	}
	return topptr;
}

struct node *pop(struct node *topptr)
{
	struct node *temp;
	int value, n;
	if (isempty(topptr) == 0)
	{
		printf("\nHow many element you want to pop\n");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp = topptr;
			topptr = topptr->next;
			free(temp);
		}
	}
	else
	{
		printf("\nSorry! There is no element to pop");
	}
	return topptr;
}
void peek(struct node *topptr)
{
	printf("%d is on top of stack\n",topptr->data);
}
int main()
{
	struct node *N;
	int n, option;
	printf("\nHow many elemnet you want in stack-\t");
	scanf("%d", &n);
	N = creation(n);

label:
	printf("\nPress Enter to continue");
	getch();
system("cls");
	printf("\nPress 1 for traversal\n Press 2 to perform push operation\n Press 3 to perform pop operation\n Press 4 to check is stack empty or not\n Press 5 to perform peek operation\nPress 6 to exit\n");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		traversel(N);
		goto label;
		break;
	case 2:
		N = push(N);
		goto label;
		break;
	case 3:
		N = pop(N);
		goto label;
		break;
	case 4:
		isempty(N);
		goto label;
		break;
	case 5:
		peek(N);
		goto label;
		break;
		case 6:
		exit(0);
	default:
		printf(" select valid option");
		goto label;
	}
	return 0;
}