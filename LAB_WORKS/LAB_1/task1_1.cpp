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

void printNthPair(int *arr, int n, int k, map<int, int> count, map<int, int> firstIndex) {
    int i = firstIndex[arr[k / n]];
    int j = (k - n * i) / count[arr[i]];

    printf("%d %d\n", arr[i], arr[j]);
}


int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[n];
    map<int, int> count, firstIndex;

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    sort(arr, n);

    for (int i = 0; i < n; ++i) {
        count[arr[i]] += 1;
        if (count[arr[i]] == 1) firstIndex[arr[i]] = i;
    }

    printNthPair(arr, n, k - 1, count, firstIndex);
}