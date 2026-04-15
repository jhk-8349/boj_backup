#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int INF = 1e18;
const int MOD = 1e9+7;

void solve() {
    int N, M; cin >> N >> M;
    vii adj(N + 1, vi(N + 1, INF));
    for (int i = 1; i <= N; i++) adj[i][i] = 0;

    while (M--) {
        int A, B, T; cin >> A >> B >> T;
        adj[A][B] = T;
    }
    
    int K; cin >> K;
    vi C(K + 1);
    for (int i = 1; i <= K; i++) cin >> C[i];

    for (int m = 1; m <= N; m++) {
        for (int s = 1; s <= N; s++) {
            for (int e = 1; e <= N; e++) {
                if (adj[s][m] == INF || adj[m][e] == INF) continue;
                if (adj[s][e] > adj[s][m] + adj[m][e]) {
                    adj[s][e] = adj[s][m] + adj[m][e];
                }
            }
        }
    }
    
    vii dist(N + 1, vi(K + 1, INF)); // dist[목표 도시 X]][i] = Ci-X 왕복 거리
    for (int X = 1; X <= N; X++) {
        for (int i = 1; i <= K; i++) {
            if (adj[C[i]][X] == INF || adj[X][C[i]] == INF) continue;
            dist[X][i] = adj[C[i]][X] + adj[X][C[i]];
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= K; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // } cout << endl;

    vi max_dist(N + 1);
    for (int X = 1; X <= N; X++) max_dist[X] = *max_element(dist[X].begin() + 1, dist[X].end());
    int min_max = *min_element(max_dist.begin() + 1, max_dist.end());
    for (int X = 1; X <= N; X++) if (max_dist[X] == min_max) cout << X << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}