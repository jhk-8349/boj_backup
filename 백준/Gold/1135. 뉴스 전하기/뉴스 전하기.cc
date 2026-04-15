// BOJ 1135: 뉴스 전하기
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

void solve() {
	int N; cin >> N;
	vector<int> dp(N, -1);
	vector<vector<int>> tree(N);
	int c; cin >> c;
	for (int i = 1; i < N; i++) {
		cin >> c;
		tree[c].push_back(i);
	}
	function<int(int)> f = [&](int a) {
		if (tree[a].empty()) return dp[a] = 0;
		if (dp[a] != -1) return dp[a];
		vector<int> v;
		for (auto x : tree[a]) v.push_back(f(x));
		sort(v.begin(), v.end());
		int size = v.size(), result = 0;
		for (auto x : v) {
			result = max(result, x + size);
			size--;
		}
		return result;
	};

	cout << f(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}