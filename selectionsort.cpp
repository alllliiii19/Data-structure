#include<stdio.h>

void selection(int arr[],int n)
{
	int temp;
	int indexofmin;
	
	for(int i=0;i<n-1;i++)
	{
		indexofmin=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[indexofmin]){
				indexofmin=j;
			}
		}
		temp=arr[indexofmin];
		arr[indexofmin]=arr[i];
		arr[i] = temp;
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
	
	printf("The sorted array is: ");
	print(arr,n);
	printf("\n");
	
	printf("The unsorted array is: ");
	selection(arr,n);
	print(arr,n);
}
