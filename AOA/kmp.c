#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define x 20
int f[x];

void prefixtable(char s[],int m)
{	int i=1,j=0;
	f[0]=0;
	while(i<m)
	{	if(s[i]==s[j])
		{	f[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
			j=f[j-1];
		else
		{	f[i]=0;
			i++;
		}
	}
}

int kmp(char t[],int n,char s[],int m)
{	int i=0,j=0;
	prefixtable(s,m);
	while(i<n)
	{	if(t[i]==s[j])
		{	if(j==m-1)
				return i-j;
			else
			{	i++;
				j++;
			}
		}
		else if(j>0)
			j=f[j-1];
		else
			i++;
	}
	return -1;
}

void main()
{	char sub[x],str[x];
	int m,n;
	printf("Enter string\n");
	gets(str);
	printf("Enter string\n");
	gets(sub);
	n=strlen(str);
	m=strlen(sub);
	if(kmp(str,n,sub,m)!=-1)
		printf("Match Found\n");
	else
		printf("Not Found\n");
	
}