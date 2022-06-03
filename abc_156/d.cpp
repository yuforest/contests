#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (b)-1; i >= (a); --i)
using namespace std;
using P = pair<int, int>;

const ll MOD = ll(1e9) + 7;

// int num_of_combination(int n, int r) {
//   int num = 1;
//   for (int i = 1; i <= r; i++) {
//     num = num * (n - i + 1) / i;
//   }
//   return num;
// }

const ll MAX = ll(1e9);

ll fact[MAX], fact_inv[MAX];

// 繰り返し二乗法
ll power(ll a, ll b)
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

ll comb(ll n, ll r) {
  return (fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD;
}

int main()
{
  ll n, a, b;
  cin >> n >> a >> b;

  int ans = 0;

  fact[0] = 1;
  rep(i, n) fact[i + 1] = fact[i] * (i + 1) % MOD;
  fact_inv[n] = power(fact[n], MOD - 2);
  // 逆元の計算
  FORR(i, 0, n) fact_inv[i] = fact_inv[i + 1] * (i + 1) % MOD;

  for (ll i = 1; i <= n; i++) {
    if (i == a) {
      continue;
    }
    if (i == b) {
      continue;
    }
    // cout << comb(n, i) << endl;
    ans += comb(n, i) % MOD;
  }
  cout << ans << endl;
  // cout << ans % MOD << endl;
}