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

  ll N, K;
  cin >> N >> K;

  if (K == 0) {
    ll ans = N * N;
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;
  // bを固定して考える
  // bがK以下の場合は剰余がK以上となることはないので、b=[K+1,N]で全探索する。
  rep3(b, K + 1, N + 1) {
    // N以下で範囲が全て入る最大のnを計算(このとき0も考えるので1を足している)
    ll n = (N + 1) / b;
    // b個ある区間内の要素のうち、あまりがK以上になるのはb-K個
    ll d = 1LL * (b - K) * n;

    // n+1の範囲の途中でNがあり、一部条件をみたす場合がある
    // Lはnまでの区間と
    ll L = K + b * n;
    ll R = N;
    if (L <= R) d += R - L + 1;

    ans += d;
  }

  cout << ans << endl;

  return 0;
}