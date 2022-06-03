#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int X;
  cin >> X;
  int ans = 0;
  int devide_500 = X / 500;
  if (devide_500 > 0) {
    ans += devide_500 * 1000;
    X -= devide_500 * 500;
  }
  int devide_5 = X / 5;
  if (devide_5 > 0) {
    ans += devide_5 * 5;
    X -= devide_5 * 5;
  }
  cout << ans << endl;
}