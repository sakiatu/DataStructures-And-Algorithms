#include <bits/stdc++.h>

using namespace std;

void sort(vector<pair<int, int>> &vec, int n) {
    for (int i = 1; i < n; i++) {
        int val1 = vec[i].first;
        int val2 = vec[i].second;
        int hole = i;
        while (hole > 0 && val1 <= vec[hole - 1].first && val2 <= vec[hole - 1].second) {
            vec[hole].first = vec[hole - 1].first;
            vec[hole].second = vec[hole - 1].second;
            hole--;
        }
        vec[hole].first = val1;
        vec[hole].second = val2;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            vec.push_back(make_pair(arr[i], arr[j]));
    sort(vec, n * n);

    printf("%d %d\n", vec[k - 1].first, vec[k - 1].second);
}