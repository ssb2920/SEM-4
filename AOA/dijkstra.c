#include<stdio.h>
#define max 10 
typedef struct node
{
    int dist,no,pred;
}node;
typedef struct mat
{
    int a[max][max];
    int v[max];
    int nv[max];
    node e[max];
}mat;
void display_mat(mat m,int n)
{
    int i,j;
    printf("The matrix is:");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            if(m.a[i][j]==1000)
                printf("-  ");
            else
                printf("%d  ",m.a[i][j]);
        }
    }
}
mat create_mat(mat m,int n)
{
    int i,j,k,r;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            m.a[i][j]=1000;
    }
    for(i=0;i<n;i++)
    {   while(1)
        {
            printf("\nEnter the number of neighbours of %d:",i+1);
            scanf("%d",&k);
            if(k>n-1)
                printf("\nno. of nodes out of bound.");
            else
                break;
        }
        
        for(j=0;j<k;j++)
        {
            printf("\nEnter the neighbour:");
            scanf("%d",&r);
            if(i+1==r)
            {
                printf("\nThere cannot be loops .");
                j--;
                continue;
            }
            printf("\nEnter the distance:");
            scanf("  %d",&(m.a[i][r-1]));
        }
    }
    return m;
}

void disp(mat m,int n)
{
    int i;
    printf("\nno.   dist   pred");
    for(i=0;i<n;i++)
    {   printf("\n");
        if(m.e[i].pred==-1&&m.e[i].dist==1000)
            printf("%d   -   -",m.e[i].no);
        else if(m.e[i].dist==1000)
            printf("%d   -  %d",m.e[i].no,m.e[i].pred);
        else
            printf("%d  %d  %d",m.e[i].no,m.e[i].dist,m.e[i].pred);
    }
}

int isp(int a[],int n,int x)
{   int i;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
            return 1;
    }
    return 0;
}

void print(mat m,int s)
{
    if(m.e[s-1].pred==-1)
        printf("%d",s);
    else
    {
        print(m,m.e[s-1].pred);
        printf("->%d",s);
    }
}

mat dij(mat m,int n)
{
    int i,j,small,w,k=n-1,c;
    for(i=0;i<n-1;i++)
    {   
        small=m.e[m.nv[0]-1].dist;
        w=m.nv[0];
        for(j=0;j<k;j++)
        {
            if(small>m.e[m.nv[j]-1].dist)
            {
                w=m.nv[j];
                small=m.e[w-1].dist;
            }
        }
        m.v[i+1]=w;                             //adding visited element in visited array
        j=0;
        while(w!=m.nv[j])                       //removing the visited element
            j++;
        for(c=j;c<k;c++)                        
            m.nv[c]=m.nv[c+1];
        k--;
        for(j=0;j<n;j++)                        //finding neighbours
        {
            if(m.a[w-1][j]!=1000 && isp(m.v,i+1,j+1)!=1)
            {
                if(m.e[j].dist>(m.e[w-1].dist+m.a[w-1][j]))
                {
                    m.e[j].dist=(m.e[w-1].dist+m.a[w-1][j]);
                    m.e[j].pred=w;
                    printf("\nchange occured in %d to %d",w,j+1);
                }
                else
                    printf("\nNo change in %d to %d",w,j+1);
            }
        }
        disp(m,n);
    }
    printf("\n Visited Array :\n");
    for(i=0;i<n;i++)                            //printing result
    {
        if(i==n-1)
            printf("%d",m.v[i]);
        else
            printf("%d->",m.v[i]);
    }
    for(i=0;i<n;i++)
        if(i+1!=m.v[0])
        {
            printf("\nThe shortest path from %d to %d : ",m.v[0],i+1);
            print(m,i+1);
        }
    return m;
}

void main()
{
    mat m;
    int n,i,u,k=0;
    printf("\nEnter the number of nodes :");
    scanf("%d",&n);
    m=create_mat(m,n);
    display_mat(m,n);
    printf("\nEnter the source node:");
    scanf("%d",&u);
    for(i=0;i<n;i++)
    {   
        if(i==u-1)
        {
            m.v[0]=u;
            m.e[u-1].no=u;
            m.e[u-1].dist=1000;
            m.e[u-1].pred=-1;
        }
        else
        {
            m.e[i].no=i+1;
            m.e[i].dist=m.a[u-1][i];
            m.e[i].pred=u;
            m.nv[k++]=i+1;
        }
    }
    disp(m,n);
    m=dij(m,n);
}