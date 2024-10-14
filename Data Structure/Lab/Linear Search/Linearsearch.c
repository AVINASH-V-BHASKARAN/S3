#include <stdio.h>

int main()
{
    int a[50], search, i, found = 0, n;
    printf("Enter the No of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i=0;i<n;i++)
	{
        	scanf("%d", &a[i]);
	}
    printf("Element to be searched: ");
    scanf("%d", &search);
    for (i=0;i<n;i++)
	{
		if (a[i] == search)
		{
            		found = 1;
            		break;
        	}
    	}
	if(found)
	{
		printf("The element was found at position %d\n", i + 1);
	}
	else
	{
        	printf("THE ELEMENT YOU SEARCHED DOESNT EXIST! try again \n");
					
	}
	return 0;
}
	
	
	
