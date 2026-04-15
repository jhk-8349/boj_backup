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

class UnionFind {
    private:
    vector<int> par;
    vector<int> rank;
    public:
    UnionFind(int N) {
        par.assign(N + 1, -1);
        rank.assign(N + 1, 0);
    }
    int Find(int a) {
        if (par[a] == -1) return a;
        else {
            int x = Find(par[a]);
            par[a] = x;
            return x;
        }
    }
    void Union(int a, int b) {
        int x = Find(a), y = Find(b);
        if (x == y) return;
        else if (rank[x] > rank[y]) swap(x, y);
        par[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vector<array<int, 3>> edge(M);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    sort(edge.begin(), edge.end());
    UnionFind uf(N);
    int cnt = 0; ll ans = 0;

    for (auto r : edge) {
        if (uf.Find(r[1]) == uf.Find(r[2])) continue;
        else {
            if (cnt == N - 2) break;
            ans += r[0];
            uf.Union(r[1], r[2]);
            cnt++;
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}