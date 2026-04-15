// BOJ 10986: 나머지 합
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
    ll N, M; cin >> N >> M;
    ll pref = 0, foo, mod[1000] = {1,};
    for (int i = 0; i < N; i++) {
        cin >> foo;
        pref = (pref + foo) % M;
        mod[pref]++;
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ans += mod[i] * (mod[i] - 1) / 2;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}