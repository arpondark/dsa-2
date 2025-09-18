#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns the k-th largest element in nums (1-based k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const int num : nums) {
            minHeap.push(num);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        cerr << "Expected number of elements\n";
        return 1;
    }

    if (n <= 0) {
        cerr << "n must be positive\n";
        return 1;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int k;
    if (!(cin >> k)) {
        cerr << "Expected k\n";
        return 1;
    }

    if (k < 1 || k > n) {
        cerr << "k must be between 1 and n\n";
        return 1;
    }

    Solution sol;
    int ans = sol.findKthLargest(nums, k);
    cout << ans << '\n';

    return 0;
}