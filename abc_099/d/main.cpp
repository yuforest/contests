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

int N, C, D[30][30], c[505][505];
int pre[3][30];

// (x+y)%3の0,1,2の3種類の色の組み合わせを全て全探索
int main() {
  // 入力
  cin >> N >> C;
  rep(y, C) rep(x, C) cin >> D[y][x];
  // 0-indexedにする
  rep(y, N) rep(x, N) cin >> c[y][x], c[y][x]--;

  // 違和感計算を前計算しておく
  // pre[pat][col] := (x+y)%3=patであるマス全てをcol色にしたときの違和感の総和
  // D[c[y][x]][col]は、(y,x)のマスをcol色にしたときの違和感
  rep(col, C) rep(y, N) rep(x, N) pre[(y + x) % 3][col] += D[c[y][x]][col];

  int ans = INT_MAX / 2;
  // 色を全探索する
  rep(c0, C) rep(c1, C) rep(c2, C) {
    // 3色は違う色
    if (c0 == c1) continue;
    if (c0 == c2) continue;
    if (c1 == c2) continue;
    // 3色の組み合わせに対して、違和感の総和を計算する
    // 0の色はc0, 1の色はc1, 2の色はc2とする時のコストで最小値更新
    chmin(ans, pre[0][c0] + pre[1][c1] + pre[2][c2]);
  }
  cout << ans << endl;
}