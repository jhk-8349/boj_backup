// BOJ 10844: 쉬운 계단 수
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

int mod = 1000000000;
int dp[101][10] = {}; // dp[digit][last digit]

void solve() {
    int N; cin >> N; N;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % mod;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
        dp[i][9] = dp[i - 1][8] % mod;
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % mod;
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