// BOJ 15681: 트리와 쿼리
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

int N, R, Q;
vector<vector<int>> input, tree;
vector<int> dp;

int query(int node) {
	if (tree[node].empty()) return 1;
	if (dp[node] != -1) return dp[node];
	int ans = 0;
	for (auto nxt : tree[node]) ans += query(nxt);
	return dp[node] = ans + 1;
}

void solve() {
	cin >> N >> R >> Q;
	input.resize(N + 1);
	tree.resize(N + 1);
	dp.resize(N + 1);

	for (int i = 1; i < N; i++) {
		int U, V; cin >> U >> V;
		input[U].push_back(V);
		input[V].push_back(U);
	}

	dp[R] = -1;
	queue<int> q; q.push(R);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : input[cur]) {
			if (dp[nxt]) continue;
			else {
				q.push(nxt);
				tree[cur].push_back(nxt);
				dp[nxt] = -1;
			}
		}
	}
	int k;
	while (Q--) {
		cin >> k;
		cout << query(k) << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}