// BOJ 1922: 네트워크 연결
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
	int a, b, c;
};

vector<int> uf;
vector<Edge> graph;

int find(int a) {
	return a == uf[a] ? a : uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	uf[a] = b;
	return a != b;
}

void solve() {
	int N, M; cin >> N >> M;
	uf.resize(N + 1);
	for (int i = 1; i <= N; i++) uf[i] = i;
	Edge e;
	while (M--) {
		cin >> e.a >> e.b >> e.c;
		graph.push_back(e);
	}

	sort(graph.begin(), graph.end(), [&](Edge e1, Edge e2){return e1.c < e2.c;});

	int cost = 0, cnt = 0; N--;
	for (auto [a, b, c] : graph) {
		if (a == b) continue;
		if (!merge(a, b)) continue;
		cost += c; cnt++;
	}

	cout << cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}