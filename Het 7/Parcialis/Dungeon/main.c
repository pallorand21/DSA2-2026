#include <stdio.h>
#include "dungeon.h"
int main(void) {


    //0 - ut
    //1 - fal
    //2 - erosites
    //3 - ellenseg
    //9 - boss

    int d[50][50];
    int n,erosites,ellenseg,boss;
    int kezdoero = 5;
    beolvasDungeon(d,&n,&erosites,&ellenseg,&boss,"dungeon.txt");
    kiirDungeon(d,n);
    printf("*******************\n");

    Pont utmax[2500],ut[2500];
    int kmax = INT_MIN;
    int eromax=INT_MIN;
    int latogatott[50][50] = {0};
    BTDungeon(d,n,erosites,ellenseg,boss,ut,utmax,&kmax,0,0,0,kezdoero,&eromax,latogatott);

    if (kmax == INT_MIN) {
        printf("Nem sikerult megolni");
    }
    else {
        printf("Sikeres harc: Erod: %d\n",eromax);
        maxut(d,utmax,kmax);
    }


    return 0;
}