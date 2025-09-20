#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> &arr) {
    if (arr.empty()) return 0; // handle empty input case
    
    long long maxSoFar = arr[0];
    long long maxEndingHere = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxEndingHere = max((long long)arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    int n;
    cin >> n;  // ✅ Read n properly
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSubarraySum(arr) << endl;
    return 0;
}
