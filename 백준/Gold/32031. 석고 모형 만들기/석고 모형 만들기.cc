#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

vector<int> par;

int find_root(int x) {
    if (x == par[x]) return x;
    return par[x] = find_root(par[x]);
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) {
        par[y] = x;
    }
}

// index 규칙: (C * i + j) * 8 + 꼭짓점
int R, C; 
void func(int i, int j, char d) {
    // d == H: 01/23/45/67
    // d == O: 04/15/26/37
    // d == I: 03/12/47/56
    int N = (C*i+j)*8;
    if (d == 'H') {
        union_root(N+0, N+1);
        union_root(N+2, N+3);
        union_root(N+4, N+5);
        union_root(N+6, N+7);
    } else if (d == 'O') {
        union_root(N+0, N+4);
        union_root(N+1, N+5);
        union_root(N+2, N+6);
        union_root(N+3, N+7);
    } else if (d == 'I') {
        union_root(N+0, N+3);
        union_root(N+2, N+1);
        union_root(N+4, N+7);
        union_root(N+6, N+5);
    }
    
    for (int k = 0; k < 8; k++) {
        switch (k)
        {
        case 0:
            if (j != 0) union_root(N+0, N-8+1);
            if (i != R - 1) union_root(N+0, N+C*8+3);
            break;
        case 1:
            if (j != C - 1) union_root(N+1, N+8+0);
            if (i != R - 1) union_root(N+1, N+C*8+2);
            break;
        case 2:
            if (j != C - 1) union_root(N+2, N+8+3);
            if (i != 0) union_root(N+2, N-C*8+1);
            break;        
        case 3:
            if (j != 0) union_root(N+3, N-8+2);
            if (i != 0) union_root(N+3, N-C*8+0);
            break;
        case 4:
            if (j != 0) union_root(N+4, N-8+5);
            if (i != R - 1) union_root(N+4, N+C*8+7);
            break;
        case 5:
            if (j != C - 1) union_root(N+5, N+8+4);
            if (i != R - 1) union_root(N+5, N+C*8+6);
            break;
        case 6:
            if (j != C - 1) union_root(N+6, N+8+7);
            if (i != 0) union_root(N+6, N-C*8+5);
            break;        
        case 7:
            if (j != 0) union_root(N+7, N-8+6);
            if (i != 0) union_root(N+7, N-C*8+4);
            break;                        
        default:
            break;
        }
    }
}

void solve() {
    cin >> R >> C;
    int N = R * C;
    par.assign(N * 8, 0);
    
    for (int i = 0; i < N * 8; i++) {
        par[i] = i;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char d; cin >> d;
            func(i, j, d);
        }
    }
    
    set<int> s;
    for (int i = 0; i < N * 8; i++) {
        s.insert(find_root(i));
    }

    cout << s.size() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}