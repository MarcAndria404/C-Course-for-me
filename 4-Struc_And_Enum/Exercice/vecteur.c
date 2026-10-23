#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Vec2;

typedef struct {
    double x;
    char y;
    char z;
} Vec3;

typedef struct {
    char x;
    double y;
    char z;
} Vec4;

enum Feu {
    ROUGE,
    ORANGE,
    VERT
};

Vec2 somme(Vec2 a, Vec2 b) {
    Vec2 resultat;
    resultat.x = a.x + b.x;
    resultat.y = a.y + b.y;
    return resultat;
}

double produitScalaire(Vec2 a, Vec2 b) {
    return ((a.x * b.x) + (a.y * b.y) );
}

double norme(Vec2 a) {
    return sqrt((a.x * a.x) + (a.y * a.y));
}

void doubler(Vec2 *v) {
    v->x *= 2;
    v->y *= 2;
}

void echanger(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;

}

void feu(enum Feu couleur) {
    switch (couleur) {
        case ROUGE: 
            printf("Le feu est rouge\n");
            break;
        case ORANGE: 
            printf("Le feu est orange\n");
            break;
        case VERT: 
            printf("Le feu est vert\n");
            break;
    }
}

int main() {
    Vec2 a = {5, 10};
    Vec2 b = {15, 20};

    Vec2 c = {25, 30};

    Vec3 e = {5, 'c', 'h'};
    Vec4 f = {'c', 5, 'h'};

    int nbA = 5;
    int nbB = 10;

    printf("Valeur A: %d\nValeur B: %d\n", nbA, nbB);

    echanger(&nbA, &nbB);

    printf("Valeur echanger A: %d\nValeur echanger B: %d\n", nbA, nbB);


    


    Vec2 sumResult = somme(a, b);

    double produitScalaireResult = produitScalaire(a, b);
    double normeResult = norme(a);

    printf("Somme: %.2f, %.2f\nProduit Scalire: %.2f\nNorme: %.2f\n", sumResult.x, sumResult.y, produitScalaireResult,normeResult );
    printf("C: %.2f, %.2f\n", c.x, c.y);
    doubler(&c);
    printf("C Copy: %.2f, %.2f\n", c.x, c.y);

    printf("First: %zu,\nSecond: %zu\n", sizeof(e), sizeof(f));


    feu(ROUGE);

    return 0;
}