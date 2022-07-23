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

int main(void)
{
  ll x;
  cin >> x;

  ll ans = 0;
  ans += (x / 11) * 2;
  x -= 11 * (x / 11);
  if (x > 0 && x % 11 <= 6) {
    ans += 1;
  }
  if (x > 0 && x % 11 > 6) {
    ans += 2;
  }
  cout << ans << endl;
}