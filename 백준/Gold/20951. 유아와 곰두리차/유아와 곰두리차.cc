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

void solve() {
    const int MOD = 1000000007;
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[length of path][terminate of path]
    vector<vector<int>> dp(8, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) dp[1][i] = graph[i].size();

    for (int len = 1; len < 7; len++) {
        for (int i = 1; i <= N; i++) {
            for (int x : graph[i]){
                dp[len + 1][x] += dp[len][i];
                dp[len + 1][x] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int x : dp[7]) {
        ans += x; ans %= MOD;
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