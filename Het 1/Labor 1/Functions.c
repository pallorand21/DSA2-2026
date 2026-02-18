//
// Created by pallorand21 on 2026. 02. 18..
//

#include "Functions.h"

#include <limits.h>


void readElementsRecursive(int *v, int n) {
    if ( n >=0 ) {
        readElementsRecursive(v, n-1);
        scanf("%d", &v[n]);
    }
}

void printElementsRecursive(int *v, int n) {
    if ( n >=0 ) {
        printElementsRecursive(v, n-1);
        printf("%d ", v[n]);
    }
}

int sumElementsRecursive(int *v, int n) {
    if ( n == 0) {
        return v[0];
    }
    return (v[n] + sumElementsRecursive(v, n-1));
}

int minElementRecursive(int *v, int n) {

    if ( n == 1) {
        return v[0];
    }

int min=minElementRecursive(v,n-1);
    int vegsomin;

    if (*(v+n-1) < min) {
        vegsomin = *(v+n-1);
    }
    else {
            min = vegsomin;
        }
    return vegsomin;

    }

int countPositiveElementsRecursive(int *v, int n) {
    if ( n == 0) {
        return 0;
    }

    int count = countPositiveElementsRecursive(v, n-1);
    if (*(v+n-1) > 0) {
        return count + 1;
    }
    else {
        return count;
    }
}



