
#include<stdio.h>
#include<stdlib.h>
#define arrlen 20

void sortprint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void merge(int arr[], int start, int mid, int end)
{
	int ARR[arrlen];
	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			ARR[k++] = arr[i++];
		}
		else
		{
			ARR[k++] = arr[j++];
		}
	}
	//如果i走完了，j还没走完
	if (i == mid + 1)
	{
		while (j <= end)
		{
			ARR[k++] = arr[j++];
		}
	}
	//如果j走完了，i还没走完
	if (j == end + 1)
	{
		while (i <= mid )
		{
			ARR[k++] = arr[i++];
		}
	}
	for (i = start, j = 0; j < k; i++,j++)
	{
		arr[i] = ARR[j];
	}


}

void mergesort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (end + start) / 2;
	mergesort(arr, start, mid);
	mergesort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

int main() {

	int arr[10] = { 3,5,4,1,8,9,6,2,7,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mergesort(arr, 0, size-1);

	sortprint(arr, size);

	return 0;
}