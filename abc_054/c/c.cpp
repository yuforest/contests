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
  ll N, M;
  cin >> N >> M;
  ll ans = 0;
  if (N > 0) {
    ll val = min(N, M / 2);
    ans += val;
    N -= val;
    M -= 2 * val;
  }
  if (M > 0) {
    ans += M / 4;
  }
  cout << ans << endl;
}