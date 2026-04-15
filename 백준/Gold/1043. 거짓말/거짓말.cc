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
    int N, M, T; cin >> N >> M >> T;
    UnionFind uf(N);
    vector<int> truth(T);
    vector<vector<int>> party(M);
    for (int i = 0; i < T; i++) cin >> truth[i];
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int b; cin >> b;
            party[i].push_back(b);
        }
    }

    if (T == 0) {
        cout << M << endl;
        return;
    }

    for (int x : truth) uf.Union(x, truth[0]);
    for (vector<int> p : party) {
        for (int x : p) uf.Union(x, p[0]);
    }

    int ans = 0;

    for (vector<int> p : party) {
        bool flag = true;
        for (int x : p) {
            if (uf.Find(x) == uf.Find(truth[0])) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
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