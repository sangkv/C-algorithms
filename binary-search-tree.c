#include<stdio.h>
#include<stdlib.h>

typedef int typeOfData;

typedef struct
{
	typeOfData key;
	struct node* left;
	struct node* right;
}node;

typedef node* binarySearchTree;

void initialize(binarySearchTree* ptr_T)
{
	*ptr_T = NULL;
}

int isEmpty(binarySearchTree T)
{
	if(T==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void preOrder(binarySearchTree T)
{
	if(T != NULL)
	{
		printf("%d ", T->key);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(binarySearchTree T)
{
	if(T != NULL)
	{
		inOrder(T->left);
		printf("%d ", T->key);
		inOrder(T->right);
	}
}

void postOrder(binarySearchTree T)
{
	if(T != NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		printf("%d ", T->key);
	}
}

node* createNode(typeOfData x)
{
	node* p = (node*) malloc(sizeof(node));
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		p->key = x;
		p->left = NULL;
		p->right = NULL;
		return p;
	}
}

void insertNode(binarySearchTree* ptr_T, typeOfData x)
{
	if(*ptr_T == NULL)
	{
		node* p = createNode(x);
		*ptr_T = p;
	}
	else
	{
		if(x<(*ptr_T)->key)
		{
			insertNode(&(*ptr_T)->left, x);
		}
		else if(x>(*ptr_T)->key)
		{
			insertNode(&(*ptr_T)->right, x);
		}
	}
}

node* searchNode(binarySearchTree T, typeOfData x)
{
	if(T == NULL)
	{
		return NULL;
	}
	else
	{
		if(x < T->key)
		{
			searchNode(T->left, x);
		}
		else if(x > T->key)
		{
			searchNode(T->right, x);
		}
		else
		{
			return T;
		}
	}
}

node* Quick_searchNode(binarySearchTree T, typeOfData x)
{
	node* p = T;
	while(p != NULL)
	{
		if(x == p->key)
		{
			return p;
		}
		else if(x < p->key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return NULL;
}

void removeTree(binarySearchTree T)
{
	if(T != NULL)
	{
		removeTree(T->left);
		removeTree(T->right);
		free(T);
	}
}

int main(int argc, char* argv[])
{
	/* Khai bao cay nhi phan tim kiem */
	binarySearchTree T;
	
	/* Khoi tao cay nhi phan tim kiem */
	initialize(&T);
	
	/* Kiem tra cay rong */
	printf("\nBinary Search Tree is empty: %d", isEmpty(T));
	
	/* Them Node */
	typeOfData A[15]= {25, 15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
	for(int i=0;i<15;i++)
	{
		insertNode(&T, A[i]);
	}
	
	/* Duyet cay */
	printf("\npreOrder = ");
	preOrder(T);
	printf("\ninOrder = ");
	inOrder(T);
	printf("\npostOrder = ");
	postOrder(T);
	
	/* Tim Node co key = x */
	typeOfData x = 35;
	node* p = Quick_searchNode(T, x);
	if(p==NULL)
	{
		printf("\nnot found");
	}
	else
	{
		printf("\nfind");
	}
	
	/* Xoa toan bo cay */
	removeTree(T);
	
	
	return 0;
}
