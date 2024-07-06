//LFU replacement algorithm
#include<stdio.h>
int main()
{
	int i,j,k,Num,Pos;
	int Fault=0, Flag=0, Fsize, N;
	int Pg[25],Fr[]={-1,-1,-1,-1,-1},Use[]={0,0,0,0,0};
	printf("\nEnter total number of pages :");
		scanf("%d",&N);
	printf("\nEnter Sequence :");
	for(i=0;i<N;i++)
		scanf("%d",&Pg[i]);
	printf("\nEnter frame size :");
		scanf("%d",&Fsize);
	printf("\n*** LFU Page Replacement Algorithm ***\n");
	for(i=0;i<N;i++)
	{
		Flag=0;
		Num=Pg[i];
		Pos=0;

		for(j=0;j<Fsize;j++)
			if(Fr[j]==-1 || Num==Fr[j])
			{
				Pos=j;
				Fr[Pos]=Num;
				Use[Pos]++;
				Flag=1;
				break;
			}
		if(Flag==0)
		{
			Fault++;
			for(j=1;j<Fsize;j++)
				Pos=(Use[Pos]<=Use[j])?Pos:j;
				Fr[Pos]=Num;
                Use[Pos]=1;
		}
		printf("\n%d ->\t",Num);
		for(j=0;j<Fsize;j++)
			printf("%d\t",Fr[j]);
	}
	printf("\nTotal number of faults = %d \n\n",Fault);
}

