#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int index;
	float w;
	struct node* next;
}node;

typedef int typeOfData;

typedef struct
{
	typeOfData data;
	node* next;
}vertex;

typedef struct
{
	vertex elem[100]; /* Mang chua toi da 100 dinh cua graph */
	int size; /* So dinh thuc te cua graph */
}graph;

void initialize(graph* p)
{
	p->size = 0;
}

int isEmpty(graph G)
{
	if(G.size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(graph G)
{
	if(G.size == 100)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int sizeOfGraph(graph G)
{
	return G.size;
}

vertex createVertex(typeOfData x)
{
	vertex V;
	V.data = x;
	V.next = NULL;
	return V;
}

void addVertex(graph* p, vertex V)
{
	if(isFull(*p) == 0)
	{
		p->size++;
		p->elem[p->size-1] = V;
	}
	else
	{
		printf("\nList is full!!!");
	}
}

void addEdge(vertex* p, int indexVertex, float weight)
{
	node* edge = (node*) malloc(sizeof(node));
	if(edge != NULL)
	{
		edge->index = indexVertex;
		edge->w = weight;
		edge->next = NULL;
		if(p->next == NULL)
		{
			p->next = edge;
		}
		else
		{
			node* ptr = p->next;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = edge;
		}
	}
}

void searchVertex(vertex V)
{
	node* p = V.next;
	if(p==NULL)
	{
		printf("\nKhong ke voi dinh nao");
	}
	else
	{
		while(p != NULL)
		{
			printf("%d ", p->index);
			p = p->next;
		}
	}
}

int main(int argc, char* argv[])
{
	/* Khai bao do thi */
	graph G;
	
	/* Khoi tao do thi rong */
	initialize(&G);
	
	/* Kiem tra do thi rong */
	printf("\nGraph is empty: %d", isEmpty(G));
	
	/* Create vertex */
	typeOfData x = 10;
	vertex V1 = createVertex(x);
	vertex V2 = createVertex(20);
	vertex V3 = createVertex(30);
	vertex V4 = createVertex(40);
	vertex V5 = createVertex(50);
	
	/* Add vertex graph */
	addVertex(&G, V1);
	addVertex(&G, V2);
	addVertex(&G, V3);
	addVertex(&G, V4);
	addVertex(&G, V5);
	
	/* Add edge */
	vertex* p0 = &(G.elem[0]);
	vertex* p1 = &(G.elem[1]);
	vertex* p2 = &(G.elem[2]);
	vertex* p3 = &(G.elem[3]);
	vertex* p4 = &(G.elem[4]);
	
	addEdge(p0, 2, 20.0); /* V1 -> V3 */
	addEdge(p0, 4, 20.0); /* V1 -> V5 */
	addEdge(p1, 0, 20.0); /* V2 -> V1 */
	addEdge(p1, 3, 20.0); /* V2 -> V4 */
	addEdge(p1, 2, 20.0); /* V2 -> V3 */
	addEdge(p2, 4, 20.0); /* V3 -> V5 */
	addEdge(p3, 1, 20.0); /* V4 -> V2 */
	addEdge(p3, 2, 20.0); /* V4 -> V3 */
	addEdge(p4, 0, 20.0); /* V5 -> V1 */
	
	/* Tim cac dinh ke dinh v */
	printf("\nCac dinh ke dinh V0 la: ");
	searchVertex(G.elem[0]);
	
	/* Duyet do thi vo huong lien thong:
	 * 1. Breadth First Search - tim theo chieu rong truoc
	 * 2. Defth First Seach - Tim theo chieu sau truoc
	 * */
	 
	/* Dijkstra algorithm - Tim duong di ngan nhat tu mot dinh toi moi dinh */
	
	
	return 0;
}
