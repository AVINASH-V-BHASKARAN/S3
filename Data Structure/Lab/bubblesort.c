#include<stdio.h>
#include<stdbool.h>
void swap(int* xp,int* yp)
{
	int temp= *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[],int n)
{
	int i,j;
	bool swapped;
	for(i=0;i<n-1;i++)
	{
		swapped = false;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		
	}
}

void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[50],i,j,n;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the elements in array:");
	for(i=0;i<n;i++)
	{
			scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("The Sorted Array: \n");
	printArray(arr,n);
	return 0;
}
