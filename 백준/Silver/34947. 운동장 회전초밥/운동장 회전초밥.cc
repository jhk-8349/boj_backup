#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T; cin >> N >> T;
  double R, D, theta, w; cin >> R >> D >> theta >> w;
  theta *= (M_PI / 180);
  w /= 100;
  double d_3 = 2 * (  (R - w/2) * theta + D - w*cos(theta/2) );
  double d_2 = 2 * (  (R - 3*w/2) * theta + D - 3*w*cos(theta/2)   );
  double d_1 = 2 * (  (R - 5*w/2) * theta + D - 5*w*cos(theta/2)   );
  
  cout << fixed;
  cout.precision(9);
  cout << (d_3-d_1) * N/T << endl;
  cout << (d_3-d_2) * N/T << endl;
  return 0;
}