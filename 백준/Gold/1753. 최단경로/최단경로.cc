#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef array<int, 2> pii;
typedef array<ll, 2> pll;
#define F first
#define S second
#define endl "\n"
const int INF = (~0U >> 2);

void solve() {
    int V, E, K; cin >> V >> E >> K;
    vector<vector<pii>> adj(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(V + 1, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[K] = 0;
    pq.push({0, K});
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top(); pq.pop();
        if (cur_dist != dist[cur]) continue;
        for (auto [nxt, cost] : adj[cur]) {
            if (dist[nxt] <= dist[cur] + cost) continue;
            dist[nxt] = dist[cur] + cost;
            pq.push({dist[nxt], nxt});
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}