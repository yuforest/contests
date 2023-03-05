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
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
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

using mint=modint1000000007;

using vmint = vector<mint>;
using vvmint = vector<vmint>;


int main() {
  ll H, W;
  cin >> H >> W;
  vs S(H);
  rep(i, H) cin >> S[i];
  // dp[i][j] = dp[i][j-1] + dp[i][j-2] + ...
  //          + dp[i-1][j] + dp[i-2][j] + ...
  //          + dp[i-1][j-1] + dp[i-2][j-2] + ...
  // というDPの遷移を考えると求められる
  // 愚直にやるとO(HW(H+W))となりTLEする
  // それぞれの方向に関して累積和を求めながらDPすることで高速化できる
  vvmint dp(H, vmint(W, 0));
  vvmint x(H, vmint(W, 0));
  vvmint y(H, vmint(W, 0));
  vvmint z(H, vmint(W, 0));
  dp[0][0] = 1;
  rep(i, H) rep(j, W) {
    if (i == 0 && j == 0) continue;
    if (S[i][j] == '#') continue;
    // それぞれの累積和配列を作る
    // 左からの遷移
    if (j > 0) x[i][j] = x[i][j-1] + dp[i][j-1];
    // 上からの遷移
    if (i > 0) y[i][j] = y[i-1][j] + dp[i-1][j];
    // 左上からの遷移
    if (i > 0 && j > 0) z[i][j] = z[i-1][j-1] + dp[i-1][j-1];
    dp[i][j] = x[i][j]+y[i][j]+z[i][j];
    debug(i);
    debug(j);
    debug(dp[i][j].val());
  }
  cout << dp[H-1][W-1].val() << endl;
}