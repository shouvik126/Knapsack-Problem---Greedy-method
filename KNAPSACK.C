#include<stdio.h>
#include<conio.h>
int profit[50],weight[50],max_weight;
void knapsack(int profit[],int weight[],int n)
{
	int i,j;
	float max_profit=0.0,temp,p_w[50],select[50];
	for(i=0;i<n;i++)//calculating per weight profit
	{
		p_w[i]=(profit[i]*1.0)/weight[i];
		select[i]=0;
	}
	for(i=1;i<n;i++)//sorting according to per weight profit
	{
		for(j=0;j<n-i;j++)
		{
			if(p_w[j]<=p_w[j+1])
			{
			 temp=p_w[j];
			 p_w[j]=p_w[j+1];
			 p_w[j+1]=temp;

			 temp=weight[j];
			 weight[j]=weight[j+1];
			 weight[j+1]=temp;

			 temp=profit[j];
			 profit[j]=profit[j+1];
			 profit[j+1]=temp;

			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d,",weight[i]);
	}
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		if(weight[i]<=max_weight)
		{
			select[i]=1.0;
			max_weight-=weight[i];
		}
		else
		{
			select[i]=(max_weight*1.0)/weight[i];
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		max_profit+=(select[i]*profit[i]);
	}
	printf("\nMaximum profit:=%f",max_profit);

}
void main()
{
	int n,i;
	clrscr();
	printf("\tEnter no of object:=");
	scanf("%d",&n);
	printf("Enter profit and weight of all the objects:=");
	for(i=0;i<n;i++)
	{
		printf("\nProfit[%d] :",i+1);
		scanf("%d",&profit[i]);
		printf("\nWeight[%d] :",i+1);
		scanf("%d",&weight[i]);
	}
	printf("\nEnter max weight of knapsack:=");
	scanf("%d",&max_weight);
	knapsack(profit,weight,n);
	getch();
}