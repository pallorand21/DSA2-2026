#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PERMUTACIO
/*void BT(int *x, int n, int k);
bool igeretes(int *x, int n, int k);
void kiir(int *x, int n, int k);*/
//PERMUTACIO

//VARIACIO
/*void BT(int *x, int n, int k,int v);
bool igeretes(int *x, int n, int k,int v);
void kiir(int *x, int n, int k,int v);*/
//VARIACIO

//KOMBINACIO
/*void BT(int *x, int n, int k,int v);
bool igeretes(int *x, int n, int k,int v);
void kiir(int *x, int n, int k,int v);*/
//KOMBINACIO

//VERSENY
void BT(int *x, int n, int k,int v,char nevek[][25]);
bool igeretes(int *x, int n, int k,int v,char nevek[][25]);
void kiir(int *x, int n, int k,int v,char nevek[][25]);
//VERSENY



int main(void) {

    //PERMUTACIO
    /*int n;
    printf("n = ?");
    scanf("%d", &n);
    int *x=(int*)malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    BT(x,n,0);*/
    //PERMUTACIO

    //VARIACIO
    /*int n,v;
    printf("n = ?");
    scanf("%d", &n);
    printf("v = ?");
    scanf("%d", &v);

    int *x=(int*)malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    BT(x,n,0,v);*/
    //VARIACIO

    //KOMBINACIO
    /*int n,v;
    printf("n = ?");
    scanf("%d", &n);
    printf("v = ?");
    scanf("%d", &v);

    int *x=(int*)malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    BT(x,n,0,v);*/
    //KOMBINACIO


    //VERSENY
    int n,v;
    char nevek[][25]={"Csiki Gergo", "Darvai Renata" , "Debreceni Zita", "Csegzi Etele", "Barabas Daniel"};
    printf("n = ?");
    scanf("%d", &n);
    printf("v = ?");
    scanf("%d", &v);

    int *x=(int*)malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    BT(x,n,0,v,nevek);


    //VERSENY
    return 0;
}

//PERMUTACIO
/*void BT(int *x, int n, int k) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (igeretes(x, n, k)) {
            if (k < n-1) {
                BT(x, n, k + 1);
            }
            else {
                kiir(x, n, k);
            }
        }

    }
}
bool igeretes(int *x, int n, int k) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) {
            return false;
        }
    }
    return true;
}
void kiir(int *x, int n, int k) {
    for (int i = 0; i < n; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");
}*/
//PERMUTACIO

//VARIACIO
/*void BT(int *x, int n, int k,int v) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (igeretes(x, n, k,v)) {
            if (k < v-1) {
                BT(x, n, k + 1,v);
            }
            else {
                kiir(x, n, k,v);
            }
        }

    }
}
bool igeretes(int *x, int n, int k,int v) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) {
            return false;
        }
    }
    return true;
}
void kiir(int *x, int n, int k,int v) {
    for (int i = 0; i < v; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");
}*/
//VARIACIO

//KOMBINACIO
/*void BT(int *x, int n, int k,int v) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (igeretes(x, n, k,v)) {
            if (k < v-1) {
                BT(x, n, k + 1,v);
            }
            else {
                kiir(x, n, k,v);
            }
        }

    }
}
bool igeretes(int *x, int n, int k,int v) {
    for (int i = 0; i < k; i++) {
        if (x[k] <= x[i]) {
            return false;
        }
    }
    return true;
}
void kiir(int *x, int n, int k,int v) {
    for (int i = 0; i < v; i++) {
        printf("%i ", x[i]);
    }
    printf("\n");
}*/
//KOMBINACIO

//VERSENY
void BT(int *x, int n, int k,int v,char nevek[][25]) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (igeretes(x, n, k,v,nevek)) {
            if (k < v-1) {
                BT(x, n, k + 1,v,nevek);
            }
            else {
                kiir(x, n, k,v,nevek);
            }
        }
    }
}
bool igeretes(int *x, int n, int k,int v,char nevek[][25]) {
    for (int i = 0; i < k; i++) {
        if (x[k] <= x[i] && strcmp(nevek[x[i]],"Darvai Renata")==0) {
            return false;
        }
    }
    return true;
}
void kiir(int *x, int n, int k,int v,char nevek[][25]) {
    for (int i = 0; i < v; i++) {
        printf("%s | ", nevek[x[i]-1]);
    }
    printf("\n");
}