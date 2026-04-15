#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, t; cin >> N;
  vector<int> dist(N + 1, 1234567891);
  vector<bool> visited(N + 1, false);
  vector<vector<int>> graph(N + 1);
  for (int i=1;i<=N;i++) {
    cin >> t;
    graph[t].push_back(i);
  }
  
  dist[N] = 0; visited[N] = 1;
  queue<int> q; q.push(N);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : graph[cur]) {
      if (!visited[nxt]) {
        dist[nxt] = dist[cur] + 1;
        visited[nxt] = 1;
        q.push(nxt);
      }
    }
  }
  
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) cout << -1 << "\n";
    else cout << dist[i] << "\n";
  }
  return 0;
}