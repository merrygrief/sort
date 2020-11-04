#include <stdio.h>
#include <stdlib.h>
void heap_sort(int *a, int n);
void swap(int *a, int *b);
void percdown(int *a, int root, int n);
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand()%100;
    for (int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    heap_sort(a, 10);
    for (int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heap_sort(int *a, int n)
{
    for (int i = n/2; i >= 0; i--) percdown(a, i, n);
    for (int i = n-1; i > 0; i--){
        swap(&a[0], &a[i]);
        percdown(a, 0, i);
    }
}

void percdown(int *a, int root, int n)
{
    int child;
    for(; 2*root+1 < n; root = child){
        child = 2*root+1;
        if(child != n-1 && a[child+1] > a[child]) child++;
        if(a[root] < a[child]) swap(&a[root], &a[child]);
        else break;
    }
}