#include <bits/stdc++.h>

using namespace std;

void sort(int *arr, int n) {
    int i = n - 1;
    int value = arr[i];
    int hole = i;
    while (hole > 0 && value < arr[hole - 1]) {
        arr[hole] = arr[hole - 1];
        hole--;
    }
    arr[hole] = value;
}

void printMedian(int *arr, int size) {
    int median = size % 2 ? arr[size / 2] : (arr[size / 2] + arr[size / 2 - 1]) / 2;
    printf("%d\n", median);
}

int main() {
    int arr[1000];
    int i = 0;
    int j = 0;
    while (++i) {
        scanf("%d", &arr[j++]);
        sort(arr, i);//i = size of current arr
        printMedian(arr, i);
    }
}