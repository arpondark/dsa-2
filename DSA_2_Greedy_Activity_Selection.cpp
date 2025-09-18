#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    string name;
    int start_time;
    int end_time;
};

// Compare function: sort by finish time in ascending order
bool byFinishTime(const Activity &a, const Activity &b) {
    if (a.end_time != b.end_time)
        return a.end_time < b.end_time;  // earlier finish first
    return a.start_time < b.start_time;  // tie-breaker: earlier start first
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter activity details (name start_time end_time):\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].name >> activities[i].start_time >> activities[i].end_time;
    }

    sort(activities.begin(), activities.end(), byFinishTime);

    vector<Activity> selected;
    int lastFinish = -1;

    for (Activity act : activities) {
        if (act.start_time >= lastFinish) {
            selected.push_back(act);
            lastFinish = act.end_time;
        }
    }

    cout << "\nSelected activities: " << endl;
    for (Activity act : selected) {
        cout << act.name << " (" << act.start_time << ", " << act.end_time << ")" << endl;
    }

    cout << "Maximum number of activities = " << selected.size() << endl;

    return 0;
}

