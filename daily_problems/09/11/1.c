#include <stdio.h>

void f(int *a, int n, int idx) {
    int x = a[idx], i = idx, j = n-1;
    while(i <= j) {
        while(i <= j && a[j] >= x) j--;
        a[i] = a[j];
        while(i <= j && a[i] <= x) i++;
        a[j] = a[i];
    }
    a[i] = x;
    j = i, i = 0;
    while(i <= j) {
        while(i <= j && a[i] <= x) i++;
        a[j] = a[i];
        while(i <= j && a[j] >= x) j--;
        a[i] = a[j];
    }
    a[i] = x;
}


int main() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    f(a, n, 3);
    for(int i = 0; i < n; i++) printf("%-3d", a[i]);
}