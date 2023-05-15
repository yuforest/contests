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

constexpr ll INF = 1e18;
const int MX = 3010;

// dp[i][j][k] := (i, j) までの最大値で、今の行でk個取ったときの最大値
ll dp[MX][MX][4];
ll v[MX][MX];

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  rep(i, K) {
    int r, c, val;
    cin >> r >> c >> val;
    --r, --c;
    // 価値を記録
    v[r][c] = val;
  }
  // 初期化
  rep(i, MX) rep(j, MX) rep(k, 4) dp[i][j][k] = -INF;
  dp[0][0][0] = 0;

  rep(i, R) {
    rep(j, C) {
      // これは、この行で取れるかどうかを考える(0,1,2個のとき新たに取れる)
      for (int k = 2; k >= 0; --k) {
        // 遷移できれば最大値更新
        // kを増やさない時は取らないということ
        if (dp[i][j][k] >= 0) {
          chmax(dp[i][j][k + 1], dp[i][j][k] + v[i][j]);
        }
      }
      rep(k, 4) {
        if (dp[i][j][k] >= 0) {
          // 次の行への遷移
          if (i + 1 < R) {
            // 取った個数は0にリセット
            chmax(dp[i + 1][j][0], dp[i][j][k]);
          }
          // 次の列への遷移
          if (j + 1 < C) {
            // 取った個数はそのまま
            chmax(dp[i][j + 1][k], dp[i][j][k]);
          }
        }
      }
    }
  }
  // debug(dp);

  ll ans = -INF;
  // 最後まできた時に、k個取っている最大値を探す
  rep(k, 4) chmax(ans, dp[R - 1][C - 1][k]);
  cout << ans << endl;

  return 0;
}