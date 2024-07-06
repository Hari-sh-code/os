#include<stdio.h>
#include<conio.h>

void main()
{
    int qlength;
    int queue[25];
    int cylinders, curposition;

    int headmovement = 0;
    int i,j;

    printf("Ener queue length: ");
    scanf("%d",&qlength);

    printf("Enter disk access requests: ");
    for(i=0; i<qlength; i++)
        scanf("%d",&queue[i]);

    printf("Enter the current position: ");
    scanf("%d",&curposition);

    //FCFS Scheduling
    for(i=0; i<qlength; i++){
        headmovement+=abs(curposition-queue[i]);
        curposition=queue[i];
    }

    printf("\nFCFS Scheduling: ");
    printf("\nTotal head movement = %d",headmovement);
}