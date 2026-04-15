#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

const int INF = 1e18;
const int MOD = 1e9+7;

int start(int a, int m) {
    if (a % m) return m - (a % m);
    else return 0;
}

void solve() {
    int a, b; cin >> a >> b;
    int rng = b - a + 1;    
    vector<bool> sieve(b - a + 1, true);

    for (int i = start(a, 4); i < rng; i += 4) sieve[i] = false;
    
    int i = 3, sq;
    while (i * i <= b) {
        sq = i * i;
        for (int j = start(a, sq); j < rng; j += sq) sieve[j] = false;
        i += 2;
    }
    int ans = 0;
    for (auto x : sieve) if (x) ans++;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}