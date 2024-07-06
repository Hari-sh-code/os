#include<stdio.h>
#include<stdlib.h>

void main()
{
    int qlength;
    int queue[25];
    int finish[25];
    int cylinders, curposition;

    int headmovement = 0;
    int i,j,diff,min,minpos;

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
        finish[i] = 0;
    }
    //sstf scheduling

    for(j=0; j<qlength; j++){

        min= cylinders;
        minpos = -1;

        //find nearest
        for(i=0; i<qlength; i++){

                if(Finish[i] == 0){

                    diff = abs(curposition-queue[i]);

                    if(min>diff){

                        min = diff;
                        minpos=i;
                    }
                }
        }

        headmovement+=min;
        finish[minpos]= 1;
        curposition = queue[minpos];

    }

    printf("\nSSTF Scheduling: ");
    printf("\nTotal head movement = %d",headmovement);
}