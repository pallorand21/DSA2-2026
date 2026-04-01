//
// Created by pallo on 2026. 03. 28..
//

#ifndef DUNGEON_DUNGEON_H
#define DUNGEON_DUNGEON_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x,y;

}Pont;


void beolvasDungeon(int d[][50],int *n,int *erosites,int *ellenseg,int *boss, const char *input);
void kiirDungeon(int d[][50],int n);
void masol(Pont utmax[],Pont ut[],int k, int *kmax);
//void backtracking_eger(int a[][50], int n, int m,Pont ut[], Pont utmin[], int *kmin,int xs, int ys, int x, int y, int k);
void BTDungeon(int d[][50],int n,int erosites,int ellenseg,int boss,Pont ut[],Pont utmax[],int *kmax,int x,int y,int k, int ero, int *eromax,int latogatott[][50]);
void maxut(int d[][50],Pont utmax[],int kmax);
#endif //DUNGEON_DUNGEON_H
