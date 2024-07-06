#include<stdio.h>

struct dir
{
    char name[10];
    int indexblock;
    int ind[8];
}

main(){

    struct dir f[10];
    int fa[32], tmp, n, r1, r, len, i, j;

    for(i=0; i<32; i++){

        fa[i]=-1;
    }

    printf("\nCreate directory: \n");
    printf("\nEnter the number of files to be loaded: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){

        printf("\nEnter the file name: ");
        scanf("%s", f[i].name);

        printf("\nEnter the number of blocks: ");
        scanf("%d",&len);
        
        while (1){

            r = rand()%32;
            if(fa[r]==-1){
                fa[r]=-10;
                f[i].indexblock = r;
                for(j=0;j<8;j++)
                    f[i].ind[j]=-1;
                tmp=0;
                break;
            }
        }

        while(1){

            r = rand()%32;
            if(fa[r]==-1){
                fa[r]=i;
                f[i].ind[tmp]=r;
                tmp++;
                if(tmp==len){
                    break;
                }
            }
        }
    }

    printf("\n\nFile\t index block\n");
    for(i=0; i<n; i++)
        printf("\n%s\t%d",f[i].name, f[i].indexblock);

    printf("\n\n\nIndex blocks \n");
    for(i=0; i<n; i++){
        printf("\nIndex block: %d\n", f[i].indexblock);
        for(j=0; j<8; j++){
            printf("\t%d\n",f[i].ind[j]);
            
        }
    }
}