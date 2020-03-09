#include<stdio.h>
#define max 10

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
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
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
            printf("There cannot be loops .\n");
            continue;
        }
        printf("Enter the distance:");
        scanf("%d",&r);
        if(a[s-1][d-1]>r)
        {
            a[s-1][d-1]=r;    
            a[d-1][s-1]=r;
            e++;
        }
        else
        {
            printf("The parallel edge is of larger value\n");
        }
    }
    return e;
}

void compute(int a[max][max],int f[max][max],int n)
{
    int b[max],v[max][max],i,j,k=0,g=n,l[n],min,minr,minc,flag,sum=0;
    for(i=0;i<n;i++)
    {
        b[i]=0;
        l[i]=-1;
        for(j=0;j<n;j++)
        {
            v[i][j]=0;
            f[i][j]=1000;
        }
    }
    l[k]=0;
    g--;
    do
    {
        min=a[l[0]][0];
        minr=l[0];
        minc=0;
        flag=0;
        for(i=0;i<=k;i++)
        {   
            for(j=0;j<n;j++)
            {
                if(a[l[i]][j]<min && v[l[i]][j]!=1)
                {   flag=1;
                    min=a[l[i]][j];
                    minc=j;
                    minr=l[i];
                }
            }
        }
        if(flag==1)
        {
            if(b[minr]==0 || b[minc]==0)
            {
                f[minr][minc]=f[minc][minr]=min;
                b[minr]=b[minc]=1;
                printf("\nthe edge %d->%d has weight %d",minr+1,minc+1,min);
                sum+=min;
                v[minc][minr]=v[minr][minc]=1;
                for(i=0;i<n;i++)
                {
                    if(l[i]==-1)
                    {
                        l[i]=minc;
                        k++;
                        g--;
                        break;
                    }
                }
            }
            else
                v[minc][minr]=v[minr][minc]=1; 
        }
    }while(g!=0);
    printf("\nThe total cost of spanning tree is %d",sum);
}

void main()
{
    int r,a[max][max],f[max][max],n,u,k=0;
    printf("Enter the number of vertices :");
    scanf("%d",&n);
    r=create_mat(a,n);
    compute(a,f,n);
}