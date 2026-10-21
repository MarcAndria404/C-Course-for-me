#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LENGTH_NUMBERS 5
#define LENGTH_STARS 2

void fillPlayerNumbers(int playerNumbers[], int taille) {
    
    
    int i, j;
    int nombre;
    int invalide;

    // Demander les numéros du joueur
    for (i = 0; i < taille; i++) {
        do {
            invalide = 0;
            printf("Entrez un nombre (%d/5) : ", i + 1);
            int retour = scanf("%d", &nombre);

            // Verifier que c'est bien un entier
            if (retour != 1) {
                printf("Veuiller entrer un numéros\n");
                // Vider le buffer (caractère non numérique + newline)
                while (getchar() != '\n');
                invalide = 1;
                continue;
            }

            // Verifier si le numero est inferieur ou egale a 0 ou superieur a 50
            if (nombre <= 0 || nombre > 10) {
                printf("Le numéros doit etre compris entre 1 et 10\n");
                invalide = 1;
                continue;
            }

            // Verifiersi le numéro n'est pas deja dans le tableau
            for (j = 0; j < i; j++) {
                if (nombre == playerNumbers[j]) {
                    printf("Ce nombre existe déjà, réessayez,\n");
                    invalide = 1;
                    break;
                }
            }
        } while (invalide); // Boucler tant que invalide;

        playerNumbers[i] = nombre;

    }
}

void fillPlayerStars(int playerStars[], int taille) {
    
    
    int i, j;
    int nombre;
    int invalide;

    // Demander les numéros du joueur
    for (i = 0; i < taille; i++) {
        do {
            invalide = 0;
            printf("Entrez un nombre (%d/%d) : ", i + 1, taille);
            int retour = scanf("%d", &nombre);

            // Verifier que c'est bien un entier
            if (retour != 1) {
                printf("Veuiller entrer un numéros\n");
                // Vider le buffer (caractère non numérique + newline)
                while (getchar() != '\n');
                invalide = 1;
                continue;
            }

            // Verifier si le numero est inferieur ou egale a 0 ou superieur a 12
            if (nombre <= 0 || nombre > 7) {
                printf("Le numéros doit etre compris entre 1 et 7\n");
                invalide = 1;
                continue;
            }

            // Verifiersi le numéro n'est pas deja dans le tableau
            for (j = 0; j < i; j++) {
                if (nombre == playerStars[j]) {
                    printf("Ce nombre existe déjà, réessayez,\n");
                    invalide = 1;
                    break;
                }
            }
        } while (invalide); // Boucler tant que invalide;

        playerStars[i] = nombre;

    }
}

void fillGameNumbers(int gameNumbers[], int taille) {
    srand(time(NULL));
    int i, j;
    int invalide;
    for (i = 0; i < taille; i++) {
        do {
            invalide = 0;
            gameNumbers[i] = (rand() % 10) + 1; // 1 a 50

            for (j = 0; j < i; j++) {
                if (gameNumbers[i] == gameNumbers[j]) {
                    invalide = 1;
                    break;
                }
            }
        } while (invalide);
    }
}

void fillGameStars(int gameStars[], int taille) {
    srand((unsigned) time(NULL));
    int i, j;
    int invalide;
    for (i = 0; i < taille; i++) {
        do {
            invalide = 0;
            gameStars[i] = (rand() % 7) + 1; // 1 a 12

            for (j = 0; j < i; j++) {
                if (gameStars[i] == gameStars[j]) {
                    invalide = 1;
                    break;
                }
            }
        } while (invalide);
    }
}

void printArray(int tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int sameCount(int tab1[], int tab2[], int tabLen) {
    int i,j;
    int sameNbCount = 0;
    // Rechercher les doublon
    for (i = 0; i < tabLen; i++) {
        for (j = 0; j < tabLen; j++) {
            if (tab1[i] == tab2[j]) {
                sameNbCount += 1;
                break;
            }
        }
    }
    return sameNbCount;
}

int main() {
    // Initialisations des variables necessaire au jeu
    int playerNumbers[LENGTH_NUMBERS];
    int playerStars[LENGTH_STARS];
    int gameNumbers[LENGTH_NUMBERS];
    int gameStars[LENGTH_STARS];
    int playerGain = 0;
    bool replay = true;

    do {
    
        // Game Numbers
        fillGameNumbers(gameNumbers, LENGTH_NUMBERS);

        // Game Stars
        fillGameStars(gameStars, LENGTH_STARS);

        // Player Numbers
        printf("Choisissez vos numéros (1 - 10)\n");
        fillPlayerNumbers(playerNumbers, LENGTH_NUMBERS);
        printf("Vos numéros:\n");
        printArray(playerNumbers, LENGTH_NUMBERS);

        // Player Stars
        printf("Choisissez vos étoiles (1 - 7)\n");
        fillPlayerStars(playerStars, LENGTH_STARS);
        printf("Vos Etoiles:\n");
        printArray(playerStars, LENGTH_STARS);

   
        // Nombre d'étoile et de numéros gagnants
        int sameNbCount = sameCount(gameNumbers, playerNumbers, LENGTH_NUMBERS);
        int sameStarsCount = sameCount(gameStars, playerStars, LENGTH_STARS);
        printf("Nombre de numéros correspondants: %d\n", sameNbCount);
        printf("Nombre d'étoiles correspondantes: %d\n", sameStarsCount);

        // Print numeros gagnants:
        printf("Numéro Gagnant:\n");
        printArray(gameNumbers, LENGTH_NUMBERS);

        // Print etoile gagnante
        printf("Etoiles gagnante: \n");
        printArray(gameStars, LENGTH_STARS);

        // Jeu
        if (sameNbCount == 5 && sameStarsCount == 2) {
            printf("JACKPOT !!!\n");
            playerGain += 77777;
        } else if (sameNbCount == 5 && sameStarsCount == 1) {
            printf("Gain très élevé: 50000$\n");
            playerGain += 50000;
        } else if (sameNbCount == 5) {
            printf("Gain Elevé: 10000$\n");
            playerGain += 10000;
        } else if (sameNbCount == 4 && sameStarsCount == 2) {
            printf("Gain Moyen: 1000$\n");
            playerGain += 1000;
        } else if (sameNbCount == 4 && sameStarsCount == 1) {
            printf("Gain plus petit: 300$\n");
            playerGain += 300;
        } else if (sameNbCount == 3 && sameStarsCount == 2) {
            printf("Petit Gain: 50$\n");
            playerGain += 50;
        } else if (sameNbCount == 3 && sameStarsCount == 1) {
            printf("Gain minimal: 20$\n");
            playerGain += 20;
        } else {
            printf("Perdu !!!");
        }

        printf("Votre gain: %d$\n", playerGain);
        char yesorno;
        printf("Rejouer ? (y or n)");
        scanf(" %c", &yesorno);
        if (yesorno == 'y') {
            replay = true;
        } else {
            replay = false;
        }
    } while(replay);

    return 0;
}