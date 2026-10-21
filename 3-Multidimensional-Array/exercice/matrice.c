#include <stdio.h>

#define LENGTH 2

void printMatrice(int tab[][LENGTH],int n ) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", tab[i][j]);
        }
    }
    printf("\n");
}

int addMatrice(int tab[][LENGTH ], int n) {
    int i, j;
    int sum;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += tab[i][j];
        }
    }
    return sum;
}

int main() {
    int matrice1[2][2] = {{1, 2}, {3, 4}};
    int matrice2[2][2] = {{5, 6}, {7, 8}};

    printMatrice(matrice1, LENGTH);
    printMatrice(matrice2, LENGTH);

    int sum1 = addMatrice(matrice1, LENGTH);
    int sum2 = addMatrice(matrice2, LENGTH);

    printf("Somme 1: %d\nSomme 2: %d\n", sum1, sum2);
    return 0;
}