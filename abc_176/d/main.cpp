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

bool used[1000][1000];
int INF = 100000000;
vvi dp(1001, vector<int>(1001, INF));
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int warp_x[5] = { -2, -1, 0, 1, 2 }, warp_y[5] = { -2, -1, 0, 1, 2 };

int main(){
  int H, W;
  cin >> H >> W;
  int ch, cw, dh, dw;
  cin >> ch >> cw >> dh >> dw;
  ch--;cw--;dh--;dw--;
  string S[H];
  rep(i, H) cin >> S[i];

  // 普通のqueueの代わりにdequeを使う
  // また、移動におけるコストが 0 と 1 だけの場合は、01-BFSと呼ばれる実装が可能となります
  // dequeを使用し、コストが 0 の移動先の頂点はdequeの先頭に、
  // コストが1の移動先の頂点はdequeの末尾に追加することで、距離順に探索をすることが可能となります。
  // 暫定最短距離が最も小さい頂点を選んで、そこから伸びる辺で他の頂点の暫定最短距離を更新する
  deque<pair<int, int>>que;
  que.push_back({ch, cw});
  dp[ch][cw] = 0;

  // 幅優先探索
  // 移動Aで移動可能な場所まで移動し、ゴールにたどり着けないのであれば、移動Bを用いて、移動Aだけでは移動出来ない場所に移動する
  while (!que.empty()) {
    // dequeを前から取り出す
    auto q = que.front();
    que.pop_front();
    int x, y;
    tie(x, y) = q;

    // 上下左右への移動
    bool wall_present = false;
    rep(i, 4) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 0 || xx >= H) continue;
      if (yy < 0 || yy >= W) continue;
      if (S[xx][yy] == '#') {
        wall_present = true;
        continue;
      }
      // 他の探索経路から同じ場所を探索してしまうことがあるので
      // この時点で訪問済みにして距離も入れておくと良い
      if (dp[xx][yy] <= dp[x][y]) continue;
      dp[xx][yy] = dp[x][y];
      // 距離0で移動できるので前から追加
      que.push_front({xx, yy});
    }
    // ワープの移動
    rep(i, 5) {
      rep(j, 5) {
        // その場に止まったり、歩いて行ける範囲は除く
        if (warp_x[i] == 0 && warp_y[j] == 0) continue;
        if (warp_x[i] == 1 && warp_y[j] == 0) continue;
        if (warp_x[i] == -1 && warp_y[j] == 0) continue;
        if (warp_x[i] == 0 && warp_y[j] == 1) continue;
        if (warp_x[i] == 0 && warp_y[j] == -1) continue;
        int xx = x + warp_x[i];
        int yy = y + warp_y[j];
        if (xx < 0 || xx >= H) continue;
        if (yy < 0 || yy >= W) continue;
        if (S[xx][yy] == '#') continue;
        // 遷移先が今の地点から遷移するよりワープ回数が小さければcontinue
        if (dp[xx][yy] <= dp[x][y] + 1) continue;
        // ワープ回数を追加
        dp[xx][yy] = dp[x][y] + 1;
         // 距離1で移動できるので後ろから追加
        que.push_back({xx, yy});
      }
    }
  }
  if (dp[dh][dw] == INF) cout << -1 << endl;
  else cout << dp[dh][dw] << endl;

  return 0;
}