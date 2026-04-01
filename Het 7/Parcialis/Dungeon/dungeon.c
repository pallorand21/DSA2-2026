//
// Created by pallo on 2026. 03. 28..
//

#include "dungeon.h"

void beolvasDungeon(int d[][50], int *n, int *erosites, int *ellenseg, int *boss, const char *input) {
    FILE *f = fopen(input,"r");
    if (!f) {
        printf("sikertelen megnyitas");
        exit(-1);
    }

    fscanf(f,"%d",n);
    fscanf(f,"%d %d %d",erosites,ellenseg,boss);

    for (int i=0;i<*n;i++) {
        for (int j=0;j<*n;j++) {
            fscanf(f,"%d",&d[i][j]);
        }
    }
    fclose(f);
}

void kiirDungeon(int d[][50], int n) {
    printf("********MAP********\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}

void masol(Pont utmax[], Pont ut[], int k, int *kmax) {
    for (int i=0;i<=k;i++) {
        utmax[i]=ut[i];
    }
    *kmax=k;
}

void BTDungeon(int d[][50], int n, int erosites, int ellenseg, int boss, Pont ut[], Pont utmax[], int *kmax, int x,
    int y, int k, int ero, int *eromax, int latogatott[][50]) {
    ut[k].x=x;
    ut[k].y=y;

    int ujero = ero;
    if (d[x][y]==2) {ujero += erosites;}
    if (d[x][y]==3) {ujero -= ellenseg;}

    if (ujero==0) {return;}


    if (d[x][y]==9) {
        if (ujero >= boss && ujero > *eromax) {
            *eromax = ujero;
            masol(utmax,ut,k,kmax);
        }
        return;
    }

    latogatott[x][y]=1;

    //fel
    if (x-1 >= 0 && d[x-1][y] != 1 && !latogatott[x-1][y]) {
        BTDungeon(d,n,erosites,ellenseg,boss,ut,utmax,kmax,x-1,y,k+1,ujero,eromax,latogatott);
    }
    //jobbra
    if (y+1 < n && d[x][y+1] != 1 && !latogatott[x][y+1] ) {
        BTDungeon(d,n,erosites,ellenseg,boss,ut,utmax,kmax,x,y+1,k+1,ujero,eromax,latogatott);
    }
    //le
    if (x+1 < n && d[x+1][y] != 1 && !latogatott[x+1][y]) {
        BTDungeon(d,n,erosites,ellenseg,boss,ut,utmax,kmax,x+1,y,k+1,ujero,eromax,latogatott);
    }
    //bal
    if (y-1 >= 0 && d[x][y-1] != 1 && !latogatott[x][y-1]) {
        BTDungeon(d,n,erosites,ellenseg,boss,ut,utmax,kmax,x,y-1,k+1,ujero,eromax,latogatott);
    }

    latogatott[x][y]=0;

}

void maxut(int d[][50],Pont utmax[], int kmax) {
    printf("Lepesek szama: %d\n",kmax);
    for (int i = 0; i <= kmax; i++) {
        printf("%i. lepes: (%d %d)\n ",i,utmax[i].x,utmax[i].y);
        int x = utmax[i].x;
        int y = utmax[i].y;
        if (d[x][y] == 2){ printf("$$EROSITES FELVEVE$$\n");}
        else if (d[x][y] == 3) {printf("$$SEBZEST KAPTAL$$\n");}
        else if (d[x][y] == 9) {printf("$$BOSS LEGYOZVE$$");}
        }
    }


