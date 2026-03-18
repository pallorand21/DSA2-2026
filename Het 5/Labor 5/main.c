#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x,y;
}Pont;

void masol(Pont utmin[],Pont ut[],int k, int *kmin);

void backtracking_eger(int a[][50],int n,int m,Pont ut[],Pont utmin[],
    int *kmin,int xs,int ys,int x,int y,int k);

void beolvasas_labirintus(int a[][50],int *n,int *m,const char *input);

void kiir_labirintus(int a[][50],int n, int m);

void kiir_utmin(Pont utmin[],int kmin);


/*void BT(int *x, int n, int k,char szinek[][25],int penznemek[]);
bool igeretes(int *x, int n, int k,char szinek[][25],int penznemek[]);
void kiir(int *x, int n, int k,char szinek[][25],int penznemek[]);*/


int main(void) {
   /* int n;
    printf("n = ");
    scanf("%d", &n);
    char szinek[][25] = {"kek","sarga","zold"};
    int penznemek[]={5,10,20,100,500};

    int S = 225;
    int *x = (int *) malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    BT(x, n, 0,szinek,penznemek);
*/




    return 0;
}











/*
void BT(int *x, int n, int k,char szinek[][25],int penznemek[]) {
    for (x[k] = 0; x[k] <= 1; x[k]++) {
        if (igeretes(x, n, k,szinek,penznemek)) {
            if (k < n - 1) {
                BT(x, n, k + 1,szinek,penznemek);
            } else {
                kiir(x, n, k,szinek,penznemek);
            }
        }
    }
}

bool igeretes(int *x, int n, int k,char szinek[][25],int penznemek[]) {
    for (int i = 0; i < k; i++) {
        //if (x[k] == x[i]) { return false; }
    }
    return true;
}

void kiir(int *x, int n, int k,char szinek[][25],int penznemek[]) {
    for (int i = 0; i < n; i++) {
        printf("%i ", x[i]);
        if (x[i]==1) {
            printf("%s ",szinek[i]);
        }
    }
    printf("\n");
}
*/