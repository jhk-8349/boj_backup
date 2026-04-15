// BOJ 17435: 합성함수와 쿼리
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

vector<vector<int>> sp; // sparse table



void solve() {
	int m; cin >> m;
	sp.resize(20, vector<int>(m + 1));
	for (int i = 1; i <= m; i++) cin >> sp[0][i];

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= m; j++) {
			sp[i][j] = sp[i - 1][sp[i - 1][j]];
		}
	}

	int Q, n, x, bit; cin >> Q;
	while (Q--) {
		cin >> n >> x; bit = 0;
		while (n) {
			if (n & 1) x = sp[bit][x];
			n >>= 1; bit++;
		}
		cout << x << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}