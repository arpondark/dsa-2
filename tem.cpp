#include <bits/stdc++.h>
using namespace std;

// ---------- Optimization ----------
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// ---------- Aliases ----------
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using vi = vector<int>;
using vl = vector<long long>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7; // change if needed

// ---------- Fast IO ----------
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ---------- Debug (disable for contest) ----------
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << '\n'
#else
    #define debug(x)
#endif

// ---------- Utility ----------
template<class T> inline void ckmin(T& a, T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T& a, T b) { if (b > a) a = b; }

// ---------- Main ----------
void solve() {
    // write solution here
}

int main() {
    fastio();
    int t = 1;
    // cin >> t; // enable if multiple test cases
    while (t--) solve();
    return 0;
}
