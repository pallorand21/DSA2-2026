#include <stdio.h>

#include "hegymaszas.h"
#include "../hegymaszas/functions.h"

int paroszamjegyek(int n, int *paros);


int main(void) {
    //REKURZIV PAROS SZAMJEGYEK SZAMA
    /*int n;
    int paros=0;
    printf("Szam: "); scanf("%d", &n);
    paroszamjegyek(n, &paros);
    printf("Paros: %d\n", paros);*/
    int a[50][50];
    int n,m;

    beolvasas(a, &n, &m, "labirintus.txt");
    kiiras(a,n,m);
    int L = 0;
    backtracing_hegymaszas(a,n,m,0,0,1,&L);
    printf("%d",L);



    return 0;
}

int paroszamjegyek(int n, int *paros) {
    int r;
    r = n % 10;
    if ( r % 2 == 0 ) {
        *paros += 1;
    }
    n /= 10;
    if ( n != 0) {
        paroszamjegyek(n, paros);
    }
}