#include <bits/stdc++.h>
using namespace std;

// QuickSort implementation (in-place, recursive) using Lomuto partition
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortRec(vector<int> &a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSortRec(a, low, p - 1);
        quickSortRec(a, p + 1, high);
    }
}

void heapSort(vector<int> &nums) {
    // Keep function name same to minimize changes in main.
    if (nums.empty()) return;
    quickSortRec(nums, 0, (int)nums.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    heapSort(nums);

    for (int x : nums)
        cout << x << " ";
    cout << "\n";
    return 0;
}
