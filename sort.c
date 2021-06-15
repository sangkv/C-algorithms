#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int typeOfData;

void swap(typeOfData* a, typeOfData* b)
{
	typeOfData temp = *a;
	*a = *b;
	*b = temp;
}

/* Selection Sort algorithm */
void selectionSort(typeOfData A[], const int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i] > A[j])
			{
				swap(&A[i], &A[j]);
			}
		}
	}
}

/* Quick Sort algorithm */
int findPivot(typeOfData* p, int left, int right) /* Chọn Pivot: Chọn phần tử có key lớn nhất trong hai phần tử có key khác nhau, kể từ trái qua phải */
{
	int k = left+1;
	typeOfData firstKey = p[left];
	
	while(k<=right && p[k]==firstKey)
	{
		k++;
	}
	
	if(k > right)
	{
		return -1;
	}
	else 
	{
		if(p[k] > firstKey)
		{
			return k;
		}
		else
		{
			return left;
		}
	}
}

int partition(typeOfData* p, int left, int right, typeOfData pivot)
{
	int l = left;  /* l - con nháy trái */
	int r = right; /* r - con nháy phải */
	
	while(l <= r)
	{
		while(p[l] < pivot)  /* l chạy sang phải cho tới khi gặp phần tử có key >= pivot thì dừng */
		{
			l++;
		}
		
		while(p[r] >= pivot) /* r chạy sang trái cho tới khi gặp phần tử có key < pivot thì dừng */
		{
			r--;
		}
		
		if(l < r) /* Thực hiện swap nếu thỏa mãn điều kiện l<r */
		{
			swap(&p[l], &p[r]);
		}
	}
	return l;
}

void quickSort(typeOfData* p, int left, int right)
{
	int pivotIndex = findPivot(p, left, right);
	
	if(pivotIndex != -1)
	{
		typeOfData pivot = p[pivotIndex];
		
		int k = partition(p, left, right, pivot);
		
		quickSort(p, left, k-1);
		quickSort(p, k, right);
	}
}

int main(int argc, char* argv[])
{
	const int n = 10;
	typeOfData A[] = {9, 8, 7, 2, 4, 5, 3, 7, 1, 6};
	typeOfData B[] = {9, 8, 7, 2, 4, 5, 3, 7, 1, 6};
	
	/* Selection Sort */
	selectionSort(A, n);
	for(int i=0;i<n;i++)
	{
		printf("\nA[%d] = %d",i,A[i]);
	}
	
	/* Quick Sort */
	quickSort(B, 0, n-1);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("\nB[%d] = %d",i,B[i]);
	}
	
	
	return 0;
}
