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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

int H, W;
char c[20][20];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool used[20][20];

// DFS(再帰関数)によるバックトラッキング
int dfs(int sx, int sy, int px, int py) {
  // スタート地点に2回目訪問したら0を返す
  if (sx == px && sy == py && used[px][py] == true) return 0;
  // 現在位置を訪問済みに
  used[px][py] = true;

  // あり得ない小さな値を設定しておくことで
  // 山が始点になった場合に小さな値が最終的な答えとなり
  // 実現不可能となる、場合分けの省略ができる
  int ret = -10000;
  // 4方向探索
  for (int i = 0; i < 4; i++) {
    // 次の位置
    int nx = px + dx[i], ny = py + dy[i];
    // 範囲外や山は探索しない
    if (nx < 1 || ny < 1 || nx > H || ny > W || c[nx][ny] == '#') continue;
    // 始点を除いて、次が探索済みの時はcontinue
    if ((sx != nx || sy != ny) && used[nx][ny] == true) continue;
    // 探索する
    int v = dfs(sx, sy, nx, ny);
    // 今の値と探索結果に1を足したものの大きい方をとる、1は次のマスへの移動を表す
    // 途中で探索できるところがなくなった場合は-10000が返るので
    // 最終的な答えもマイナスになり実現不可能となる
    ret = max(ret, v + 1);
  }
  // 現在位置を未訪問に戻す
  used[px][py] = false;
  // 現在位置を始点とするルートの通るマス数で最大のものを返す
  return ret;
}

int main() {
  // Step #1. Input
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) cin >> c[i][j];
  }

  // Step #2. DFS
  // 全てのマスを探索しながら最大値を更新していく
  int Answer = -1;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      // スタート地点と現在の位置を表す
      int val = dfs(i, j, i, j);
      debug(val);
      Answer = max(Answer, val);
    }
  }
  // もしも答えが2より小さければ条件を満たさない
  if (Answer <= 2) Answer = -1;
  // 出力
  cout << Answer << endl;
  return 0;
}