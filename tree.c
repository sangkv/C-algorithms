#include<stdio.h>
#include<stdlib.h>

typedef int typeOfData;

typedef struct
{
	typeOfData data;
	struct node* parent;
	struct node* leftMostChild;
	struct node* rightSibling;
}node;

typedef node* tree;

void initialize(tree* p)
{
	*p = NULL;
}

int isEmpty(tree root)
{
	if(root==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

node* createNode(typeOfData x)
{
	node* p = (node*) malloc(sizeof(node));
	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->parent = NULL;
		p->leftMostChild = NULL;
		p->rightSibling = NULL;
		return p;
	}
}

void insertRoot(tree* ptr_root, node* p)
{
	if(*ptr_root == NULL)
	{
		*ptr_root = p;
	}
}

void insertLeftMostChild(node* N, node* p)
{
	N->leftMostChild = p;
	p->parent = N;
}

void insertRightSibling(node* N, node* p)
{
	N->rightSibling = p;
}

node* returnParent(node* p)
{
	return p->parent;
}

node* returnLeftMostChild(node* p)
{
	return p->leftMostChild;
}

node* returnRightSibling(node* p)
{
	return p->rightSibling;
}

node* returnRoot(node* p)
{
	while(p->parent != NULL)
	{
		p = p->parent;
	}
	return p;
}

typeOfData returnData(node* p)
{
	return p->data;
}

int main(int argc, char* argv[])
{
	/* Khai bao cay */
	tree root;
	
	/* Khoi tao cay */
	initialize(&root);
	
	/* Kiem tra cay rong */
	printf("Tree is empty: %d", isEmpty(root));
	
	/* Insert root */
	typeOfData x = 100;
	node* p = createNode(x);
	if(p != NULL)
	{
		insertRoot(&root, p);
	}
	
	/* Insert leftMostChild */
	node* q = createNode(50);
	if(q != NULL)
	{
		insertLeftMostChild(root, q);
	}
	
	/* Insert rightSibling */
	node* k = createNode(200);
	if(q != NULL)
	{
		insertRightSibling(q, k);
	}
	
	/* Return Root and Root data */
	node* result = returnRoot(q);
	printf("\ndata = %d", returnData(result));
	
	return 0;
}
