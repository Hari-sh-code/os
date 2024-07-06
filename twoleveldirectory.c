#include <stdio.h>

struct mfd {
    char Na_U[10];
    int Num_d;

    struct ufd {
        char Na_d[10];
        int Num_f;
        char p[10][10];
    } d[10];
} Usr[10];

void create(int n) {
    int i, j;

    printf("\nEnter name of User: ");
    scanf("%s", Usr[n].Na_U);

    printf("\nEnter number of directories for user %s: ", Usr[n].Na_U);
    scanf("%d", &Usr[n].Num_d);

    for (i = 0; i < Usr[n].Num_d; i++) {
        printf("\nEnter name of the dir - %d: ", i + 1);
        scanf("%s", Usr[n].d[i].Na_d);

        printf("\nEnter number of files: ");
        scanf("%d", &Usr[n].d[i].Num_f);

        printf("\n\tEnter names of files: ");
        for (j = 0; j < Usr[n].d[i].Num_f; j++) {
            printf("\n\t\t%d - ", j + 1);
            scanf("%s", Usr[n].d[i].p[j]);
        }
    }
}

void Display(int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        printf("\n<Usr> %s", Usr[i].Na_U);
        for (j = 0; j < Usr[i].Num_d; j++) {
            printf("\n\t%d - %s", j + 1, Usr[i].d[j].Na_d);
            for (k = 0; k < Usr[i].d[j].Num_f; k++) {
                printf("\n\t\t%d - %s", k + 1, Usr[i].d[j].p[k]);
            }
        }
    }
}

int main() {
    int Num_U, i;

    printf("\nEnter number of users: ");
    scanf("%d", &Num_U);

    for (i = 0; i < Num_U; i++) {
        create(i);
    }

    printf("\nTwo level directory\n");
    Display(Num_U);

    return 0;
}
