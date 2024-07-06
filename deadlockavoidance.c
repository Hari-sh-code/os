#include<stdio.h>
#include<stdlib.h>



void main()
{

    int Max[10][10], Need[10][10], Alloc[10][10], Avail[10], Finish[10], SafeSequence[10];
    int p,r,i,j,process,count;
    count = 0;

    printf("Enter the no of processes: ");
    scanf("%d",&p);

    for(i=0; i<p;i++)
        Finish[i] = 0;

    printf("\n\nEnter the no of resources: ");
    scanf("%d",&r);

    printf("\n\nEnter the Max Matrix for each process: ");
    for(i=0; i<p;i++)
    {
        printf("\nFor process %d: ",i+1);
        for(j=0; j<r; j++)
            scanf("%d",&Max[i][j]);
    }
    
    printf("\n\nEnter the allocation for each process: ");
    for(i=0;i<p;i++)
    {
    	printf("\nFor process %d: ",i+1);
    	for(j=0;j<r;j++)
    		scanf("%d",&Alloc[i][j]);
    }
    
    printf("\n\nEnter the available resources: ");
    for(i=0;i<r;i++)
    	scanf("%d",&Avail[i]);
    
    for(i=0;i<p;i++)
    
    	for(j=0;j<r;j++)
    
    		Need[i][j]=Max[i][j] - Alloc[i][j];
    
    do
    {
    	process = -1;
    	
    	for(i=0;i<p;i++)
    	{
    		if(Finish[i] == 0)
    		{
    			process = i;
    			for(j = 0; j < r; j++) 
    			{
                		if(Avail[j] < Need[i][j])
                		{
                			process = -1;
                			break;
                		}
                	}
     		}
    	
    		if (process != -1)
    			break;
    	}
    	if(process != -1)
    	{
    		printf("\n Process P%d runs to completion!",process);
    		SafeSequence[count] = process;
    		count++;
    		for(j=0; j<r; j++)
    		{
    			Avail[j] += Alloc[process][j];
    			Alloc[process][j] = 0;
    			Max[process][j] = 0;
    			Finish[process] = 1;
    		}
    		continue;
    	}
     
     }while(count != p && process != -1);
    	
     if(count == p){
     	printf("\nThe system is in a safe state!!\n");
    	printf("Safe Sequence: <");
    	for(i=0; i<p; i++)
    		printf("P%d", SafeSequence[i]);
    	printf(">\n");
     }
     else
     {
    	printf("\nThe system is in an unsafe state!!");
     }
    
     
}




