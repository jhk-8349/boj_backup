// BOJ 1761: 정점의 거리
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

vector<vector<pii>> tree;
vector<int> dep;
vector<int> dist;
vector<vector<int>> sp; //sp[node][lifting]

void dfs(int cur, int prn, int d) {
	dep[cur] = dep[prn] + 1;
	dist[cur] = dist[prn] + d;
	sp[cur][0] = prn;
	for (auto child : tree[cur]) {
		if (dep[child.F] != -1) continue;
		dfs(child.F, cur, child.S);
	}
}

int find(int now, int depth) {
	for (int i = 0; depth > 0; i++) {
		if (depth & 1) now = sp[now][i];
		depth >>= 1;
	}
	return now;
}

int LCA(int a, int b) {
	if (dep[a] > dep[b]) a = find(a, dep[a] - dep[b]);
	else if (dep[a] < dep[b]) b = find(b, dep[b] - dep[a]);
	if (a == b) return a;
	for (int x = 19; x >= 0; x--) {
		if (find(a, 1 << x) == find(b, 1 << x)) continue;
		else {
			a = find(a, 1 << x);
			b = find(b, 1 << x);
		}
	}
	return find(a, 1);
}

void solve() {
	int N; cin >> N;
	tree.resize(N + 1);
	dep.resize(N + 1, -1);
	dist.resize(N + 1);
	sp.resize(N + 1, vector<int>(20));
	for (int i = 1; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	dfs(1, 1, 0);
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= N; i++) {
			sp[i][j] = sp[sp[i][j - 1]][j - 1];
		}
	}

	int M; cin >> M;
	while (M--) {
		int a, b; cin >> a >> b;
		cout << dist[a] + dist[b] - (2 * dist[LCA(a, b)]) << endl;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}