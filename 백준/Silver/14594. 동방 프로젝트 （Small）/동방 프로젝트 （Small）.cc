// BOJ 14594: 동방 프로젝트 (Small)
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
	int N, M, x, y;
	cin >> N >> M;
	vector<int> wall(N - 1);

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
        x--; y--;
		for (int j = x; j < y; j++) {
			wall[j] = 1;
		}
	}
	int broken_wall = 0;
	for (auto i : wall) broken_wall += i;

	cout << N - broken_wall << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 1; //cin >> T;
	while (T--) solve();	
	return 0;
}