#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void permutacio(int *t, int n, int k, char zenek[][2][25]);

bool permutal(int *t, int n, int k, char zenek[][2][25]);

void kiir(int *t, int n, int k, char zenek[][2][25]);


int main(void) {
    char zenek[][2][25] = {
        {"gta.mp3", "intro"}, {"redemptixn", "banger"}, {"cherry tea", "interlude"}, {"selyem", "interlude"},
        {"tihany", "interlude"}
    };
    int n = sizeof(zenek) / sizeof(zenek[0]);
    int *t = (int *) malloc(n * sizeof(int));
    if (!t) {
        printf("sikertelen foglalas");
        exit(-1);
    }

    permutacio(t, n, 0, zenek);

    free(t);
    return 0;
}

void permutacio(int *t, int n, int k, char zenek[][2][25]) {
    for (t[k] = 1; t[k] <= n; t[k]++) {
        if (permutal(t, n, k, zenek)) {
            if (k < n - 1) {
                permutacio(t, n, k+1, zenek);
            }
            else {
                kiir(t, n, k, zenek);
            }
        }
    }
}

bool permutal(int *t, int n, int k, char zenek[][2][25]) {
    if (k == 0 && strcmp(zenek[t[k] - 1][1], "intro") != 0) { return false; }
    if (k == n - 1 && strcmp(zenek[t[k] - 1][1], "banger") != 0) { return false; }
    for (int i = 0; i < k; i++) {
        if (t[k] == t[i]) {
            return false;
        }
    }
    return true;
}

void kiir(int *t, int n, int k, char zenek[][2][25]) {
    for (int i = 0; i < n; i++) {
        printf("%s | ", zenek[t[i]-1][0]);
    }
    printf("\n");
}
