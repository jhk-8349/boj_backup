// BOJ 13717: 포켓몬 GO
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
	string ans_name; int cnt = 0, ans_max = -1;
	
	string name; int a, b, q;
	while (N--) {
		q = 0;
		cin >> name >> a >> b;
		
		for(;;) {
			b -= a;
			if (b < 0) break;
			q++; b += 2;
		}

		cnt += q;

		if (q > ans_max) {
			ans_max = q;
			ans_name = name;
		}
	}

	cout << cnt << endl << ans_name;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();	
	return 0;
}