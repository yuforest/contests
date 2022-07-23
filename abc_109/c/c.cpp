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
// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main(void)
{
  ll N, X;
  cin >> N >> X;
  ll x[N];
  rep(i, N) {
    cin >> x[i];
  }
  ll diff[N];
  rep(i, N) {
    diff[i] = abs(x[i] - X);
  }
  int ans = diff[0];
  rep(i, N) {
    ans = gcd(ans, diff[i]);
  }
  cout << ans << endl;
}