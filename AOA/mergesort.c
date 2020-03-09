#include<stdio.h>
#define max 100
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
	mergesort(a,0,n-1);
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}