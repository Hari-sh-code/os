#include<stdio.h>
struct dir
{
    char name[10];
    int start, length;
}

main()
{
    struct dir f[10];
    int fa[32], n, st,len, i , j;

    for(i=0; i<32; i++){
        fa[i]=-1;
    }

    printf("\nCreate directory: ");
    printf("\nEnter number of files to be loaded: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nEnter the file name: ")l;
        scanf("%s",f[i].name);

        printf("\nEnter starting block: ");
        scanf("%d", &st);

        printf("\nEnter length: ");
        scanf("%d", &len);

        for(j=st; j<(st+len);j++){
            if(fa[j]==-1){
                fa[j]=1;
            }
            else{
                printf("\nBlock not empty. Cannot allocate");
                exit();
            }
        }
        f[i].start = st;
        f[i].length = len;
    }

    printf("\n\nFile\tStart\tLength\n");
    for(i=0; i<n; i++){

        printf("\n%s\t%d\t%d", f[i].name, f[i].start, f[i].length);
    }

    printf("\nDisk allocation\n");
    for(i=0; i<32; i++){

        if(fa[i]==-1){
            continue;
            printf("%d\t",i);
        }
    }

}