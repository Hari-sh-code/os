#include<stdio.h>

struct dirc{
    char Na_d[10];
    int Num_f;
    char p[10][10];

}d[10];

void create(int n){
    int i;

    printf("\nEnter the name of dir: ");
    scanf("%s",d[n].Na_d);

    printf("\n\tEnter number of files: ");
    scanf("%d",&d[n].Num_f);

    printf("\n\tEnter the names of files: ");
    for(i=0; i<d[n].Num_f;i++){
        printf("\n\t%d - ",i+1);
        scanf("%s",d[n].p[i]);
    }
}

void Display(int N){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n%s - %d",d[i].Na_d,d[i].Num_f);
        for(j=0;j<d[i].Num_f;j++)
            printf("\n\t%s",d[i].p[j]);
    }
}

void main(){
    int Num_d, i;

    printf("\nEnter number of directories: ");
    scanf("%d",&Num_d);

    for(i=0; i<Num_d; i++)
        create(i);

    printf("\nSingle level directory \n");
    Display(Num_d);
}