#include <stdio.h>
#include <stdlib.h>


int binarysearch(int arr[], int left, int right, int target);






int rendez( const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}

int main(void) {
    //I. FELADAT
    FILE *f = fopen("1dbemenet.txt","r");
    if (!f) {
        printf("sikertelen 1dbemenet megnyitas");
        exit(-2);
    }
    int n;
    fscanf(f,"%d",&n);
    int tomb[n];
    for ( int i = 0; i < n ; ++i) {
        fscanf(f,"%d",&tomb[i]);
        //printf("%d\n",tomb[i]);
    }
    qsort(tomb,n,sizeof(int),rendez);
    printf("Rendezett tomb: ");
    for ( int i = 0; i < n ; ++i) {
        printf("%d ",tomb[i]);
    }
    int talalat = binarysearch(tomb,0,n,2);
    if (talalat == 1) {
        printf("talalat");
    }
    else {
        printf("talalat nincs");
    }

    return 0;
}
int binarysearch(int arr[], int left, int right, int target) {
    int mid = (left + right) / 2;
    if (target == arr[mid]) {
        return mid;
    }
    if (target > arr[mid]) {
        return binarysearch(arr, mid+1, right, target);
    }
    else {
        return binarysearch(arr, left, mid-1, target);
    }
}

