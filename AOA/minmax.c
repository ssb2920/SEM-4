#include<stdio.h>
#include<stdlib.h>
typedef struct mm
{
	int min;
	int max;
}mm;
mm minmax(int a[],int low,int high)
{
	mm l,r,res;
	int mid;
	if(low+high>=0)
	{
		if(low==high)
		{
			res.min=a[low];
			res.max=a[low];
		}
		else if (low+1==high)
		{
			if(a[low]>=a[high])
			{
				res.min=a[high];
				res.max=a[low];
			}
			else
			{
				res.min=a[low];
				res.max=a[high];				
			}
		}
		else
		{
			mid=(low+high)/2;
			l=minmax(a,low,mid);
			r=minmax(a,mid+1,high);
			if(l.min<r.min)
				res.min=l.min;
			else
				res.min=r.min;
			if(l.max>r.max)
				res.max=l.max;
			else
				res.max=r.max;
		}
		
	}
	printf("\nmin=%d max=%d\n",res.min,res.max);
	return res;
}
void main()
{	
	mm res;
	int n,i,a[10];
	printf("Enter the size of the array : ");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		printf("Enter the %d element of the array : ",i+1);
		scanf("%d",&a[i]);
	}
	res=minmax(a,0,n-1);
	printf("\nThe minimum element of array is %d and maximum is %d",res.min,res.max);
}