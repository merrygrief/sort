#include <stdio.h>
#include <stdlib.h>
void quick_sort(int *a, int low, int high);
void swap(int *a, int *b);
void q_sort(int *a, int n);
int main()
{
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = rand()%100;
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    q_sort(a, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void quick_sort(int *a, int low, int high)
{
    if(low >= high) return;
    int start = low, end = high;
    int key = a[high];
    high--;
    while(low < high){
        while(a[low] < key && low < high) low++;
        while(a[high] >= key && low < high) high--;
        swap(&a[low], &a[high]);
    }
    if(a[low] > key) swap(&a[low], &a[end]);
    if(low) quick_sort(a, start, low-1);
    quick_sort(a, low+1, end);
}
void q_sort(int *a, int n)
{
    quick_sort(a, 0, n-1);
}