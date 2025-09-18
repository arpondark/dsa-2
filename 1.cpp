#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int> &a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(a.begin() + l, a.begin() + m + 1);
    vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    long long inv = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else {
            a[k++] = R[j++];
            inv += (n1 - i); 
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    return inv;
}

long long countInversion(vector<int> &a, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv += countInversion(a, l, m);
        inv += countInversion(a, m + 1, r);
        inv += mergeAndCount(a, l, m, r);
    }
    return inv;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "#inversions: " << countInversion(arr, 0, n - 1) << "\n";
}
