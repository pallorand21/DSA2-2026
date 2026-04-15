#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nev[25];
    int terfogat;
    int ertek;

}Ekszer;


int sort(const void *a , const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {

    int k, n;

    printf("Taska terfogata: ");
    scanf("%d", &k);

    printf("Ekszerek szama: ");
    scanf("%d", &n);

    Ekszer *ekszerek = malloc(n * sizeof(Ekszer));
    if (!ekszerek) {
        fprintf(stderr, "Memoria hiba!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n%d. ekszer neve: ", i + 1);
        scanf("%24s", ekszerek[i].nev);
        printf("   Terfogata:   ");
        scanf("%d", &ekszerek[i].terfogat);
        printf("   Erteke:      ");
        scanf("%d", &ekszerek[i].ertek);
    }







    return 0;
}
