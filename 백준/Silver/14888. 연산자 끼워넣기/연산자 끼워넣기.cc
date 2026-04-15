// BOJ 14888: 연산자 끼워넣기
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

int N, A[11], pmtd[4];
vector<int> oprt;
int max_val = INT_MIN, min_val = INT_MAX;

void rec() {
    if (oprt.size() == N - 1) {
        int ans = A[0], j = 1;

        for (auto x : oprt) {
            if (x == 0) ans += A[j];
            else if (x == 1) ans -= A[j];
            else if (x == 2) ans *= A[j];
            else ans /= A[j];
            j++;
        }

        if (ans > max_val) max_val = ans;
        if (ans < min_val) min_val = ans;
    } else {
        for (int i = 0; i < 4; i++) {
            if (pmtd[i]) {
                pmtd[i]--;
                oprt.push_back(i);
                rec();
                oprt.pop_back();
                pmtd[i]++;
            }
        }
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> pmtd[i];
    
    rec();

    cout << max_val << endl;
    cout << min_val << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 1; //cin >> T;
    while (T--) solve();
    return 0;
}