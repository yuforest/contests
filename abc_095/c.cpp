#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep_ex(i, n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;

  ll ans = 0;
  if (A+B >= C) {
    int min_num = min(X, Y);
    ans += C * min_num;
    X -= min_num;
    Y -= min_num;
  }
  if (A >= C) {
    ans += C * X;
    X = 0;
    Y -= X;
  }
  if (B >= C) {
    ans += C * Y;
    Y = 0;
    X -= Y;
  }
  if (X < 0) {
    X = 0;
  }
  if (Y < 0) {
    Y = 0;
  }
  ans += A * X;
  ans += B * Y;
  cout << ans << endl;
}