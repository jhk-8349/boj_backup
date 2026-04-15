// BOJ 20040: 사이클 게임
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

vector<int> uf;

int find(int a) {
	return a == uf[a] ? a : uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	uf[a] = uf[b];
	return a == b;
}

void solve() {
	int n, m; cin >> n >> m;
	uf.resize(n);
	for (int i = 0; i < n; i++) uf[i] = i;
	int ans = 0, first = true;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (merge(a, b) && first) {ans = i; first = false;}
	}
	if (first) cout << 0;
	else cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}