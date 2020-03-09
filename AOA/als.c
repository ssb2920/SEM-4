#include<stdio.h>
#define max 10
typedef struct a
{
    int start[max],end[max],c[max][max],ec[max][max][max];
    int asln[max][max],prev[max][max];
    int final,p;
}r;
r ob;

void input(int s,int l) 
{
    int i,j,k;
    for(i=0;i<l;i++)
    {
        printf("Enter the entry cost for line %d : ",i+1);
        scanf("%d",&ob.start[i]);
        printf("Enter the exit cost for line %d : ",i+1);
        scanf("%d",&ob.end[i]);
        for(j=0;j<s;j++)
        {   
            printf("Enter the cost of stage %d of line %d   : ",j+1,i+1);
            scanf("%d",&ob.c[i][j]);
            if(j==s-1)
                break;
            for(k=0;k<l;k++)
            {
                
                if(i==k)
                    ob.ec[i][j][k]=0;
                else
                {
                    printf("Enter the travel cost of stage %d of line %d to next stage of assembly line %d  : ",j+1,i+1,k+1);
                    scanf("%d",&ob.ec[i][j][k]);
                }
            }
        }
    }
    
}

void print(int s,int l,int y,int x)                 //y-> stage no. ,x-> line no.
{
    if(y==0)
    {
        printf("start-%d->(%d)",ob.asln[x][y],ob.c[x][y]);
    }
    else if(y==s)
    {
        print(s,l,y-1,(ob.p)-1);
        printf("-%d->end(%d,%d)",ob.end[x],ob.p,ob.final);
    }
    else
    {
        print(s,l,y-1,(ob.prev[x][y])-1);
        printf("-%d->(%d,%d)",ob.ec[ob.prev[x][y]-1][y-1][x],ob.prev[x][y],ob.c[x][y]);
    }
}


void als(int s,int l)
{
    int i,j,k,minc,minn,prev;
    for(i=0;i<=s;i++)
    {
        for(j=0;j<l;j++)
        {
            if(i==0)
                ob.asln[j][i]=ob.start[j];
            else if(i==s)
                ob.asln[j][i]=ob.asln[j][i-1]+ob.c[j][i-1]+ob.end[j];
            else
            {   
                minc=ob.asln[0][i-1]+ob.c[0][i-1]+ob.ec[0][i-1][j] ;
                prev=1;
                for(k=1;k<l;k++)
                {   
                    minn=ob.asln[k][i-1]+ob.c[k][i-1]+ob.ec[k][i-1][j];
                    if(minc>minn)
                    {
                        minc=minn;
                        prev=k+1;
                    }
                }
                ob.asln[j][i]=minc;
                ob.prev[j][i]=prev;
            }
            
        }
    }
    minc=ob.asln[0][s];
    prev=1;
    for(j=1;j<l;j++)
    {
        if(minc>ob.asln[j][s])
        {
            minc=ob.asln[j][s];
            prev=j+1;
        }
    }
    ob.final=minc;
    ob.p=prev;
    for(i=0;i<l;i++)
    {
        printf("\n");
        for(j=0;j<=s;j++)
        {
            printf("%d ",ob.asln[i][j]);
        }
    }
    for(i=0;i<l;i++)
    {
        printf("\n");
        for(j=0;j<s;j++)
        {
            if(j==0)
                printf("  ");
            else
                printf("%d ",ob.prev[i][j]);
        }
    }
    printf("\n");
    print(s,l,s,ob.p-1);
}

void main()
{
    int i,s,l;
    printf("Enter the number of assembly lines : ");
    scanf("%d",&l);
    printf("Enter the number of stages : ");
    scanf("%d",&s);
    input(s,l);
    als(s,l);

}