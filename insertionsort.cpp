#include<stdio.h>

void insertion(int arr[],int n)
{
	int j;
	for(int i=1;i<n;i++)
	{
		int key = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}
void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d",arr[i]);
	}
}

int main()
{
	int arr[5]={5,3,1,6,4};
	int n;
	n = sizeof(arr) / sizeof(arr[0]);
	
	printf("The unsorted array is: ");
	print(arr,n);
	printf("\n");
	
	printf("The unsorted array is: ");
	insertion(arr,n);
	print(arr,n);
}
