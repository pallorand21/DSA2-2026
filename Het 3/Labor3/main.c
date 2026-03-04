#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int *v, int n) {
    if (n==0) {
        return;
    }
    v[n-1] = rand() % 201 - 100;
    fill(v, n-1);
}
void kiir(int *v, int n) {
    if (n==0) {
        return;
    }
    kiir(v,n-1);
    printf("%d ",v[n-1]);

}
int merge(int *v,int bal,int mid,int jobb)
{
    int arr1[10],arr2[10];
    int n1,n2,i,j,k;
    n1=mid-bal+1;
    n2=jobb-mid;

    for(i=0;i<n1;i++)
        arr1[i]=v[bal+i];
    for(j=0;j<n2;j++)
        arr2[j]=v[mid+j+1];

    arr1[i]=INT_MAX;
    arr2[j]=INT_MAX;

    i=0;j=0;
    for(k=bal;k<=jobb;k++)
    {
        if(arr1[i]<=arr2[j])
            v[k]=arr1[i++];
        else
            v[k]=arr2[j++];
    }

    return 0;
}
int mergesort(int *v, int i, int j) {
    if (i < j) {
        int mid = (i + j)/2;
        mergesort(v,i,mid);
        mergesort(v,mid+1,j);
        merge(v,i,mid,j);
    }
    return 0;
}
int binary(int *v,int start, int end, int elem) {
    if (end >= start) {
        int mid = start + (end - start)/2;
        if (v[mid] == elem )
            return mid;
        if (v[mid] > elem)
            return binary(v,start,mid-1,elem);
        return binary(v,mid+1,end,elem);
    }
    return -1;
}



int main(void) {
    srand(time(NULL));
    int n;
    printf("Tomb merete: ");
    scanf("%d",&n);
    int v[n];
    fill(v,n);
    kiir(v,n);
    mergesort(v, 0, n-1);
    printf("\nRendezve:\n");
    kiir(v,n);
    printf("keresett elem: ");
    int elem;
    scanf("%d",&elem);
    int talalat = binary(v,0,n-1,elem);
    if (talalat == -1) {
        printf("nincs talalat\n");
    }
    else {
        printf("van talalat: %d", talalat);
    }





    return 0;
}