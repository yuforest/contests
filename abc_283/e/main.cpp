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

long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

constexpr int inf = 1000000010;
// O(HW)
int main() {
  // 入力
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  // h*2*2のdp配列、値はinfで初期化
  // dp[i][j][k]をi行目までについて操作を行うかを確定して、
  // jをi−1 行目に対して操作を行ったか、
  // kをi行目に対して操作を行ったかを表すflagとしたときに
  // i−1行目までに孤立した要素が存在しなくなるという条件を満たすために必要な操作回数の最小値
  vector<vector<vector<int>>> dp(h, vector<vector<int>>(2, vector<int>(2, inf)));
  // 0行目に対して操作を行わないので操作回数は0回
  dp[0][0][0] = 0;
  // 0行目に対して操作を行うので操作回数は1回
  dp[0][0][1] = 1;
  // 1からh-1まで見ていく
  for (int i = 1; i < h; i++) {
    rep(j, 2) {
      rep(k, 2) {
        // i行目に対して操作を行うかどうか
        rep(l, 2) {
          // wの長さの要素が-1の配列
          vector<int> x(w, -1);
          // iが2以上の時は2つ前の配列を入れる
          if (i != 1) x = a[i - 2];

          // i-2行目の配列をjが1なら反転させる
          // i=1の時は全ての要素が2になる
          if (j) rep(m, w) x[m] = 1 - x[m];

          // i-1行目の配列をコピーしてkが1なら反転させる
          // この前後の行の配列しか孤立には関係ない
          vector<int> y = a[i - 1];
          if (k) rep(m, w) y[m] = 1 - y[m];

          // i行目の配列をコピーしてlが1なら反転させる
          vector<int> z = a[i];
          if (l) rep(m, w) z[m] = 1 - z[m];

          bool ok = true;
          // iが1からh-1に対してi-1行目を見る
          // つまり0からh-2業目に対する確認
          rep(m, w) {
            // 上下左右の4方向を探索して
            // 孤立している場合はokをfalseにする
            if (
              x[m] != y[m] && y[m] != z[m] &&
              (m == 0 || y[m] != y[m - 1]) &&
              (m == w - 1 || y[m] != y[m + 1])
            ) {
              ok = false;
            }
          }
          // iがh-1の時はzを基準にして
          // 上、左右に対する孤立の確認を行う
          // h-1の時は上のh-2に対する確認と、このh-1に対する確認が走る
          if (i == h - 1) {
            rep(m, w) {
              if (
                z[m] != y[m] &&
                (m == 0 || z[m] != z[m - 1]) &&
                (m == w - 1 || z[m] != z[m + 1])
              ) {
                ok = false;
              }
            }
          }
          // okなら更新する
          // lはi行目に対して操作を行うかどうか
          // i行目まで操作を行うかどうかを確定し、
          // i-1行目まで操作を行うかどうか確定し、i-2行目に対して操作を行なったかをjとし
          // i-1行目に対して操作を行なったかをkとする時にi行目で操作を行なったかどうかで遷移する
          if (ok) chmin(dp[i][k][l], dp[i - 1][j][k] + l);
        }
      }
    }
  }
  debug(dp);
  int ans = inf;
  rep(j, 2) rep(k, 2) chmin(ans, dp[h - 1][j][k]);
  cout << (ans == inf ? -1 : ans) << '\n';
}