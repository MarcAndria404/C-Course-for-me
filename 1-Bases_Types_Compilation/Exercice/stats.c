#include <stdio.h>

double moyenne(double tab[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += tab[i];
    }
    return (double) total / n;
}

double variance(double tab[], int n) {
    
}

int main() {
    int x = 10;
    int n = sizeof(x);

    double y = 10.5;
    int m = sizeof(y);

    char c = 'h';
    int l = sizeof(c);

    double tab[8] = {10.0, 15.6, 17.8, 9.80, 5.40, 7.43, 13.50, 10.50};
    int tabSize = sizeof(tab) / sizeof(tab[0]);
    printf("Taille int: %d\nTaille double: %d\nTaille char: %d\nTaille tableau: %d\n", n, m, l, tabSize);
    double avrg = moyenne(tab, tabSize);
    printf("Moyenne: %.2f\n", avrg);
}

