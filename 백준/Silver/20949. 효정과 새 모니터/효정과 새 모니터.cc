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
const int INF = (~0U >> 2);

bool cmp(pii A, pii B) {return A.F == B.F ? A.S < B.S : A.F > B.F;}

void solve() {
    int N; cin >> N;
    vector<pii> monitor(N);
    for (int i = 0; i < N; i++) {
        int w, h; cin >> w >> h;
        monitor[i] = {w * w + h * h, i};
    }

    sort(monitor.begin(), monitor.end(), cmp);
    for (auto x : monitor) cout << x.S + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}