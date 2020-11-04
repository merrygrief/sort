#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bucket_sort(int *, int);
int main()
{
    int a[10];
    for(int i = 0; i < 10; i++) a[i] = rand()%100;
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    printf("\n");
    bucket_sort(a, 10);
    for(int i = 0; i < 10; i++) printf("%d, ", a[i]);
    return 0;
}

void bucket_sort(int *a, int n)
{
    int max = a[0], min = a[0], len;
    for(int i = 1; i < n; i++) if(max < a[i]) max = a[i];
    for(int i = 1; i < n; i++) if(min > a[i]) min = a[i];
    len = max-min+1;
    int b[len];
    memset(b, 0, len * sizeof(int));
    for(int i = 0; i < n; i++) b[a[i]-min]++;
    for(int j = 0, i = 0; j < len; j++){
            if(b[j]!=0){a[i] = j+min; i++; b[j]--;}
    }
}