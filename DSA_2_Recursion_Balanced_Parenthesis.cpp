#include <bits/stdc++.h>
using namespace std;

bool checkBalanced(string s, int index, int count) {
    if (count < 0)
        return false;

    if (index == (int)s.size()) {
        return (count == 0);
    }

    if (s[index] == '(')
        return checkBalanced(s, index + 1, count + 1);
    else if (s[index] == ')')
        return checkBalanced(s, index + 1, count - 1);
    else
        return checkBalanced(s, index + 1, count);
}

int main() {
    string s;
    cin >> s;

    if (checkBalanced(s, 0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

