// BOJ 1316: 그룹 단어 체커
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

int n = 0;
void solve() {
	int arr[26] = {};
	string s; cin >> s;
	int len = s.length();
	bool flag = true;
	for (int i = 1; i < len; i++) {
		if (s[i - 1] == s[i]) continue;
		if (arr[s[i - 1] - 'a']) {
			flag = false;
			break;
		}
		arr[s[i - 1] - 'a']++;
	}
	if (arr[s[len - 1] - 'a']) flag = false;
	if (flag) n++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) solve();
	cout << n;
	return 0;
}