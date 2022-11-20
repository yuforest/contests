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

// x の偶奇による
int dx[2][6] = {
    {1, 0, -1, 0, 1, -1},
    {1, 0, -1, 0, 1, -1}
};
int dy[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {0, 1, 0, -1, 1, 1}
};


int main() {
  int W, H;
  cin >> W >> H;
  // マップの外側を白色マスで囲む
  vector<vector<int>> fi(H+2, vector<int>(W+2, 0));
  // 1から入力を受け取る
  for (int x = 1; x <= H; ++x) for (int y = 1; y <= W; ++y) cin >> fi[x][y];

  // 探索済みの座標
  vector<vector<bool>> seen(H+2, vector<bool>(W+2, false));
  // 建物の外側を探索する関数
  auto rec = [&](auto self, int x, int y) -> void {
    seen[x][y] = true;
    // 6方向に探索
    for (int dir = 0; dir < 6; ++dir) {
      // 偶奇で訪問する方向が変わる
      int nx = x + dx[x%2][dir];
      int ny = y + dy[x%2][dir];
      if (nx < 0 || nx >= H+2 || ny < 0 || ny >= W+2) continue;
      // 建物の座標は訪問しない
      if (fi[nx][ny] == 1) continue;
      // 再起的に呼び出して探索
      if (!seen[nx][ny]) self(self, nx, ny);
    }
  };
  rec(rec, 0, 0);
  // ここで訪問されていない座標は囲いの中にあるのでフラグを立てる
  // こうしないと建物内のスペースも壁としてカウントしてしまうため
  for (int x = 1; x <= H; ++x) for (int y = 1; y <= W; ++y) if (!seen[x][y]) fi[x][y] = 1;
  int res = 0;
  // マップを全探索
  for (int x = 1; x <= H; ++x) {
    for (int y = 1; y <= W; ++y) {
      // 建物がない場合はcontinue
      if (fi[x][y] == 0) continue;
      // 建物の壁から6方向に探索してそれが外と接しているならば壁なのでインクリメント
      for (int dir = 0; dir < 6; ++dir) {
        int nx = x + dx[x%2][dir], ny = y + dy[x%2][dir];
        if (fi[nx][ny] == 0) ++res;
      }
  }
  }
  cout << res << endl;

  return 0;
}