#include <stdlib.h>
#include <stdio.h>


int hossz (int szam){
    if (szam==0) return 0;
    return 1+ hossz(szam/10);
}


void paros(int szam, int pozicio, int n) {
    if (szam == 0) return;
    paros(szam / 10, pozicio - 1, n);
    if (pozicio % 2 == 0) {
        printf("%d. pozicio: %d\n", pozicio, szam % 10);
    }
}



int main(){
    //int szam;
    //scanf("%d",&szam);
    int szam = 9754;
    int n = hossz(szam);
    paros(szam,n,n);

    //10 szamjegy beolvasas es kiirni azokat a szamjegyeketet amelyek paros helyen vannak





    return 0;
}