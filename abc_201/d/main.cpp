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

const int inf = INT_MAX / 2;
int H, W;
string A[2020];
//---------------------------------------------------------------------------------------------------
bool vis[2020][2020];

// ミニマックス法 = 自分は利得を最大化し、相手は利得を最小化する
// dp(x, y) := 駒が(x,y)にあるときの「高橋君の点数-青木君の点数」の最適値
// 高橋君のターンなら最大化、青木君のターンならこの値を最小化するように動かす
int memo[2020][2020];
int dp(int x, int y) {
  // 既に計算済みならメモを返す
  if (vis[y][x]) return memo[y][x];
  vis[y][x] = true;

  int turn = (x + y) % 2;

  // もし終端なら0を返す、終わりなので0を返す
  if (x == W - 1 && y == H - 1) return memo[y][x] = 0;
  // 偶数ならTakahashiのターン
  if (turn == 0) {
    // Takahashi
    // まずは非常に小さい値を入れておく
    memo[y][x] = -inf;
    // 下端ではないなら、下に移動して、その後の最適値を計算する
    if (y < H - 1) chmax(memo[y][x], dp(x, y + 1) + (A[y + 1][x] == '+' ? 1 : -1));
    // 右端ではないなら、右に移動して、その後の最適値を計算する
    if (x < W - 1) chmax(memo[y][x], dp(x + 1, y) + (A[y][x + 1] == '+' ? 1 : -1));
  }
  else {
    // Aoki
    // まずは非常に大きい値を入れておく
    memo[y][x] = inf;
    // 下端ではないなら、下に移動して、その後の最適値を計算する
    // 青木の点数はマイナスになるので、+なら引くようにしている
    if (y < H - 1) chmin(memo[y][x], dp(x, y + 1) - (A[y + 1][x] == '+' ? 1 : -1));
    // 右端ではないなら、右に移動して、その後の最適値を計算する
    // 青木の点数はマイナスになるので、+なら引くようにしている
    if (x < W - 1) chmin(memo[y][x], dp(x + 1, y) - (A[y][x + 1] == '+' ? 1 : -1));
  }
  // 再帰的に計算した結果を返す
  return memo[y][x];
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> H >> W;
  rep(y, H) cin >> A[y];

  int opt = dp(0, 0);
  // optが正ならTakahashiの勝ち
  if (0 < opt) cout << "Takahashi" << endl;
  else if (opt == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
}