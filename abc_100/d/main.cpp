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

int N, M; ll X[1010], Y[1010], Z[1010];
ll dp[1010][1010];
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> N >> M;
  rep(i, N) cin >> X[i] >> Y[i] >> Z[i];

  ll ans = -1e18;
  // -1と1のときをそれぞれ試す(0は試さない)
  // 最小、最大の組み合わせ
  // 2^3=8通り
  // 最後に-1を掛けると最適である可能性があるので、各要素について*(-1)をするかどうかの可能性がある
  rep3(a, -1, 2) rep3(b, -1, 2) rep3(c, -1, 2) if (a) if (b) if (c) {
    // 配列の初期化
    rep(i, N + 1) rep(j, M + 1) dp[i][j] = -1e18;
    dp[0][0] = 0;
    // DP
    rep(i, N) rep(j, M + 1) {
      ll d = a * X[i] + b * Y[i] + c * Z[i];
      chmax(dp[i + 1][j], dp[i][j]);
      chmax(dp[i + 1][j + 1], dp[i][j] + d);
    }
    // 答えを更新
    chmax(ans, dp[N][M]);
  }
  cout << ans << endl;
}