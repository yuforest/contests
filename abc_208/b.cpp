#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int P;
  cin >> P;
  vector<int> coins(11, 0);
  for (int i = 1; i <= 10; ++i) {
    if (i == 1) {
      coins.at(i) = 1;
      continue;
    }
    coins.at(i) = coins.at(i-1) * i;
    // cout << coins.at(i) << endl;
  }
  // cout << P << endl;
  int ans = 0;
  while (true) {
    // cout << P << endl;
    for (int i = 10; i >= 1; i--) {
      // cout << coins.at(i) << endl;
      if (P >= coins.at(i))
      {
        ans++;
        P -= coins.at(i);
        // cout << P << endl;
        break;
      }
    }
    if (P == 0) {
      break;
    }
  }
  cout << ans << endl;
}

