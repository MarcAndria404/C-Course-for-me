#include <stdio.h>

#define LIGNE_A 2
#define LIGNE_B 2
#define COLONNE_A 2
#define COLONNE_B 2
#define LIGNE_C 3

void printMatrice(int tab[LIGNE_A][COLONNE_A],int n ) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// 2. PRODUIT MATRICIEL GENERALISE EN 2D
void produitMatricielle2D(int A[LIGNE_A][COLONNE_A],int B[LIGNE_A][COLONNE_A], int C[LIGNE_A][COLONNE_A], int l1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < l1; i++) {
        for (j = 0; j < A, B, C, L1, C1, C2 c2; j++) {
             C[i][j] = 0;
            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 2. PRODUIT MATRICIEL GENERALISE EN 3D
void produitMatricielle3D(int m, int l1, int c1, int c2, 
                        int A[m][l1][c1], 
                        int B[m][c1][c2], 
                        int Res[m][l1][c2]) 
{
    // On boucle sur la première dimension (le lot / la profondeur)
    for (int b = 0; b < m; b++) {
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < c2; j++) {
                Res[b][i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    Res[b][i][j] += A[b][i][k] * B[b][k][j];
                }
            }
        }
    }
}

int main() {
    int matrice1[2][2] = {{1, 2}, {3, 4}};
    int matrice2[2][2] = {{5, 6}, {7, 8}};
//  int matrice3[L1][C1];

    int A[2][3][2] = { 
        { {1, 2}, {3, 4}, {5, 6} }, 
        { {7, 8}, {9, 10}, {11, 12} } 
    };
    int B[2][3][2] = { 
        { {1, 2}, {3, 4}, {5, 6} }, 
        { {7, 8}, {9, 10}, {11, 12} } 
    };
    int C[2][3][2] = { 
        { {1, 2}, {3, 4}, {5, 6} }, 
        { {7, 8}, {9, 10}, {11, 12} } 
    };
    //produitMatricielle2D(matrice1, matrice2, matrice3, L1, C1, C2);
    produitMatricielle3D(LIGNE_C, LIGNE_A, COLONNE_A, COLONNE_B, A, B, C);


    for (int b = 0; b < LIGNE_A; b++) {
        printf("Matrice Resultat du lot [%d]: \n", b);
        printMatrice(C[b], LIGNE_A);
    }
    

    return 0;
}