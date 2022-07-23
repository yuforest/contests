// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M, X, T, D;
  cin >> N >> M >> X >> T >> D;
  if (M >= X) {
    cout << T << endl;
  } else {
    int ans = max(1, T - D * (X-M));
    cout << ans << endl;
  }
  return 0;
}