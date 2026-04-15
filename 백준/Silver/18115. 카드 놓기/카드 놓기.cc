#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N + 1);
    deque<int> card;
    for (int i = 1; i <= N; i++) cin >> A[N - i + 1];
    
    for (int i = 1; i <= N; i++) {
      switch (A[i]){
        case 1: {
          card.push_front(i);
          break;
        }
        case 2: {
          int x = card.front();
          card.pop_front();
          card.push_front(i);
          card.push_front(x);
          break;
        }
        case 3: {
          card.push_back(i);
          break;
        }
      }
    }
    
    for (auto x : card) cout << x << ' ';
    
    return 0;
}