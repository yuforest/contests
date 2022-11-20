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

bool vis[55][55];
int dp[55][55];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int main() {
  int H, W;
  cin >> H >> W;
  int sx, sy;
  int gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--;
  sy--;
  gx--;
  gy--;
  string S[H];
  rep(i, H) cin >> S[i];
  queue<pair<int, int>> que;
  que.push({ sx, sy });
  vis[sx][sy] = true;
  dp[sx][sy] = 0;
  // 幅優先探索
  while (!que.empty()) {
    auto q = que.front();
    que.pop();
    int x, y;
    tie(x, y) = q;

    rep(i, 4) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 0 || xx >= H) continue;
      if (yy < 0 || yy >= W) continue;
      if (vis[xx][yy] == true) continue;
      if (S[xx][yy] == '#') continue;
      // 他の探索経路から同じ場所を探索してしまうことがあるので
      // この時点で訪問済みにして距離も入れておくと良い
      dp[xx][yy] = dp[x][y] + 1;
      vis[xx][yy] = true;
      que.push({xx, yy});
    }
  }
  cout << dp[gx][gy] << endl;
  return 0;
}