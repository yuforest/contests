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
using ll = long long;

int main(void)
{
  ll N, T;
  cin >> N >> T;
  ll t[N];
  rep(i, N) {
    cin >> t[i];
  }
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (t[i] - t[i-1] >= T) {
      ans += T;
    } else {
      ans += t[i] - t[i-1];
    }
  }
  ans += T;
  cout << ans << endl;
  return 0;
}