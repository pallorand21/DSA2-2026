#include <stdio.h>
#include "Functions.h"


int main(void) {
    int n ;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    if (!v) {
        printf("sikertelen helyfoglalas");
        exit (-1);

    }


    readElementsRecursive(v,n-1);
   printElementsRecursive(v,n-1);
    int sum = sumElementsRecursive(v,n-1);
    //int min = minElementRecursive(v,n);
    int pos = countPositiveElementsRecursive(v,n);
    printf("Sum: %d\n",sum);
    printf("positive: %d\n",pos);
    //printf("Min: %d\n",min);


free(v);
return 0;
}