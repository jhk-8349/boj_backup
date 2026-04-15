#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef array<ll, 2> pll;

#define F first
#define S second
#define endl "\n"
const ll INF = (~0U >> 2);

int N, M;
vector<int> v;

void rec() {
    if (v.size() == M) {
        for (auto x : v) cout << x << ' ';
        cout << endl;
        return;
    } else {
        for (int i = 1; i <= N; i++) {
            v.push_back(i);
            rec();
            v.pop_back();
        }
    }
}


void solve() {
    cin >> N >> M;
    rec();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}