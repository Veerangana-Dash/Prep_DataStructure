/*
Duplicate_Removal:
Complete the removeDuplicates() function which takes a list sorted in  
non-decreasing order and deletes any duplicate nodes from the list.
The list should only be traversed once.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void push(struct Node** head,int data)
{
	struct Node* node=(struct Node *)malloc(sizeof(struct Node));
	node->data=data;
	node->next=(*head);
	(*head)=node;
}

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

void printList(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL \n");
}

void removeDuplicate(struct Node *head)
{
	struct Node *temp=head,*ptr=head->next;
	while(temp!=NULL && temp->next!=NULL)
	{
		if(temp->data==ptr->data)
		{
			delete(head,ptr->data);
		}
		temp=temp->next;
		ptr=temp->next;
	}
}

int main()
{
	struct Node* root=NULL;
	push(&root,25);
	push(&root,23);
	push(&root,23);
	push(&root,17);
	push(&root,11);
	push(&root,11);
	push(&root,11);
	printList(root);
	removeDuplicate(root);
	printList(root);
	return 0;
}