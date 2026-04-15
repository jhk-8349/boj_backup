// BOJ 14438: 수열과 쿼리 17
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

class Segtree_Min {
private:
	int n;
	ll *data;
	ll build(const vector<ll>& arr, int n, int s, int e) {
		if (s == e) return data[n] = arr[s];
		int m = (s + e) >> 1;
		return data[n] = min(build(arr, n << 1, s, m)
					   , build(arr, (n << 1) + 1, m + 1, e));
	}
	ll update(int i, ll x, int n, int s, int e) {
		if (e < i || i < s) return data[n];
		if (i <= s && e <= i) return data[n] = x;
		const int m = (s + e) >> 1;
		return data[n] = min(update(i, x, n << 1, s, m)
					   , update(i, x, (n << 1) + 1, m + 1, e));
	}
	ll query(int qs, int qe, int n, int s, int e) {
		if (qe < s || e < qs) return INF;
		if (qs <= s && e <= qe) return data[n];
		const int m = (s + e) >> 1;
		return min(query(qs, qe, n << 1, s, m)
			 , query(qs, qe, (n << 1) + 1, m + 1, e));
	}

public:
	Segtree_Min(int n): n(n) {
		data = new ll[4 * n + 1]();
	}
	~Segtree_Min() {
		delete []data;
		data = nullptr;
	}
	void build(vector<ll>& arr){
		this->build(arr, 1, 1, this->n);
	}
	void update(int i, ll x) {
		this->update(i, x, 1, 1, this->n);
	}
	ll query(int s, int e) {
		return this->query(s, e, 1, 1, this->n);
	}
};

void solve() {
	ll N, M; cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	Segtree_Min tree(N);
	tree.build(A);
	ll a, b, c;

	while (M--) {
		cin >> a >> b >> c;
		if (a == 1) tree.update(b, c);
		else cout << tree.query(b, c) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();	
	return 0;
}