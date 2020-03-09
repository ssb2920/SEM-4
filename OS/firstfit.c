#include<stdio.h>
#define max 10
void main()
{	int block[max],process[max],j,m,i,n;
	int allocate[max]={0};
	int visited[max]={0};
	printf("enter no of blocks and processes\n");
	scanf("%d%d",&n,&m);
	printf("Enter blocks\n");
	for(i=0;i<n;i++)
		scanf("%d",&block[i]);
	printf("Enter process\n");
	for(i=0;i<m;i++)
		scanf("%d",&process[i]);
	for ( i = 0; i <m ; i++)
	{	for(j=0;j<n;j++)
		{	if(visited[j] == 0 && block[j] >= process[i])
			{
				allocate[j] = i;
				visited[j] = 1;
				break;
			}
	
		}
	}printf("\nblock no.\tBlock\tProcess no\tprocess\n");
	for(i=0;i<n;i++)
	{	printf("\n%d\t\t%d",i+1,block[i]);	
		if(visited[i]==1)
			printf("\t%d\t\t%d",allocate[i]+1,process[allocate[i]]);
		else
			printf("Not allocated");
	}
}