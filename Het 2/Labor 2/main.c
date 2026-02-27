#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int *v, int n) {
    if (n==0) {
        return;
    }
    v[n-1] = rand() % 3;
    fill(v, n-1);
}

int max(int *v, int i, int j) {
    if (i == j) {
        return i;
    }

    int mid = (i + j) / 2;

    int m1 = max(v, i, mid);
    int m2 = max(v, mid + 1, j);


    if ((v[m1] == 0 && v[m2] == 2) ||
        (v[m1] == 2 && v[m2] == 1) ||
        (v[m1] == 1 && v[m2] == 0)) {
        return m1;
        } else {
            return m2;
        }
}

int main(void) {
    //0 ko//1 papir//2 ollo
    int n = 8;
    int v[8];
    srand(time(NULL));
    fill(v, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    int gyoztes = max(v, 0, n-1);
    printf("\ngyoztes %d.-ik \n", gyoztes);




    return 0;
}

