//optimal replacement algorithm
#include<stdio.h>
int main()
{
	int i, j, k, Num, Pos;
	int Fault=0, Flag=0, Fsize;
	int N, Pg[25];
	int Fr[]={-1,-1,-1,-1,-1}, Dist[]={100,100,100,100,100};
	printf("\nEnter total number of pages: ");
		scanf("%d",&N);
	printf("\nEnter sequence: ");
	for(i=0;i<N;i++)
		scanf("%d",&Pg[i]);
	printf("\nEnter frame size:");
		scanf("%d",&Fsize);
	printf("\n***OPTIMAL Page Replacement Algorithm **\n");
	for(i=0;i<N;i++)
	{
		Flag=0;
		Num=Pg[i];
		Pos=0;
		for(j=0;j<Fsize;j++)
			if(Num==Fr[j])
			{
				Pos=j;
				Flag=1;
				break;
			}
		if(Flag==0)
		{
			Fault++;
			for(j=1;j<Fsize;j++)
				Pos=(Dist[Pos]>=Dist[j]?Pos:j);
			Fr[Pos]=Num;
		}
		Flag=0;
		for(j=i+1;j<N;j++)
			if(Pg[j]==Num)
			{
				Dist[Pos]=j;
				Flag=1;
				break;
			}
		if(Flag==0)
			Dist[Pos]=100;
		printf("\n%d ->\t", Num);
		for(j=0;j<Fsize;j++)
			printf("%d\t", Fr[j]);
	}
	printf("\nTotal number of faults = %d \n\n", Fault);
}

