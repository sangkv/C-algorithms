#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef int typeOfElement;

typedef struct
{
	typeOfElement data;
	struct node* next;
}node;

typedef node* position;
typedef node* typeSet;

void initialize(typeSet* A)
{
	*A = NULL;
}

int isEmpty(typeSet A)
{
	if(A==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isMember(typeSet A, typeOfElement x)
{
	while(A != NULL)
	{
		if(A->data == x)
		{
			return 1;
		}
		A = A->next;
	}
	return 0;
}

node* createNode(typeOfElement x)
{
	node* p = (node*) malloc(sizeof(node));
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}

void insertSet(typeSet* A, typeOfElement x)
{
	if(*A == NULL)
	{
		node* p = createNode(x);
		*A = p;
	}
	else
	{
		if(isMember(*A, x) == 0)
		{
			node* p = createNode(x);
			node* q = *A;
			while(q->next != NULL)
			{
				q = q->next;
			}
			q->next = p;
		}
	}
}

void removeSet(typeSet* A, typeOfElement x)
{
	if(*A != NULL)
	{
		if(isMember(*A, x) == 1)
		{
			node* p = *A;
			if(p->data==x)
			{
				*A = p->next;
				free(p);
			}
			else
			{
				node* q = p->next;
				while(q->data != x)
				{
					p = p->next;
					q = p->next;
				}
				p->next = q->next;
				free(q);
			}
		}
	}
}

void traverse(typeSet A)
{
	while(A != NULL)
	{
		printf("\ndata = %d", A->data);
		A = A->next;
	}
}

typeSet unionSet(typeSet A, typeSet B)
{
	typeSet C;
	initialize(&C);
	while(A != NULL)
	{
		insertSet(&C, A->data);
		A = A->next;
	}
	while(B != NULL)
	{
		insertSet(&C, B->data);
		B = B->next;
	}
	return C;
}

typeSet intersection(typeSet A, typeSet B)
{
	typeSet C;
	initialize(&C);
	while(A != NULL)
	{
		if(isMember(B, A->data) == 1)
		{
			insertSet(&C, A->data);
		}
		A = A->next;
	}
	return C;
}

typeSet subtraction(typeSet A, typeSet B)
{
	typeSet C;
	initialize(&C);
	while(A != NULL)
	{
		if(isMember(B, A->data) == 0)
		{
			insertSet(&C, A->data);
		}
		A = A->next;
	}
	return C;
}

int main(int argc, char* argv[])
{
	/* Khai bao tap hop */
	typeSet A;
	
	/* Khoi tao tap hop */
	initialize(&A);
	
	/* Kiem tra tap hop rong */
	printf("Set is empty: %d",isEmpty(A));
	
	/* Them phan tu vao tap hop */
	typeOfElement x = 2;
	insertSet(&A, x);
	insertSet(&A, 4);
	insertSet(&A, 8);
	insertSet(&A, 16);
	insertSet(&A, 32);
	insertSet(&A, 64);
	insertSet(&A, 128);
	insertSet(&A, 32);
	insertSet(&A, 16);
	
	/* Xoa phan tu khoi tap hop */
	typeOfElement y = 32;
	removeSet(&A, y);
	
	/* Duyet tap hop */
	printf("\n\nA = ");
	traverse(A);
	
	/* Set B */
	typeSet B;
	initialize(&B);
	insertSet(&B, 64);
	insertSet(&B, 128);
	insertSet(&B, 512);
	insertSet(&B, 1024);
	insertSet(&B, 2048);
	printf("\n\nB = ");
	traverse(B);
	
	/* Hop cua A va B */
	typeSet C = unionSet(A, B);
	printf("\n\nHop cua A va B:");
	traverse(C);
	
	/* Giao cua A va B */
	typeSet D = intersection(A, B);
	printf("\n\nGiao cua A va B:");
	traverse(D);
	
	/* Hieu cua A va B */
	typeSet E = subtraction(A, B);
	printf("\n\nHieu cua A va B:");
	traverse(E);
	
	return 0;
}
