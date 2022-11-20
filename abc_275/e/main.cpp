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

using mint = atcoder::modint998244353;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector dp(k + 1, vector(n + 1, mint(0)));
  // 1/mの逆元
  // これを掛けることによってmで割ってmodであまりを取ったのと同じになる
  mint m_inv = mint(1) / m;
  // 0回ルーレットを回した時に0にいる確率は100％なのは自明
  dp[0][0] = 1;
  // k回が上限でi回ルーレットを回す
  for(int i = 0; i < k; i++) {
    // 0からNまでのマスにいることが考えられる
    for(int j = 0; j <= n; j++) {
      // 最後のマスに到達したら双六終了なのでゴールできる確率は次もゴール時の確率を入れる？
      if(j == n) {
        dp[i + 1][j] += dp[i][j];
        continue;
      }
      // この状態からの遷移、1からmまでの進む値をとりうる
      for(int l = 1; l <= m; l++) {
        // 次のマス
        int nx = j + l;
        // 次のマスがnを超えたら、
        // 超えた分だけnから引き返す
        if(nx > n) nx = n - (nx - n);
        // そのマスにいる可能性を計算する
        // 今のマスに1/m(の代わりにその逆元)を掛けたものを
        // 次のマスの確率に足す
        // 例えばdp[1][1]は1回ルーレットを回した時に、1のマスにいる確率を表す
        dp[i + 1][nx] += dp[i][j] * m_inv;
      }
    }
  }
  // 答えを出力
  cout << dp.back().back().val() << endl;
}