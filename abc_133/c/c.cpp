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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll L, R;
  cin >> L >> R;
  ll ans = 2018;
  for (ll i = L; i < R; i++) {
    for (ll j = L+1; j < R+1; j++) {
      ans = min(ans, (i * j) % 2019);
      if (ans == 0) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}