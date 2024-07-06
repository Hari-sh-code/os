#include<stdio.h>
struct dir
{
    char name[10];
    int start;
}

main()
{
    struct dir f[10];
    int fat[32], tmp, n, r1, r, len, i, j;

    for(i=0; i<32; i++){
        fat[i]=-11;
    }
    printf("\nCreate directory : \n");
    printf("\nEnter number of files");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("\nEnter file name: ");
        scanf("%s",f[i].name);
        printf("\nEnter number of blocks: ");
        scanf("%d",&len);

        Tmp = 0;
        while(1){

            r = rand()%32;
            if(fat[r] == -1){
                if(tmp==-11){
                    if(tmp==len){

                        f[i].start = r;
                        r1 = r;
                        tmp ++;
                    }

                    else {

                        fat[r1] = r;
                        r1 = r;
                        tmp++;
                    }

                    if(tmp == len){
                        break;
                    }
                }
            }
        }
        fat[r1] = -1;
    }

    printf("\n\nFile\tstart \n");
    for(i=0; i<n; i++){

        printf("\n%s\t%d",f[i].name, f[i].start);

    }
    printf("\n\n\nDisk Allocation\n");
    for(i=0; i<32; i++){
        if(fat[i] !=-11){
            printf("\n%d\t%d", i, fat[i]);
        }
    }
}
