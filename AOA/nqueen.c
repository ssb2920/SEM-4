#include<stdio.h>
#include<math.h>
#define SIZE 10
int col[SIZE] = {0};
int is_safe(int q,int c)
{	int k;
	for(k=1;k<=q-1;k++)
	{	if(c==col[k]||abs(q-k)==abs(c-col[k]))
			return 0;
	}
	return 1;	
}
void nqueen(int q,int n,int *count)
{	int c,j;
	for(c=1;c<=n;c++)
	{	if(is_safe(q,c)==1)
		{	
			col[q]=c;
			if(q == n)
			{	for(c = 1; c <= n; c++)
				{	for(j=1;j<=n;j++)
					{	if(col[c]!=j)
							printf("-\t");
						else
							printf("Q\t");
					}
					printf("\n");
				}
        		printf("\n\n");
        		*count = *count + 1;
      		}
      		else
				nqueen(q+1, n, count);
    	}	
	}	
}
void main()
{	int n,count=0;
	printf("Enter no. of queens\n");
	scanf("%d",&n);
	nqueen(1,n,&count);
	printf("There are %d solutions\n",count);
}