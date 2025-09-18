#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, d;
    cout << "Input amount (in cents): ";
    cin >> N;

    cout << "Enter number of coin types: ";
    cin >> d;

    vector<int> coins(d);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < d; i++)
        cin >> coins[i];
    sort(coins.rbegin(), coins.rend());

    int totalCoins = 0;
    vector<pair<int,int>> result;

    for (int c : coins) {
        if (N >= c) {
            int count = N / c;
            N -= count * c;
            totalCoins += count;
            result.push_back({c, count});
        }
    }

    for (auto p : result) {
        cout << p.first << " cents --- " << p.second << "\n";
    }
    cout << "Total " << totalCoins << " coins\n";

    return 0;
}

