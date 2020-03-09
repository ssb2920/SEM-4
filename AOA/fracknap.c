#include<stdio.h>
#include<stdlib.h>
 struct mm
{
    float weight,ratio,profit,frac;
    int no;
};
void main()
{
    struct mm  s[10],temp;
    int i,j,n;
    float x,f,tp;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        s[i].no=i+1;
        printf("Enter the weight of item %d: ",i);
        scanf("%f",&s[i].weight);
        printf("Enter the profit of item %d: ",i);
        scanf("%f",&s[i].profit);
        s[i].ratio=s[i].profit/s[i].weight;
        printf("The ratio of profit/weight :%f \n",s[i].ratio);
    }
    printf("Enter the limit : ");
    scanf("%f",&x);
    printf("\n number   weight   ratio \n");
    for(i=0;i<n;i++)
        printf("%d   %f    %f   \n",s[i].no,s[i].weight,s[i].ratio);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(s[j].ratio<s[j+1].ratio)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    printf(" number   weight    ratio  \n");
    for(i=0;i<n;i++)
        printf("%d    %f    %f   \n",s[i].no,s[i].weight,s[i].ratio);
    i=0;
    tp=0;
    while(x!=0)
    {
        if(x>s[i].weight)
        {
            s[i].frac=1;
            x=x-s[i].weight;
            tp=tp+s[i].profit;
            s[i].ratio=tp;
        }
        else if(x<s[i].weight)
        {
            f=x/s[i].weight;
            s[i].frac=f;
            tp=tp+f*s[i].profit;
            s[i].ratio=tp;
            x=0;
        }
        i++;
    }
    printf("number   weight   tp   profit   frac \n");
    for(i=0;i<n;i++)
        printf("%d   %f   %f   %f    %f   \n",s[i].no,s[i].weight,s[i].ratio,s[i].profit,s[i].frac);
    printf("The total profit is : %f",tp);
}