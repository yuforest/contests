#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep_ex(i, n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll X;
  cin >> X;
  vector<ll> sum(50001, 0);
  rep(i, 50001) {
    if (i == 0) {
      sum.at(i) = 0;
    } else {
      sum.at(i) = sum.at(i-1) + i;
    }
  }
  ll ans;
  rep(i, 50001) {
    if (X <= sum.at(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}