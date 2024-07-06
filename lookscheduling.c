#include<stdio.h>
#include<stdlib.h>

void main()
{
    int qlength;
    int queue[25];
    int cylinders, curposition;

    int headmovement=0;
    int i,j,tmp;

    printf("Enter the queue length: ");
    scanf("%d",&qlength);

    printf("Enter the disk access requests: ");
    for(i=0;i<qlength;i++){

        scanf("%d",&queue[i]);
    }

    printf("Enter the current position: ");
    scanf("%d",&curposition);

    printf("Enter number of cylinders: ");
    scanf("%d",&curposition);

    for(i=0; i<qlength; i++){
        for(j=0; j<qlength; j++){

            if(queue[i]<queue[j]){
                tmp = queue[i];
                queue[i] = queue[j];
                queue[j] = tmp;
            }
        }
        
    }
    cylinders--;

    headmovement = (queue[qlength - 1] - curposition)+(queue9[qlength-1]-queue[0]);
    printf("\nLook Scheduling; Forward move");
    printf("\nTotal head movement = %d",headmovement);

    headmovement = (curposition - queue[0])+(queue[qlength-1]-queue[0]);
    printf("\nLook Scheduling : Reverse move");
    printf("\nTotal head movement = %d",headmovement);

}