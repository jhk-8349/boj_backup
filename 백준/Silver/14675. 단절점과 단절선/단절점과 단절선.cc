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

int N;
vector<vector<int>> tree(100010);
vector<pii> edge(100010);
void solve() {
    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        edge[i] = {a, b};
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t, k; cin >> t >> k;
        if (t == 1) cout << (tree[k].size() == 1 ? "no" : "yes") << endl;
        else cout << "yes" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}