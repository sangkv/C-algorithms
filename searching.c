#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "quicksort.h"

typedef int typeOfData;

int linearSearch(typeOfData A[], const int n, typeOfData x)
{
	for(int i=0;i<n;i++)
	{
		if(A[i] == x)
		{
			return i;
		}
	}
	return -1;
}

int binarySearch(typeOfData A[], const int n, typeOfData x)
{
	int l = 0;
	int r = n-1;
	
	while(l <= r)
	{
		int m = (l+r)/2;
		
		if(A[m] < x)
		{
			l = m+1;
		}
		else if(A[m] > x)
		{
			r = m-1;
		}
		else
		{
			return m;
		}
	}
	
	return -1;
}


int main(int argc, char* argv[])
{
	const int n = 10;
	typeOfData A[] = {9, 8, 7, 2, 4, 5, 3, 7, 1, 6};
	typeOfData x = 3;
	
	/* Linear Search */
	int result1 = linearSearch(A, n, x);
	printf("Result position of linearSearch = %d", result1);
	
	/* Binary Search */
	quickSort(A, 0, n-1); /* sort array */
	int result2 = binarySearch(A, n, x);
	printf("\nResult position of binarySearch = %d", result2);
	
	return 0;
}
