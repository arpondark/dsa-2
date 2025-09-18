#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int index;
    double value;
    double weight;
    double ratio;

    Item(int index, double value, double weight, double ratio){
        this->index = index;
        this->value = value;
        this->weight = weight;
        this->ratio = ratio;
    }
};

bool byRatioDesc(const Item& a, const Item& b) {
    if (a.ratio != b.ratio) return a.ratio > b.ratio;   // higher ratio first
    if (a.value != b.value) return a.value > b.value;   // if equal ratio, higher value first
    return a.index < b.index;                           // finally, lower original index first
}

int main() {
    int n;
    double W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        double v, w;
        cin >> w >> v;
        items.push_back(Item(i + 1, v, w, v / w));
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    sort(items.begin(), items.end(), byRatioDesc);

    double remaining = W;
    double maxProfit = 0.0;

    vector<Item> taken;

    for (Item it : items) {
        if (remaining <= 0.0)
            break;

        if (remaining >= it.weight) {
            // Take the whole item
            remaining -= it.weight;
            maxProfit += it.value;
            taken.push_back(it);
        } else {
            // Take the fraction that fits
            double fraction = remaining / it.weight;
            maxProfit += it.value * fraction;
            taken.push_back(Item(it.index, it.value * fraction, it.weight * fraction, it.ratio));
            remaining = 0.0; // knapsack is full
        }
    }

    cout << fixed << setprecision(1);
    cout << "\nMaximum Profit = " << maxProfit << "\n";
    cout << "Items taken (original_index : weight : value):\n";
    for (Item p : taken) {
        cout << "Item " << p.index << " -> " << p.weight << " kg -> " << p.value << " taka" << endl;
    }
    return 0;
}
