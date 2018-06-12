/*
Middle_of_LL:
Given a singly linked list, find middle of the linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void printMiddle(struct Node *head)
{
	struct Node *slow=head;
	struct Node *fast=head;
	if(head!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		printf("Middle element is %d \n",slow->data);
	}
}

void push(struct Node** head,int data)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->next=(*head);
	(*head)=node;
}

void printList(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL \n");
}

int main()
{
	struct Node* head=NULL;
	int i;
	for(i=6;i>0;i--)
	{
		push(&head,i);
	}
	printList(head);
	printMiddle(head);
	return 0;
}