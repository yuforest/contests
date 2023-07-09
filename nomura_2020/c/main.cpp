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

#define yes "Yes"
#define no "No"


// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
const ll INF = ll(1e18);

int main() {
  int N;
  cin >> N;
  vl A(N + 1);
  vl suf(N + 2);
  for (int i = 0; i <= N; ++i) cin >> A[i];

  // 深さ0の時
  if (N == 0) {
    if (A[0] == 1) {
      cout << 1 << endl;
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  // それ以外の時は深さ0の値は0である必要がある
  if (A[0] > 0) {
    cout << -1 << endl;
    return 0;
  }

  // 木の下から見た時の深さiまでの葉の和を計算する
  for (int i = N; i >= 0; --i) {
    suf[i] = suf[i + 1] + A[i];
  }

  // xは深さd-1の頂点のうち葉ではないものの個数
  ll x = 1;
  // ansは頂点数の合計
  ll ans = 1;

  for (int i = 1; i <= N; ++i) {
    // 深さd-1の頂点の中で葉ではないものを2倍しても
    // 深さdの葉の数より少ない場合は不可能
    if (x * 2 < A[i]) {
      cout << -1 << endl;
      return 0;
    }
    // 深さdの頂点数の最大値は深さd-1の葉ではない頂点の2倍と
    // 下から見た時の葉の数の和の小さい方
    ll d = min(x * 2, suf[i]);
    debug(d);
    ans += d;
    // 頂点数の合計から葉であるものを引く
    x = d - A[i];
  }
  debug(suf);

  cout << ans << endl;

  return 0;
}