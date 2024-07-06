//fifo replacement algorithm
#include<stdio.h>
int main()
{
	int i , j, Fault=0, Flag=0;
	int Pos=0, Fsize, N, Num;
	int Pg[25], Fr[]={-1,-1,-1,-1,-1};
	printf("\nEnter total number of pages:");
		scanf("%d",&N);
	printf("\nEnter sequence :");
	for(i=0;i<N;i++)
		scanf("%d",&Pg[i]);
	printf("\nEnter size of page frame :");
		scanf("%d",&Fsize);
	printf("\n***FIFO page Replacement Algorithm ***\n");
	for(i=0;i<N;i++)
	{
		Flag=0;
		Num=Pg[i];

		for(j=0;j<Fsize;j++)
			if(Num==Fr[j])
			{
				Flag=1;
				break;
			}
		if(Flag==0)
		{
			Fr[Pos]=Pg[i];
			Pos=(Pos+1)%Fsize;
			Fault++;
		}

		printf("\n%d  ->",Num);
		for(j=0;j<Fsize;j++)
			printf("\t%d",Fr[j]);
	}
	printf("\nPage Faults = %d\n", Fault);
}

