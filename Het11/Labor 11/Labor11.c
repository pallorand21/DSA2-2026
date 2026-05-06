#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define V 7
int mat[V][V];
double ertek[V];


void addEdge(int i, int j){
    mat[i][j]=1;
    mat[j][i]=1;
}

void addErtek(int csomo,double ert){
    ertek[csomo] = ert;
}

void displayMatirx(){
    for(int i = 1; i < V ; ++i){
        for(int j = 1; j < V; ++j ){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void displayErtek(){
    for(int i = 1; i < V ; ++i){
        printf("%d. csomopont erteke: %.2f \n",i,ertek[i]);
    }
}


int main() {
    
    memset(mat,0,sizeof(mat));
    memset(ertek,0,sizeof(mat));


    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,6);
    addEdge(2,3);
    addEdge(2,6);
    addEdge(3,6);
    addEdge(4,5);


    addErtek(1,10);
    addErtek(2,9.5);
    addErtek(3,6);
    addErtek(4,10);
    addErtek(5,8);
    addErtek(6,5);
    
    displayMatirx();
    displayErtek();

    return 0;
}