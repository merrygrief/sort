#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *a, int n);
int main()
{
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = rand()%100;
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    bubble_sort(a,10);
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}

void bubble_sort(int *a, int n)
{
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j < n-i; j++){
            if(a[j-1] > a[j]) {int t = a[j-1]; a[j-1] = a[j]; a[j] = t;}
        }
    }
} 