// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int prize(int num) {
  if (num == 3) return 100000;
  if (num == 2) return 200000;
  if (num == 1) return 300000;
  return 0;
}
int main()
{
  int X, Y;
  cin >> X >> Y;
  int ans = 0;
  ans += prize(X);
  ans += prize(Y);
  if (X == 1 && Y == 1) ans += 400000;
  cout << ans << endl;
}