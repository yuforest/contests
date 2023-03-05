// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int main() {
  ll N;
  cin >> N;
  map<ll, ll> mp;
  rep3(i, 2, N+1) {
    ll tmp = i;
    for (ll j = 2; j * j <= tmp; j++) {
      while (tmp % j == 0) {
        mp[j]++;
        tmp /= j;
      }
    }
    if (tmp != 1) mp[tmp]++;
  }
  debug(mp);
  ll ans = 0;
  // 75
  rep3(i, 2, N+1) if (mp[i] >= 74) ans++;

  // 25 * 3
  rep3(i, 2, N+1) rep3(j, 2, N+1) {
    if (i != j && mp[i] >= 24 && mp[j] >= 2) ans++;
  }
  // 15 * 5
  rep3(i, 2, N+1) rep3(j, 2, N+1) {
    if (i != j && mp[i] >= 14 && mp[j] >= 4) ans++;
  }
  // 5 * 5 * 3
  rep3(i, 2, N+1) rep3(j, i+1, N+1) rep3(k, 2, N+1) {
    if (mp[i] >= 4 && mp[j] >= 4 && mp[k] >= 2 && i != k && j != k) ans++;
  }
  cout << ans << endl;
}