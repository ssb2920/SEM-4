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

void create_mat(int a[max][max],int seq[max][max],int n)
{
    int i,j,k,r,s,d,e=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                seq[i][j]=1000;
                a[i][j]=0;
            }
            else
            {
                seq[i][j]=j+1;
                a[i][j]=1000;
            }
        }
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
        a[d-1][s-1]=a[s-1][d-1]=r;
    }
}

void sq(int seq[max][max],int n,int i,int j)
{
    int w[n],k=0,l,x=i,y=j;
    while(i!=j)
    {   
        w[k++]=i+1;
        i=seq[i][j]-1;
    }
    w[k]=i+1;
    for(l=0;l<=k;l++)
    {
        if(l==k)
            printf("%d",w[l]);
        else
            printf("%d->",w[l]);
    }
}

void display(int a[max][max],int seq[max][max],int n)
{   
    int i,j,flag[max][max];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            flag[i][j]=0;
        }
    }
    printf("\nSrc   Destn   Dist   Path");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j && flag[i][j]==0)
            {
                printf("\n  %d     %d      %d     ",i+1,j+1,a[i][j]);
                sq(seq,n,i,j);
                flag[i][j]=flag[j][i]=1;
            }
        }
    }
}

void fw(int a[max][max],int seq[max][max],int n)
{
    int k,i,j;
    for(k=0;k<n;k++)
    {   printf("\nIteration %d",k+1);
        for(i=0;i<n;i++)
        {
            if(k!=i)
            {
                for(j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        if(a[i][j]>a[i][k]+a[k][j])
                        {
                            a[j][i]=a[i][j]=a[i][k]+a[k][j];
                            seq[i][j]=seq[j][i]=k+1;
                        }
                    }
                }
            }
        }
        display_mat(a,n);
        display_mat(seq,n);
    }
    
}

void main()
{
    int n,a[max][max],seq[max][max];
    printf("Enter the no. of vertices:");
    scanf("%d",&n);
    create_mat(a,seq,n);
    display_mat(a,n);
    display_mat(seq,n);
    fw(a,seq,n);
    display(a,seq,n);
}