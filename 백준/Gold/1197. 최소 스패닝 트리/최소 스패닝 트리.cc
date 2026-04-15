// BOJ 1197: 최소 스패닝 트리
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


struct Edge {
	int u, v, c;
};

vector<Edge> graph;
vector<int> uf;

int find(int a) {
	return a == uf[a] ? a : uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	uf[a] = b;
	return a != b;
}

void solve() {
	int V, E; cin >> V >> E;
	uf.resize(V + 1);
	for (int i = 1; i <= V; i++) uf[i] = i;
	Edge edge;
	while (E--) {
		cin >> edge.u >> edge.v >> edge.c;
		graph.push_back(edge);
	}

	sort(graph.begin(), graph.end(), [&](Edge a, Edge b) {
		return a.c < b.c;
	});

	int cnt = 0; ll ans = 0;
	for (auto [u, v, c]: graph) {
		if (merge(u, v)) {
			cnt++; ans += c;
		}
		if (cnt == V - 1) break;
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