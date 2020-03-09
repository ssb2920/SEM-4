#include<stdio.h>
#define max 10

void find(int a[max][2] ,int n,int m)
{
	int k,l,c,i,t=0,w,f[n][2],v[n+1][m+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=m;w++)
			v[i][w]=0;
	}
	for(i=0;i<n+1;i++)
	{
		for(w=0;w<m+1;w++)
		{	
			if(i==0 || w==0)
				v[i][w]=0;
			else
			{
				if(a[i-1][1]>w)
					v[i][w]=v[i-1][w];
				else if(a[i-1][1]<=w)
				{	
					c=a[i-1][0]+v[i-1][(w-a[i-1][1])];
					if(v[i-1][w]>c)
						v[i][w]=v[i-1][w];
					else
						v[i][w]=c;
				}
			}
		}
	}
	printf("\nThe matrix for knapsack problem is:\n  ");
	for(l=0;l<=m;l++)
		printf("%d ",l);
	for(k=0;k<=n;k++)
	{
		printf("\n%d ",k);
		for(l=0;l<=m;l++)
			printf("%d ",v[k][l]);
	}
	i=n;
	w=m;
	k=0;
	while(i!=0 && w!=0)
	{
		if(v[i][w]!=v[i-1][w])
		{
		    f[k][0]=a[i-1][0];
		    f[k++][1]=a[i-1][1];
		    w-=a[i-1][1];
			i--;
		}
		else
			i--;
	}
	printf("\nThe final items in bag:\nitem val weight");
    for(i=0;i<k;i++)
    {
        printf("\n %d  %d   %d",i+1,f[i][0],f[i][1]);
        t+=f[i][0];
    }
	printf("\n The total profit is %d",t);
}

void main()
{
	int n,i,m,a[max][2];
	printf("\nEnter the limit:");
	scanf("%d",&m);
	printf("\nEnter the number of items: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the %d item's value: ",i+1);
		scanf("%d",&a[i][0]);
		printf("\nEnter the %d item's weight:",i+1);
		scanf("%d",&a[i][1]);
	}
	printf("\nitem val weight");
	for(i=0;i<n;i++)
	{
		printf("\n %d  %d   %d",i+1,a[i][0],a[i][1]);
	}
	find(a,n,m);
}