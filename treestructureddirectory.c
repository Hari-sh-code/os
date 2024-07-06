#include<stdio.h>
#include<stdlib.h>

struct node{
    char N[25];
    int df;
    struct node *pc;
    struct node *ps;
};

struct node *A[20];
int in=0, c=0;

void create(struct node *P, int N){
    int i;
    struct node *Tmp, *T;
    Tmp = P;
    
    for(i=0;i<N;i++){
        T=malloc(sizeof(struct node));
        printf("Enter the name: ");
        scanf("%s",T->N);

        printf("Enter the dir(1) or file(0) : ");
        scanf("%d",&T->df);
        
        if(T->df == 1){
            A[c] = T;
            c++;
        }

        T->pc=NULL;
        T->ps=NULL;

        if(i==0){

            Tmp->pc = T;
            Tmp = T;

        }
        else
        {
            Tmp->ps = T;
            Tmp = T;
        }
    }
}

void display(struct node *P, int level) {
    
    struct node *tmp = P->pc;
    while (tmp != NULL) {
        for (int i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%s(%d)\n", tmp->N, tmp->df);
        if (tmp->df == 1 && tmp->pc != NULL) {
            display(tmp, level + 1);
        }
        tmp = tmp->ps;
    }
}

void main(){
    int nu,nc;
    int i,j,k;
    struct node *Hdr;

    Hdr = malloc(sizeof(struct node));
    Hdr->df = 1;
    Hdr->pc = NULL;
    Hdr->ps = NULL;

    printf("Enter the number of users: ");
    scanf("%d", &nu);

    create(Hdr, nu);

    for(in=0;in<c;in++){
        printf("\nEnter the number of child nodes for %s: ",A[in]->N);
        scanf("%d",&nc);

        create(A[in],nc);
    }
    printf("\nHierarchical\n");
    display(Hdr, 0); 
}