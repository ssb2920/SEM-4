#include<stdio.h>
#define max 100
void display(int a[],int n)
{	int i;
	printf("\nSorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void bubblesort(int a[],int n )
{	int i,j,temp;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-1;j++)
		{	if(a[j]>a[j+1])
			{	temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	display(a,n);
}
void insertionsort(int a[],int n)
{	int i,j,temp;
	for(i=1;i<n;i++)
	{	temp=a[i];
		j=i;
		while(j>=0 && temp<a[j-1])
		{	a[j]=a[j-1];
			j--;
		}
		temp=a[j];
	}
	display(a,n);	
}
void selectionsort(int a[],int n)
{	int i,j,min,temp;
	for(i=0;i<n;i++)
	{	min=a[i];
		for(j=i+1;j<n;j++)
		{	if(a[j]<min)
			{	temp=a[j];
				a[j]=min;
				min=temp;
			}
		}
	}
	display(a,n);
}
void main()
{	int a[max],n,i;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubblesort(a,n);	
	insertionsort(a,n);
	selectionsort(a,n);
}