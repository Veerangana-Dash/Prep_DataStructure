/*
Flatten_LL:
Given a linked list where every node represents a linked list and contains two pointers of its type:
(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
All linked lists are sorted.Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *right;
	struct Node *down;
}Node;

void push(struct Node **head,int data)
{
	Node* node=(Node *)malloc(sizeof(Node));
	node->right=NULL;
	node->data=data;
	node->down=(*head);
	(*head)=node;
}

void printList(Node *node)
{
	while(node!=NULL)
	{
		printf("%d",node->data);
		node=node->down;
	}
}

Node* merge(Node *a, Node *b)
{
	//if 1st list is empty
	if(a==NULL)
		return b;
	//if 2nd list is empty
	if(b==NULL)
		return a;

	Node* result;
	if(a->data <b->data)
	{
		result=a;
		result->down=merge(a->down,b);
	}
	else
	{
		result=b;
		result->down=merge(a,b->down);
	}
	return result;
}

Node* flatten(Node *root)
{
	//base case
	if(root==NULL || root->right==NULL)
		return root;
	//merge list with list on right
	return merge(root,flatten(root->right));
}

int main()
{
	Node* root=NULL;
	push(&root,30);
	push(&root,8);
	push(&root,7);
	push(&root,5);
	push(&(root->right),20);
	push(&(root->right),10);
	root=flatten(root);
	printList(root);
	return 0;
}



