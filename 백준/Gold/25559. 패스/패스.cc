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
const int INF = (~0U >> 2);

void solve() {
    int N; cin >> N;
    if (N % 2) {
        if (N == 1) cout << 1;
        else cout << -1;
    }
    else {
        cout << N << ' ';
        for (int i = 1; i < N; i++) {
            if (i % 2) cout << i;
            else cout << N - i;
            if (i != N - 1) cout << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}