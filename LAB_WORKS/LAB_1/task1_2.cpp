#include <bits/stdc++.h>

using namespace std;


void heapify(int arr[], int parent, int size) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int largest = parent;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != parent) {
        int temp = arr[parent];
        arr[parent] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, size);
    }
}

void heapSort(int arr[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(arr, i, size);

    for (int i = size - 1; i > 0; i--) {
        int max = arr[0];
        arr[0] = arr[i];
        arr[i] = max;
        heapify(arr, 0, i);
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

    heapSort(arr, n);

    for (int i = 0; i < n; ++i) {
        count[arr[i]] += 1;
        if (count[arr[i]] == 1) firstIndex[arr[i]] = i;
    }

    printNthPair(arr, n, k - 1, count, firstIndex);
}