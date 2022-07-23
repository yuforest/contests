// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

ll nCk(ll n, ll k) {
    ll x = 1; // n!の初期値
    ll y = 1; // (n-k)!の初期値
    ll z = 1; // k!の初期値

    rep(i, n) x *= n - i; // n!を計算
    rep(i, n - k) y *= n - k - i; // (n-k)!を計算
    rep(i, k) z *= k - i; // k!を計算

    return (x / (y * z)); // 定義通りに計算
}

int main(void)
{
  ll N, P;
  cin >> N >> P;
  ll A[N];
  ll odd_count = 0;
  rep(i, N) {
    cin >> A[i];
    if (A[i] % 2 == 1) {
      odd_count++;
    }
  }
  if (odd_count == 0) {
    if (P == 1) {
      cout << 0 << endl;
    } else {
      cout << setprecision(18) << pow(2, N) << endl;
    }
    return 0;
  }
  ll ans = pow(2, N-1);
  cout << setprecision(18) << ans << endl;
  return 0;
}