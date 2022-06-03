#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << endl;
  } else {
    int ans = 3 - x - y;
    cout << ans << endl;
  }
}