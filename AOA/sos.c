#include<stdio.h>
#define max 10
int a[max],added[max];
void sos(int sum,int loc,int e,int total,int n)
{   int i;
    if(e==sum)
    {   printf("\nSolution is\n");
        for(i=0;i<n;i++)
        {   if(added[i]==1)
                printf("%d\t",a[i]);
        }
    }
    else if((e+a[loc]<=sum)&&(e+total>=sum))
    {   added[loc]=1;
        sos(sum,loc+1,e+a[loc],total-a[loc],n);
        added[loc]=0;
        sos(sum,loc+1,e,total-a[loc],n);   
    }
}
void main()
{   int i,j,temp;
    int n,sum,total;
    //take input
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the sum : ");
    scanf("%d",&sum);
    total=0;
    //take input with total
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element : ",i);
        scanf("%d",&a[i]);
        total=total+a[i];
    }
    //sort in ascending order
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }//call sos
        sos(sum,0,0,total,n);
}
