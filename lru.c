//LRU replacement algorithm
#include<stdio.h>
int main()
{
	int i,j,k,Num,Pos;
	int Fault=0, Flag=0, Fsize=0, N, Pg[25];
	// int Pg[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int Fr[]={-1,-1,-1,-1,-1}, Use[]={-1,-1,-1,-1,-1};
	printf("\nEnter total number of pages :");
		scanf("%d",&N);
	printf("\nEnter Sequence :");
	for(i=0;i<N;i++)
		scanf("%d",&Pg[i]);
	printf("\nEnter frame size :");
		scanf("%d",&Fsize);
	printf("\n*** LRU Page Replacement Algorithm ***\n");
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
				Pos=(Use[Pos]<=Use[j])?Pos:j;
			Fr[Pos]=Num;
		}
		Use[Pos]=i;
		printf("\n%d ->\t",Num);
		for(j=0;j<Fsize;j++)
			printf("%d\t",Fr[j]);
	}
	printf("\nTotal number of faults = %d \n\n",Fault);
}


