// BOJ 1717: 집합의 표현
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

int uf_find(int a) {
	return a == uf[a] ? a : uf[a] = uf_find(uf[a]);
}

void uf_merge(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);
	uf[a] = b;
}

void solve() {
	int n, m; cin >> n >> m;
	uf.resize(n + 1);
	for (int i = 0; i <= n; i++) uf[i] = i;
	int q, a, b;
	while (m--) {
		cin >> q >> a >> b;
		if (!q) uf_merge(a, b);
		else {
			if (uf_find(a) == uf_find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}