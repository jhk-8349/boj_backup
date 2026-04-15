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

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
    int l; cin >> l;
    vector<vector<int>> board(l, vector<int>(l, -1));
    pii s, e;
    cin >> s.F >> s.S >> e.F >> e.S;
    board[s.F][s.S] = 0;
    queue<pii> q; q.push(s);
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        if (cur.F == e.F && cur.S == e.S) {
            cout << board[cur.F][cur.S] << endl;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int x = cur.F + dx[i], y = cur.S + dy[i];
            if (0 > x || x >= l || 0 > y || y >= l || board[x][y] != -1) continue;
            board[x][y] = board[cur.F][cur.S] + 1;
            q.push({x, y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}