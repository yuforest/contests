// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int W, H, x, y;
  cin >> W >> H >> x >> y;
  double ans1 = 1.0 * W * H / 2.0;
  int ans2 = 0;
  if (x * 2 == W && y * 2 == H) ans2 = 1;
  cout << fixed << setprecision(7) << ans1 << " ";
  cout << ans2 << endl;
}