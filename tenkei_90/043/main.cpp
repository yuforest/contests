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

// typedef pair<ll, vector<ll>> P;
// int main() {
//   ll H, W;
//   cin >> H >> W;
//   ll sh, sw, th, tw;
//   cin >> sh >> sw >> th >> tw;
//   sh--;sw--;
//   th--;tw--;
//   vs S(H);
//   rep(i, H) cin >> S[i];
//   vvl dist(H, vl(W, 1e9));
//   vector<int> dh={0,1,-1,0};
//   vector<int> dw={1,0,0,-1};
//   // 距離と座標を記録するデータ構造Pの優先度付キュー、昇順
//   priority_queue<P, vector<P>, greater<P>> que;
//   dist[sh][sw] = 0;
//   que.push({0, {sh, sw, -1}});
//   while(!que.empty()) {
//     auto val = que.top();
//     ll h = val.second[0];
//     ll w = val.second[1];
//     que.pop();
//     rep(i, 4) {
//       ll nh = h + dh[i];
//       ll nw = w + dw[i];
//       // 迷路の外への移動はできない
//       if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
//       // 壁なら進めない
//       if (S[nh][nw] == '#') continue;
//       // コスト計算
//       ll cost;
//       // 最初の移動や進む方向が同じならコストは変わらない
//       if (val.second[2] == -1 || val.second[2] == i) cost = val.first;
//       else cost = val.first+1;
//       // 最短回転回数を更新できない時は探索打切り
//       if (dist[nh][nw] <= cost) continue;
//       dist[nh][nw] = cost;
//       que.push({cost, {nh, nw, i}});
//     }
//   }
//   debug(dist);
//   cout << dist[th][tw] << endl;
// }


const int inf = 1012345678;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int H, W, sx, sy, gx, gy, dist[1009][1009][4]; char S[1009][1009];
struct state {
  int x, y, dir;
};
int main() {
  cin >> H >> W >> sx >> sy >> gx >> gy;
  --sx, --sy, --gx, --gy;
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }
  // 初期化
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      dist[i][j][0] = inf;
      dist[i][j][1] = inf;
      dist[i][j][2] = inf;
      dist[i][j][3] = inf;
    }
  }
  // 0-1BFSのためのdeque
  deque<state> deq;
  // 最初のコストはどの方向を向いていても0
  for (int i = 0; i < 4; ++i) {
    dist[sx][sy][i] = 0;
    deq.push_back({ sx, sy, i });
  }
  while (!deq.empty()) {
    // 前から取り出す
    state u = deq.front(); deq.pop_front();
    // 4方向を探索
    for (int i = 0; i < 4; ++i) {
      // 次の位置とコストを計算
      int tx = u.x + dx[i], ty = u.y + dy[i], cost = dist[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
      // 次のマスに進むことができて最小値を更新できれば
      if (0 <= tx && tx < H && 0 <= ty && ty < W && S[tx][ty] == '.' && dist[tx][ty][i] > cost) {
        // 最小値更新
        dist[tx][ty][i] = cost;
        // 方向が同じでなければ後ろからpush
        if (u.dir != i) deq.push_back({ tx, ty, i });
        // 同じなら前からpush
        else deq.push_front({ tx, ty, i });
      }
    }
  }
  // ゴールマスの4方向を探索し、答えを得る
  int answer = inf;
  for (int i = 0; i < 4; ++i) {
    answer = min(answer, dist[gx][gy][i]);
  }
  cout << answer << endl;
  return 0;
}