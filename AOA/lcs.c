#include<stdio.h>
#include<string.h>
#define max 100
void main()
{	char a[max],b[max],lcs[max],f[max][max];
	int i,j,r,c,q;
	printf("Enter string 1\n");
	gets(a);
	printf("Enter string 2\n");
	gets(b);
	r=strlen(a);
	c=strlen(b);
	for(i=0;i<r+1;i++)
	{	for(j=0;j<c+1;j++)
		{	f[i][j]=0;
		}
	}
	for(i=1;i<r+1;i++)
	{	for(j=1;j<c+1;j++)
		{	if(a[i-1]==b[j-1])
				f[i][j]=f[i-1][j-1]+1;
			else
			{	if(f[i-1][j]<f[i][j-1])
					f[i][j]=f[i][j-1];
				else if (f[i-1][j]>=f[i][j-1])
					f[i][j]=f[i-1][j];

			}	
		}
	}
	printf("The matrix is\n");
	printf("    ");
	for(q=0;q<c;q++)
		printf("%c ",b[q]);
	for(q=0;q<r+1;q++)
	{	printf("\n");
		if(q>0)
			printf("%c ",a[q-1]);
		else
			printf("  ");
		for(i=0;i<c+1;i++)
			printf("%d ",f[q][i]);
	}
	i=r;j=c;q=0;
	while(i!=0)
	{	if(f[i-1][j]>f[i][j-1])
		{	if(f[i-1][j]!=f[i][j])
			{	lcs[q++]=a[i-1];
				i--;j--;
			}
			else
				i--;	
		}
		else if(f[i-1][j]<=f[i][j-1])
		{	if(f[i][j-1]!=f[i][j])
			{	lcs[q++]=a[i-1];
				i--;j--;
			}
			else
				j--;
		}
	}
	printf("The lcs is %s\n",strrev(lcs));
}