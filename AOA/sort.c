#include<stdio.h>
#define max 100
void bubblesort(int a[],int n)
{	int i,j,temp;
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{	if(a[j]>a[j+1])
			{	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}	
		}	
	}
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void insertionsort(int a[],int n)
{	int i,j,temp;
	for(i=1;i<n;i++)
	{	temp=a[i];
		j=i-1;
		while(temp<a[j] && j>=0)
		{ a[j+1]=a[j];
			j--;	
		}
		a[j+1]=temp;
	}
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void selectionsort(int a[],int n)
{	int i, j,min,temp;
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

	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
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
void merge(int a[],int l,int m,int h)
{	int i,j,k,c[h];
	i=l;j=m+1;k=0;
	while(i<=m && j<=h)
	{	if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=m)
		c[k++]=a[i++];
	while(j<=h)
		c[k++]=a[j++];
	for(i=l,k=0;i<=h;i++,k++)
		a[i]=c[k];
}
void mergesort(int a[],int l,int h)
{	int m;
	if(l<h)
	{	m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
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
	bubblesort(a,n);
	insertionsort(a,n);
	selectionsort(a,n);	
	quicksort(a,0,n);
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	mergesort(a,0,n-1);
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}