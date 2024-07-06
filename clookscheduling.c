#include<stdio.h>
#include<conio.h>

void main()
{
    int qlength;
    int queue[25];
    int cylinders, curposition, lastpos, nextpos;

    int headmovement = 0;
    int i,j,tmp;

    printf("Enter queue length: ");
    scanf("%d",&qlength);

    printf("Enter the queue length: ");
    scanf("%d",&qlength);

    printf("Enter the disk access requests :");
    for(i=0; i<qlength; i++){
        scanf("%d",&queue[i]);

    }

    printf("Enter the current position: ");
    scanf("%d",&curposition);
    printf("Enter the current position: ");
    scanf("%d",&curposition);
    printf("Enter number of cylinders : ");
    scanf("%d",&cylinders);

    for(i=0; i<qlength; i++){
        for(j=0;j<qlength; j++){
            if(qlength[i]<queue[j]){
                tmp = queue[i];
                queue[i] = queue[j];
                queue[j] = tmp;
            }
        }
    }
    cylinders--;

    for(i=0; i<qlength; i++){
        if(queue[i]>curposition){
            lastpos=i-1;
            break;
        }
    }
    headmovement = (queue[qlength-1]-curposition)+(queue[qlength-1]-queue[0])+(queue[lastpos]-queue[0]);

    printf("\nCLOOK Scheduling : Forward move");
    printf("\nTotal head movement = %d",headmovement);

    for(i=0;i<qlength;i++){
        if(queue[i]>curposition){
            nextpos=i;
            break;
        }
    }

    headmovement = curposition+cylinders+(cylinders-queue[nextpos]);
    printf("\nCLOOK Scheduling : Reverse move");
    printf("\nTotal head movement = %d",headmovement);
}
