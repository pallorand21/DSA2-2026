#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void kombinacio(int *t, int n, int v, int k, char termekek[][25], float arak[], int budget);

bool kombinal(int *t, int k, float arak[], int budget);

void kiir(int *t, int v, char termekek[][25], float arak[], float budget);

int main(void) {
    //mit tudsz vasarolni egy x budgetbol a boltban

    //int n = 5;

    float budget;

    printf("Budget: ");
    scanf("%f", &budget);

    char termekek[][25] = {"Monster White", "Kenyer", "Tojas", "Sajt", "Felvagott"};
    float arak[] = {6.5, 5.0, 10.5, 9.9, 7.15};

    int n = sizeof(arak) / sizeof(arak[0]);


    int *t = (int *) malloc(n * sizeof(int));
    if (!t) {
        printf("Sikertelen foglalas");
        return -2;
    }


    for (int v = 1; v <= n; v++) {
        printf("%d Termek: \n", v);
        kombinacio(t, n, v, 0, termekek, arak, budget);
    }

    free(t);
    return 0;
}

void kombinacio(int *t, int n, int v, int k, char termekek[][25], float arak[], int budget) {
    for (t[k] = 1; t[k] <= n; t[k]++) {
        if (kombinal(t, k, arak, budget)) {
            if (k < v - 1) {
                kombinacio(t, n, v, k + 1, termekek, arak, budget);
            } else {
                kiir(t, v, termekek, arak, budget);
            }
        }
    }
}

bool kombinal(int *t, int k, float arak[], int budget) {
    if (k > 0 && t[k] <= t[k - 1]) {
        return false;
    }

    float jelenlegi = 0;

    for (int i = 0; i <= k; i++) {
        jelenlegi += arak[t[i] - 1];
    }

    if (jelenlegi > budget) {
        return false;
    }

    return true;
}

void kiir(int *t, int v, char termekek[][25], float arak[], float budget) {
    float vegosszeg = 0;

    for (int i = 0; i < v; i++) {
        vegosszeg += arak[t[i] - 1];
    }

    for (int i = 0; i < v; i++) {
        printf("%s | ", termekek[t[i] - 1]);
    }
    float maradek = budget - vegosszeg;
    printf("Osszeg: %.2f | Maradek: %.2f\n", vegosszeg, maradek);
}
