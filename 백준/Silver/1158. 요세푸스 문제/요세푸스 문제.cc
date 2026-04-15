#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t; cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    cout << '<';
    while (q.size() != 1) {
        for (int i = 1; i < k; i++) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        t = q.front();
        q.pop();
        cout << t << ", ";
    }
    cout << q.front() << '>';
    return 0;
}