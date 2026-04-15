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

struct Point {
    ll x;
    ll y;
};

ll taxi_d(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
    int N; cin >> N;
    Point s, e;
    cin >> s.x >> s.y >> e.x >> e.y;
    ll best_dist = 10e18, OEM;
    for (int i = 1; i <= N; i++) {
        ll M, dist = 0; cin >> M;
        vector<Point> p(M + 2);
        p[0] = s; p[M + 1] = e;
        for (int j = 1; j <= M; j++) {
            cin >> p[j].x >> p[j].y;
        }

        for (int j = 0; j <= M; j++) {
            dist += taxi_d(p[j], p[j + 1]);
        }
        if (dist < best_dist) {
            OEM = i;
            best_dist = dist;
        }
    }
    cout << OEM << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}