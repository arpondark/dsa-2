#include <bits/stdc++.h>
using namespace std;

int countDivisible(vector<int>& arr, int low, int high) {
    if (low == high) {
        if (arr[low] % 3 == 0 || arr[low] % 7 == 0) {
            cout << arr[low] << "\n";
            return 1;
        }
        return 0;
    }

    int mid = (low + high) / 2;

    int leftCount = countDivisible(arr, low, mid);
    int rightCount = countDivisible(arr, mid + 1, high);

    return leftCount + rightCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int total = countDivisible(arr, 0, n - 1);
    cout << "Total : " << total << "\n";

    return 0;
}

