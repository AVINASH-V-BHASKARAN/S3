#include<stdio.h>
void main()
{
	int i,row1,row2,deg,A[50],B[50],sum[50];
	printf("Enter the degree of polynomial1:");
	scanf("%d",&row1);
	printf("Enter the degree of polynomial2:");
	scanf("%d",&row2);
	for(i=row1;i>=0;i--)
	{
		printf("Enter the coefficient of x^%d of polynomial1:",i);
		scanf("%d",&A[i]);
	}
	for(i=row2;i>=0;i--)
	{
		printf("Enter the coefficient of x^%d of polynomial2:",i);
		scanf("%d",&B[i]);
	}
	deg=(row1>row2)?row1:row2;
	for(i=deg;i>=0;i--)
	{
		sum[i]=A[i]+B[i];
	}
	printf("The sum of the polynomials:");	
	for(i=deg;i>=0;i--)
	{
		printf("%dx^%d+",sum[i],i);
	}
}
