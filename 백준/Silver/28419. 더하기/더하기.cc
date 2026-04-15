// BOJ 28419: 더하기
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
	ll N; cin >> N;
	ll odd = 0, even = 0, c;
	for (ll i = 1; i <= N; i++) {
		cin >> c;
		if (i % 2) odd += c;
		else even += c;
	}

	if (N == 3) {
		if (odd <= even) cout << even - odd;
		else cout << -1;
	} else cout << abs(odd - even);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();	
	return 0;
}