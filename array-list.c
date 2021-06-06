#include<stdio.h>
#include<stdlib.h>

typedef int typeOfItem;

typedef struct
{
	typeOfItem elem[1000]; /* mang chua cac phan tu cua danh sach */
	int size; /* kich thuoc thuc cua danh sach */
}typeOfList;

int isEmpty(const typeOfList* L)
{
	if(L->size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(const typeOfList* L)
{
	if(L->size==1000)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insertAfter(typeOfList* L, int v, typeOfItem x)
{
	if(isEmpty(L)==1)
	{
		L->size++;
		L->elem[L->size-1] = x;
	}
	else if(isFull(L)==0)
	{
		L->size++;
		int i = L->size-1;
		while(i>v+1)
		{
			L->elem[i]=L->elem[i-1];
			i--;
			printf("\n%d", i);
		}
		L->elem[i] = x;
	}
	else
	{
		printf("\nDanh sach day");
	}
}

void insertBefore(typeOfList* L, int v, typeOfItem x)
{
	if(isEmpty(L)==1)
	{
		L->size++;
		L->elem[L->size-1] = x;
	}
	else if(isFull(L)==0)
	{
		L->size++;
		int i = L->size-1;
		while(i>v)
		{
			L->elem[i] = L->elem[i-1];
			i--;
			printf("\n%d",i);
		}
		L->elem[i] = x;
	}
	else
	{
		printf("\nDanh sach day");
	}
}

void delete(typeOfList* L, int v)
{
	if(isEmpty(L)==0)
	{
		for(int i=v;i<L->size-1;i++)
		{
			L->elem[i] = L->elem[i+1];
		}
		L->size--;
	}
	else
	{
		printf("Danh sach rong");
	}
}

void edit(typeOfList* L, int v, typeOfItem x)
{
	if(L->size-1 >= v)
	{
		L->elem[v] = x;
	}
	else
	{
		printf("\nDanh sach co do dai < v");
	}
}

int search(typeOfList* L, typeOfItem k)
{
	if(isEmpty(L)==0)
	{
		for(int i=0;i<=L->size-1;i++)
		{
			if(L->elem[i]==k)
			{
				return i;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	/* Khai bao danh sach */
	typeOfList L;
	
	/* Khoi tao danh sach rong */
	L.size = 0;
	
	/* Chen mot phan tu vao sau vi tri v trong danh sach */
	int v = 10;
	typeOfItem x = 64;
	typeOfItem x1 = 128;
	typeOfItem x2 = 256;
	insertAfter(&L, v, x);
	insertAfter(&L, v, x1);
	insertAfter(&L, v, x2);
	
	/* Chen mot phan tu vao truoc vi tri v trong danh sach */
	insertBefore(&L, v, x);
	
	/* Xoa bo phan tu vi tri v ra khoi danh sach */
	delete(&L, v);
	
	/* Sua phan tu vi tri v trong danh sach */
	edit(&L, v, x);
	
	/* Do dai danh sach */
	int length = L.size;
	printf("\nDo dai danh sach = %d", length);
	
	/* Duyet danh sach */
	for(int i=0;i<=L.size-1;i++)
	{
		typeOfItem y = L.elem[i];
		printf("\nItem %d = %d",i,y);
	}
	
	/* Search k */
	typeOfItem k = 128;
	int result = search(&L, k);
	printf("\nresult = %d", result);
	
	return 0;
}
