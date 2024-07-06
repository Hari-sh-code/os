#include<stdio.h>
#include<conio.h>

void main()
{
    int qlength;
    int queue[25];
    int cylinders. curposition;

    int headmovement = 0;
    int i, j, tmp;

    printf("Enter queue length: ");
    scanf("%d",&qlength);

    printf("Enter disk access requests: ");
    for(i = 0; i<qlength; i++){
        scanf("%d",&queue[i]);
    }

    printf("Enter current position: ");
    scanf("%d",&curposition);

    printf("Enter number of cylinders :");
    scanf("%d", &cylinders);

    for(j=0; j<qlength; j++){
        if(queue[i]<queue[j]){
            queue[j] = tmp;
        }
    }

    cylinders--;

    printf("\nSCAN Scheduling : Forward move");
    printf("\nTotal head movement = %d", headmovement);

    headmovement=curposition+queue[qlength-1];
    printf("\nSCAN Scheduling : Reverse move");
    printf("\nTotal head movement : %d",headmovement);
    
}