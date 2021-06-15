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
		
		if(l < r) /* Thực hiện swap nếu thỏa mãn điều kiện l < r */
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
