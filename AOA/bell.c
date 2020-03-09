#include<stdio.h>
#define max 10
typedef struct node
{
    int s,dist,pred;
}N;
typedef struct edge
{
    int s,d;
}E;
void display_mat(int a[max][max],int n)
{
    int i,j;
    printf("\nThe matrix is:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1000)
                printf("-  ");
            else
                printf("%d  ",a[i][j]);
        }
    }
}

int create_mat(int a[max][max],int n)
{
    int i,j,k,r,s,d,e=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=1000;
    }
    printf("Enter the number of edges(loops,edges,parallel edges):");
    scanf("%d",&k);
    for(i=0;i<k;i++)    
    {   
        printf("Enter the source:");
        scanf("%d",&s);
        printf("Enter the destination :");
        scanf("%d",&d);
        if(s==d)
        {
            printf("There cannot be loops .");
            continue;
        }
        printf("Enter the distance:");
        scanf("%d",&r);
        a[s-1][d-1]=r;
        e++;
    }
    return e;
}

void belf(int c,int n,int r,int a[max][max])
{
    int i,j,k=0,flag;
    N n1[max];
    E e[max];
    for(i=0;i<n;i++)
    {
        n1[i].s=i+1;
        n1[i].pred=1000;
        if(i+1==c)
            n1[i].dist=0;
        else
            n1[i].dist=1000;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=1000)
            {
                e[k].s=i+1;
                e[k++].d=j+1;
            }
        }
    }
    for(i=0;i<r;i++)
        printf("\n%d->%d",e[i].s,e[i].d);
    for(i=0;i<n;i++)
    {
        printf("\nnode dist pred");
        for(j=0;j<n;j++)
        {
            if(n1[j].pred!=1000 && n1[j].dist!=1000)
            {
                printf("\n%d %d %d",n1[j].s,n1[j].dist,n1[j].pred);
            }
            else if(n1[j].pred==1000 && n1[j].dist!=1000)
            {
                printf("\n%d %d -",n1[j].s,n1[j].dist);
            }   
            else if(n1[j].pred!=1000 && n1[j].dist==1000)
            {
                printf("\n%d - %d",n1[j].s,n1[j].pred);
            }
        }
        flag=0;
        printf("\nIteration %d",i+1);
        for(j=0;j<r;j++)
        {
            if((n1[(e[j].s)-1].dist+a[e[j].s-1][e[j].d-1])<n1[(e[j].d)-1].dist)
            {
                flag=1;
                n1[(e[j].d)-1].dist=n1[(e[j].s)-1].dist+a[e[j].s-1][e[j].d-1];
                n1[(e[j].d)-1].pred=n1[(e[j].s)-1].s;
            }
        }
        if(i==n-1 && flag==1)
        {
            printf("\nThe graph has a negetive cycle. So No solution");
            break;
        }
        else
        {
           printf("\nFINAL RESULT:");
           for(j=0;j<n;j++)
            {
                if(n1[j].pred!=1000 && n1[j].dist!=1000)
                {
                    printf("\n%d %d %d",n1[j].s,n1[j].dist,n1[j].pred);
                }
                else if(n1[j].pred==1000 && n1[j].dist!=1000)
                {
                    printf("\n%d %d -",n1[j].s,n1[j].dist);
                }   
                else if(n1[j].pred!=1000 && n1[j].dist==1000)
                {
                    printf("\n%d - %d",n1[j].s,n1[j].pred);
                }
            }            
        }
        
    }
}

void main()
{
    int r,c,n,a[max][max];
    printf("Enter the no. of vertices:");
    scanf("%d",&n);
    printf("Enter the source node:");
    scanf("%d",&c);
    r=create_mat(a,n);
    display_mat(a,n);
    belf(c,n,r,a);
}