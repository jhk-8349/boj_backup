#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define endl '\n'
#define fi first 
#define se second 
#define pb push_back 
#define all(x) x.begin(),x.end()

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int MAX = 1e18;
const int MOD = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vi h(n), w(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        h[i] = max(a, b);
        w[i] = min(a, b);
    }
    cout << *max_element(h.begin(), h.end()) * *max_element(w.begin(), w.end()) << endl;
}