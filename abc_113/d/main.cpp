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
using vvvl = vector<vector<vector<ll>>>;
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

using mint = modint1000000007;
int H, W, K;
mint dp[101][8];
// どの2つの横棒も端点を共有しないかを調べる
int check(int msk) {
  rep(i, W - 2) {
    int a = (msk >> i) & 1;
    int b = (msk >> (i + 1)) & 1;
    // どちらも1なら実現不可能
    if (a and b) return 0;
  }
  return 1;
}
int main() {
  cin >> H >> W >> K;
  K--;

  // dp[h][k] := 高さhまであみだくじを構築していて、0本目の縦棒がk本目に遷移する組み合わせ
  // 1 << (W - 1)はW-1個の間に線を引くかどうかの2進数表現
  dp[0][0] = 1;
  // 高さごとに横幅を全探索
  // その中で線を引くかどうかを全探索して、適切な線の引き方の時だけ遷移するようにする
  rep(h, H) rep(k, W) rep(msk, 1 << (W - 1)) if (check(msk)) {
    // k番目に線がある場合、次の高さではk+1番目に遷移する
    if (msk & (1 << k)) dp[h + 1][k + 1] += dp[h][k];
    // kが0以上でk-1番目に線がある場合、次の高さではk-1番目に遷移する
    else if (0 < k and msk & (1 << (k - 1))) dp[h + 1][k - 1] += dp[h][k];
    // それ以外の場合は次の高さではそのままk番目に遷移する
    else dp[h + 1][k] += dp[h][k];
  }
  // 最後の高さでK番目に遷移する組み合わせを出力
  cout << dp[H][K].val() << endl;
}