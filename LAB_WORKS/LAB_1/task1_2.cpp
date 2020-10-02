#include <bits/stdc++.h>

using namespace std;

void heapify(vector<pair<int, int>> &vec, int parent, int size) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int largest = parent;
    if (left < size && (vec[left].first > vec[largest].first ||
                        (vec[left].first == vec[largest].first && vec[left].second > vec[largest].second)))
        largest = left;
    if (right < size && (vec[right].first > vec[largest].first ||
                         (vec[right].first == vec[largest].first && vec[right].second > vec[largest].second)))
        largest = right;
    if (largest != parent) {
        int v1 = vec[parent].first;
        int v2 = vec[parent].second;
        vec[parent].first = vec[largest].first;
        vec[parent].second = vec[largest].second;
        vec[largest].first = v1;
        vec[largest].second = v2;
        heapify(vec, largest, size);
    }
}

void heapSort(vector<pair<int, int>> &vec, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(vec, i, size);

    for (int i = size - 1; i > 0; i--) {
        int max1 = vec[0].first;
        int max2 = vec[0].second;
        vec[0].first = vec[i].first;
        vec[0].second = vec[i].second;
        vec[i].first = max1;
        vec[i].second = max2;
        heapify(vec, 0, i);
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
    heapSort(vec, n * n);

    printf("%d %d\n", vec[k - 1].first, vec[k - 1].second);
}