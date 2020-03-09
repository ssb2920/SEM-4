#include<stdio.h>
#define max 100
int partition(int a[],int l,int h)
{	int pivot=a[l];
	int i=l;
	int j=h;
	int temp;
	while(i<j)
	{	do{	i++;
		}while(a[i]<=pivot);
		do{j--;
		}while(a[j]>pivot);
		if(i<j)
		{	temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}	
	}
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int l,int h)
{	int j;
	if(l<h)
	{	j=partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}
void main()
{	int a[max],n,i;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);	
	}
	quicksort(a,0,n);
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}