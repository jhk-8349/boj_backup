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

const int INF = 1e18;
const int MOD = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N; cin >> N;
    map<char, int> m;
    for (int i = 0; i < N; i++) {
      char c; cin >> c;
      m[c]++;
    }
    char a; cin >> a;
    cout << m[a] << endl;
}