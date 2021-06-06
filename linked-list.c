#include<stdio.h>
#include<stdlib.h>

typedef int typeOfData;

typedef struct
{
	typeOfData data;
	struct typeOfNode* next;
}typeOfNode;

typedef typeOfNode* NodePtr;

void initialize(typeOfNode** p)
{
	*p = NULL;
}

int isEmpty(typeOfNode* L)
{
	if(L==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void traverse(typeOfNode* L)
{
	if(L==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		typeOfNode* p = L;
		while(p != NULL)
		{
			printf("\ndata = %d",p->data);
			p = p->next;
		}
	}
}

typeOfNode* createNode(typeOfData x)
{
	typeOfNode* p = (typeOfNode*) malloc(sizeof(typeOfNode));
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

void insertHead(typeOfNode** L, typeOfNode* p)
{
	if(*L==NULL)
	{
		*L = p;
	}
	else
	{
		p->next = *L;
		*L = p;
	}
}

void insertTail(typeOfNode** L, typeOfNode* p)
{
	if(*L==NULL)
	{
		*L = p;
	}
	else
	{
		typeOfNode* i = *L;
		while(i->next != NULL)
		{
			i = i->next;
		}
		i->next = p;
	}
}

void insertAfter(typeOfNode** L, typeOfNode* q, typeOfNode* k)
{
	if(*L==NULL)
	{
		*L = k;
	}
	else
	{
		k->next = q->next;
		q->next = k;
	}
}

void editNode(typeOfNode* p, typeOfData x)
{
	p->data = x;
}

void deleteNode(typeOfNode** L, typeOfNode* p)
{
	if(*L==NULL)
	{
		printf("\nList is empty");
	}
	else if(*L==p)
	{
		*L = (*L)->next;
		free(p);
	}
	else
	{
		typeOfNode* q = *L;
		while(q != NULL && q->next != p)
		{
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
}

typeOfNode* searchNode(typeOfNode* L, typeOfData x)
{
	if(L==NULL)
	{
		return NULL;
	}
	else
	{
		typeOfNode* p = L;
		while(p != NULL && p->data != x)
		{
			p = p->next;
		}
		return p;
	}
}


int main(int argc, char* argv[])
{
	/* Khai bao con tro, tro toi danh sach */
	typeOfNode* L;
	
	/* Khoi tao danh sach */
	initialize(&L);
	
	/* Kiem tra danh sanh rong */
	int emp = isEmpty(L);
	printf("List empty is: %d", emp);
	
	/* Duyet danh sach */
	traverse(L);
	
	/* Tao Node */
	typeOfData x = 10;
	typeOfNode* p = createNode(x);
	
	/* Them dau */
	insertHead(&L, p);
	
	/* Them cuoi */
	typeOfData y = 20;
	typeOfNode* q = createNode(y);
	insertTail(&L, q);
	
	/* Them mot phan tu k vao sau mot phan tu nao do */
	typeOfData z = 30;
	typeOfNode* k = createNode(z);
	insertAfter(&L, q, k);
	
	/* Sua gia tri phan tu z trong list */
	typeOfData o = 50;
	editNode(k,o);
	
	/* Xoa phan tu trong list */
	deleteNode(&L, k);
	
	/* Tim kiem phan tu trong danh sach */
	typeOfNode* result = searchNode(L, x);
	printf("\naddress = %d", result);
	
	traverse(L);
	
	
	return 0;
}
