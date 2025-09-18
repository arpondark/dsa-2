#include <bits/stdc++.h>
using namespace std;

int partitionDesc(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] >= pivot) { 
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSortDesc(vector<int> &a, int l, int r) {
    if (l < r) {
        int p = partitionDesc(a, l, r);
        quickSortDesc(a, l, p - 1);
        quickSortDesc(a, p + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    quickSortDesc(arr, 0, n - 1);
    for (int x : arr) cout << x << " ";
    cout << "\n";
}
