#include<stdio.h>
#include<stdlib.h>

void main()
{
    int qlength;
    int queue[25];
    int cylinders, curposition, lastpos, nextpos;

    int headmovement = 0;
    int i,j,tmp;

    printf("Enter queue length: ");
    scanf("%d",&qlength);

    printf("Enter disk access requests: ");
    for(i=0; i<qlength; i++){
        scanf("%d",&queue[i]);
    }

    printf("Enter current position: ");
    scanf("%d",&curposition);

    printf("Enter number of cylinders: ");
    scanf("%d",&cylinders);

    for(i=0; i<qlength; i++){
        for(j=0; j<qlength; j++){
            if(queue[i]<queue[j]){
                tmp = queue[i];
                queue = queue[j];
                queue[j] = tmp;
            }
        }
    }
    cylinders--;

    for(i=0; i<qlength; i++){
        if(queue[i]>curposition)
            nextpos=i;
            break;
    }

    headmovement = curposition + cylinders + (cylinders-queue[nextpos]);
    printf("\nCSCAN Scheduling : Reverse move");
    printf("\nTotal head movement: %d",headmovement);

}