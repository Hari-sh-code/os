#include<stdio.h>


int Np, Nr;
int i,j;
int Alloc[5][5], Req[5][5], Avail[5];
int Work[5], Finish[5];

int Find()
{
	int Flag;
	for(i=0; i<Np ; i++)
	{
		Flag = 1;
		if(Finish[i] == 0)
		{

			for(j=0; j<Nr; j++)
				if(Req[i][j]>Work[j])
			Flag = 0;
		
			if(Flag == 1)
				return i;
		}
	}
	return -1;
}

void Update(int P)
{
	for(j=0; j<Nr ; j++)
	
		Work[j] +=Alloc[P][j];
	Finish[P] = 1;
}

void main()
{
	int Pr, count = 0;
	
	
	printf("\nEnter the number of processes: ");
	scanf("%d", &Np);
	
	printf("\nEnter the number of resources: ");
	scanf("%d",&Nr);
	
	printf("\nEnter the availability vector:\n");
	for(i=0; i<Nr; i++)
	{
		scanf("%d",&Avail[i]);
	}
	
	printf("\nEnter the Allocation Matrix:\n");
	for(i=0; i<Np; i++)
		for(j=0; j<Nr; j++)
			scanf("%d", &Alloc[i][j]);
	
	printf("\nEnter the request matrix:\n");
	for(i=0; i<Np;i++)
	{
		for(j=0;j<Nr;j++)
		{
			scanf("%d",&Req[i][j]);
		}

	}
	
	for(i=0; i<Nr; i++)
		Work[i] = Avail[i];
	for(i=0; i<Np; i++)
		for(j=0; j<Nr; j++)
			if(Alloc[i][j]!=0)
				Finish[i] = 0;
	while(1)
	{
		Pr= Find();
		if(Pr!=-1)
		{
			Update(Pr);
			count++;
		}
		if(Pr == -1)
			break;
	}
	if(count == Np)
		printf("\nNo deadlock present");
	else
		printf("\nDeadlock causing processes are: ");
		for(i=0; i<Np; i++)
			if(Finish[i] == 0)
				printf("P%d\t",i);
	
}
		


			
