#include <stdio.h>
#include <stdlib.h>
void selection_sort(int *a, int n);
int main()
{
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = rand()%100;
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    selection_sort(a, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}

void selection_sort(int *a, int n)
{
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++) if(a[min] > a[j]) min = j;
        if(min != i) {int t = a[min]; a[min] = a[i]; a[i] = t;}
    }
}