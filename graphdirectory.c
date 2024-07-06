#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char N[25];
    int df;
    struct node *Ptr;
};

struct node *A[20];
int in = 0, c = 0;

void display() {
    int i;
    struct node *P;

    for (i = 0; i < c; i++) {
        P = A[i];
        printf("\n%s(%d)", P->N, P->df);
        P = P->Ptr;

        while (P != NULL) {
            printf(" -> %s(%d)", P->N, P->df);
            P = P->Ptr;
        }
    }
}

void DAG() {
    struct node *T, *P, *Tmp;
    int i, j, Flag, nv;

    for (in = 0; in < c; in++) {
        P = A[in];
        printf("\nEnter number of adjacent vertices for %s: ", A[in]->N);
        scanf("%d", &nv);

        for (i = 0; i < nv; i++) {
            T = malloc(sizeof(struct node));
            printf("Enter the name: ");
            scanf("%s", T->N);

            printf("Enter the dir(1) or file(0): ");
            scanf("%d", &T->df);
            T->Ptr = NULL;

            // Link the new node to the current node
            if (P->Ptr == NULL) {
                P->Ptr = T;
            } else {
                struct node *temp = P->Ptr;
                while (temp->Ptr != NULL) {
                    temp = temp->Ptr;
                }
                temp->Ptr = T;
            }

            if (T->df == 1) {
                Flag = 1;
                for (j = 0; j < c; j++) {
                    if (strcmp(A[j]->N, T->N) == 0) {
                        Flag = 0;
                        break;
                    }
                }
                if (Flag == 1) {
                    Tmp = malloc(sizeof(struct node));
                    strcpy(Tmp->N, T->N);
                    Tmp->df = T->df;
                    Tmp->Ptr = NULL;
                    A[c] = Tmp;
                    c++;
                }
            }
        }
    }
}

void create(int N) {
    int i;
    struct node *T;
    for (i = 0; i < N; i++) {
        T = malloc(sizeof(struct node));
        printf("Enter node name : ");
        scanf("%s", T->N);

        printf("Enter the dir(1) or file(0): ");
        scanf("%d", &T->df);

        T->Ptr = NULL;
        A[c] = T;
        c++;
    }
}

int main() {
    int nu;

    printf("Enter the number of nodes: ");
    scanf("%d", &nu);

    create(nu);
    DAG();

    printf("\nDAG - Adjacency list representation\n");
    display();

    return 0;
}
