// BOJ 34100: └┘
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
	int N, M; cin >> N >> M;
	vector<vector<char>> B(N, vector<char> (M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}

	bool flag = true;
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i >= 0; i--) {
			if (B[i][j] != '.') continue;
			if (i == 0 || j == M - 1) flag = false;
			else if (B[i][j + 1] != '.') flag = false;
			else if (B[i - 1][j] == '.') {
				B[i][j] = 'a';
				B[i - 1][j] = 'a';
				B[i][j + 1] = 'a';
			} else if (B[i - 1][j + 1] == '.') {
				B[i][j] = 'b';
				B[i - 1][j + 1] = 'b';
				B[i][j + 1] = 'b';
			} else flag = false;
		}
	}

	if (!flag) cout << -1 << endl;
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << B[i][j];
			}
			cout << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	while (T--) solve();	
	return 0;
}