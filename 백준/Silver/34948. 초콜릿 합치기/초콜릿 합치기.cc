#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) return a.second > b.second;
  else return a.first > b.first;
}

int main() {
  int N; cin >> N;
  vector<long long> H(N), W(N);
  vector<pair<long long,long long>> choco(N);
  for (int i = 0; i < N; i++) cin >> H[i];
  for (int i = 0; i < N; i++) {
    long long w; cin >> w;
    choco[i] = make_pair(H[i], w);
  }
  
  sort(choco.begin(), choco.end(), compare);
  
  H[0] = choco[0].first;
  W[0] = choco[0].second;
  
  for (int i = 1; i < N; i++) {
    H[i] = choco[i].first;
    W[i] = choco[i].second + W[i-1];
  }

  vector<long long> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = H[i] * W[i];
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
}