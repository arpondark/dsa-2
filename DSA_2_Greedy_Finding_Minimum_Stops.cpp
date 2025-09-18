#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, m, n;
    cin >> D >> m >> n;

    vector<int> stations(n);
    for (int i = 0; i < n; i++)
        cin >> stations[i];

    stations.push_back(D);
    int current = 0;
    int lastStop = 0;
    int i = 0;
    vector<pair<int, int>> stops;

    while (current + m < D) {
        int farthest = current;
        while (i < stations.size() && stations[i] <= current + m) {
            farthest = stations[i];
            i++;
        }

        if (farthest == current) {
            cout << "Can't reach destination\n";
            return 0;
        }

        if (farthest < D)
            stops.push_back({i, farthest});
        current = farthest;
    }

    for (auto s : stops) {
        cout << "stop at gas station " << s.first << " (" << s.second << " miles)" << endl;
    }

    return 0;
}

