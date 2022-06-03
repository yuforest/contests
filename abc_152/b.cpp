#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b;
  cin >> a >> b;
  string ans = "";
  if (a <= b) {
    rep(i, b) {
      ans += to_string(a);
    }
  } else {
    rep(i, a) {
      ans += to_string(b);
    }
  }
  cout << ans << endl;
}