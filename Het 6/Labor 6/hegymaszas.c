//
// Created by pallo on 2026. 03. 25..
//

#include "hegymaszas.h"

#include <stdio.h>
#include <stdlib.h>

void backtracing_hegymaszas(int a[][50], int n, int m, int x, int y, int k, int *L) {
    if (x == n - 1 && y == m - 1) {
        if (k > *L) {
            *L = k;
        }
        return;
    }

    int aktualismagassag = a[x][y];
    a[x][y] = -1; //-1 jeloli hogy itt mar jartal

    //x = sor; ha noveled lefele mesz ha csokkented felfele
    //y = oszlop; ha noveled jobbra ha csokkented balra
    //n sorok szama   ---keret
    //m oszlopok szama---keret
    //fel
    if (x-1 >= 0 && a[x-1][y] != -1 && a[x-1][y]>=aktualismagassag) {
        backtracing_hegymaszas(a,n,m,x-1,y,k+1,L);
    }
    //jobb
    if (y+1 < m && a[x][y+1] != -1 && a[x][y+1]>=aktualismagassag) {
        backtracing_hegymaszas(a,n,m,x,y+1,k+1,L);
    }
    //le
    if (x+ 1 < n && a[x+1][y] != -1 && a[x+1][y]>=aktualismagassag) {
        backtracing_hegymaszas(a,n,m,x+1,y,k+1,L);
    }
    //bal
    if (y - 1 >= 0 && a[x][y-1] != -1 && a[x][y-1]>=aktualismagassag) {
        backtracing_hegymaszas(a,n,m,x,y-1,k+1,L);
    }
    a[x][y] = aktualismagassag;

}

void beolvasas(int a[][50],int *n, int *m, const char *input) {
    FILE *f = fopen(input,"r");
    if (!f) {
        printf("Sikertelen megnyitas");
        exit(-1);
    }
    fscanf(f,"%d %d ",n,m);
    for (int i=0;i<*n;i++) {
        for (int j=0;j<*m;j++) {
            fscanf(f,"%d",&a[i][j]);
        }
    }
    fclose(f);
}

void kiiras(int a[][50],int n,int m) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

