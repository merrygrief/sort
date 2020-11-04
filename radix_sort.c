#include<stdio.h>
#include<stdlib.h>
#define BASE 10
void radix_sort(int *a, int n); //sort natural number
int main()
{
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = rand()%100;
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    radix_sort(a, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}

void radix_sort(int *a, int n)
{
    int i, b[n], max = a[0], exp = 1;
    for (i = 1; i < n; i++) if (a[i] > max) max = a[i];
    while (max/exp > 0){
        int bucket[BASE] = {0};
        for (i = 0; i < n; i++) bucket[(a[i] / exp) % BASE]++;
        for (i = 1; i < BASE; i++)  bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--) b[--bucket[(a[i] / exp) % BASE]] = a[i];
        for (i = 0; i < n; i++) a[i] = b[i];
        exp *= BASE;
    } 
}