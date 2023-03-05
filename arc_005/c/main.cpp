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

// 無限大を表す値
const int INF = 1<<29;

// 上下左右への動きを表すベクトル
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main() {
  // 入力
  int H, W;  // 縦の長さ, 横の長さ
  cin >> H >> W;
  vector<string> field(H);
  for (int i = 0; i < H; ++i) cin >> field[i];

  // スタートとゴールのマスを割り出す
  int sx = -1, sy = -1, gx = -1, gy = -1;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (field[i][j] == 's') sx = i, sy = j;
      if (field[i][j] == 'g') gx = i, gy = j;
    }
  }

  // 各頂点は pair<int,int> 型で表すことにする
  using Node = pair<int,int>;
  deque<Node> que;  // deque

  // 初期条件
  // dist[i][j] はマス (i, j) への最短路長を表す
  que.push_front(Node(sx, sy));
  vector<vector<int>> dist(H, vector<int>(W, INF));
  dist[sx][sy] = 0;

  // 0-1 BFS 開始
  // 幅優先探索をしているがコスト0の移動を優先する
  // O(HW)
  // 各マスにおいて4方向を探索することで最短の壁を壊す回数を導くことができるため
  while (!que.empty()) {
      // deque の先頭の要素を取り出す
      auto [x, y] = que.front();
      que.pop_front();

      // 隣接頂点を順にみていく
      for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 盤面外はスキップ
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

        // コスト 0 の場合は、deque の先頭に push
        // これは優先して探索される
        // できるだけコスト0の移動で探索する
        // それができなくなった段階でコスト1の移動で探索する
        if (field[nx][ny] != '#') {
          // 次の探索頂点のコストより低ければ探索する
          if (dist[nx][ny] > dist[x][y]) {
            // 距離をセット
            dist[nx][ny] = dist[x][y];
            que.push_front(Node(nx, ny));
          }
        }
        // コスト 1 の場合は、deque の末尾に push
        // これは後から探索される
        else {
          // 訪れようとしている頂点が今の頂点+1よりコストが高ければ更新する
          // そうでなければ何もしない
          // コスト0の移動を繰り返して移動できるようなところではここは実行されない
          if (dist[nx][ny] > dist[x][y] + 1) {
            // この時は壁を壊すので今のマスまでの距離+1
            dist[nx][ny] = dist[x][y] + 1;
            que.push_back(Node(nx, ny));
          }
        }
      }
  }

  // 最短路長
  if (dist[gx][gy] <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}