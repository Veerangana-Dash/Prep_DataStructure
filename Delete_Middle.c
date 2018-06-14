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

void delete(struct Node *head,int key)
{
	struct Node *temp=head,*prev;
	if(temp!=NULL && temp->data==key)
	{
		head=temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}

	if(temp==NULL) return;
	prev->next=temp->next;
	free(temp);
}
void findMiddle(struct Node *head)
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
		delete(head,slow->data);
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
	findMiddle(head);
	printList(head);
	return 0;
}