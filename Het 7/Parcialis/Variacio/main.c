#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void variacio (int *t, int n, int k, char pedalok[][25],int osszes);
bool varial (int *t,int n, int k, char pedalok[][25],int osszes );
void kiir(int *x, int n, int k,char pedalok[][25],int osszes);

int main(void) {
    int n;
    printf("Hany pedal legyen?");
    scanf("%d", &n);
    char pedalok[][25] = {"reverb","tuner","distortion","flanger","looper","tubescreamer","overdrive","compressor"};

    int *x=(int*)malloc(n * sizeof(int));
    if (!x) {
        printf("Sikertelen foglalas");
        return -2;
    }
    int osszes = sizeof(pedalok)/sizeof(pedalok[0]);
    variacio(x,n,0,pedalok,osszes);


    return 0;
}

void variacio (int *t, int n, int k, char pedalok[][25],int osszes) {

    for (t[k] = 1; t[k] <= osszes; t[k]++) {
        if (varial(t,n,k,pedalok,osszes)) {
            if (k < n - 1) {
                variacio(t,n,k+1,pedalok,osszes);
            }
            else {
                kiir(t,n,k,pedalok,osszes);
            }
        }

}


}
bool varial (int *t,int n, int k, char pedalok[][25],int osszes ) {
    if (k == 0 && strcmp(pedalok[t[k]-1], "tuner") != 0 ){return false;}
    if (k == n-1  && strcmp(pedalok[t[k]-1],"reverb")!=0){return false;}
    for (int i = 0; i < k; i++) {
        if (t[k] == t[i]){
            return false;
        }
    }
    return true;
}

void kiir(int *x, int n, int k,char pedalok[][25],int osszes) {
    for (int i = 0; i < n; i++) {
        printf("%s | ",pedalok[x[i]-1]);
    }
    printf("\n");
}
