#include <bits/stdc++.h>

using namespace std;

void sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && value < arr[hole - 1]) {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}

void printNthPair(int *arr, int n, int k) {
    int i = k / n;
    int j = k % n - 1;
    printf("%d %d", arr[i], arr[j]);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr, n);
    printNthPair(arr, n, k);
}
