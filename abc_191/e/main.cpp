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

const int MAXN = 100100;

struct edge {
  int v;
  ll w;
  edge() {}
  // コンストラクタで頂点と辺の重みを保存
  edge(int v, ll w) : v(v), w(w) {};
};

// ダイクストラによって頂点数、グラフ、スタートの頂点を受け取り
// 単一始点からの各頂点への最短距離の配列を返す
// 計算量はO(MlogN)
// priority_queueを使うことで候補の追加や最小値の取得をO(logN)で行うことができる
// priority_queueの中で最短距離順に並べるところで合計N個の頂点を並び替えることになるので
// 計算量O(logN)となる
vector<ll> dijkstra(int n, vector<vector<edge> >& G, int s) {
  // 距離は最初大きな値で初期化しておく
  vector<ll> d(n, LLONG_MAX/10);
  // スタート地点の距離は0
  d[s] = 0;
  // スタートからある頂点への距離と頂点名をqueueに入れていく
  // priority_queueなので、常にスタート地点からの距離が近い頂点から探索してくれる
  // 例えば
  // 0,1,2,3の頂点があり
  // 0->1,dist:1
  // 0->2,dist:3
  // 1->3,dist:1
  // 2->3,dist:1
  // のような辺があったとする
  // このときまず0を探索して、{1,1}と{3,2}がpriority_queueに追加される
  // (便宜上priority_queueは昇順で値と取り出すとする)
  // 次に探索されるのは{1,1}でこのときpriority_queueに{2,3}が追加される(ここで1への最短距離は1)
  // 次に探索されるのは{2,3}でこのときpriority_queueには何も追加されない(ここで3への最短距離は2)
  // 最後に探索されるのは{3,2}でこのときpriority_queueには何も追加されない(ここで2への最短距離は3)
  // このように常に始点から距離が近い頂点を探索し、現在の最短距離よりも大きい頂点からは
  // 探索をしない(打ち切る)ことができるので効率的に最短距離を確定させていくことができる
  priority_queue<pair<ll, int> > que;
  // 最初の頂点から最初の頂点への距離は0, スタート地点から探索を始める
  que.push(make_pair(0ll, s));
  // 探索するべき頂点がなくなるまでやる
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int u = p.second;
    // 入れる時につけたマイナスを外す
    ll dist = -p.first;
    // 距離が今の頂点への距離より大きければ、
    // それより先でも距離が短くなることはないので探索を打ち切る
    if (dist > d[u]) continue;
    // 探索頂点に繋がっている頂点を探索
    for (edge e : G[u]) {
      // 次に探索する頂点の現在のスタートからの最短距離より、
      // スタートから今の頂点に来て、そこから次の頂点に移動する方が近ければ
      if (d[e.v] > d[u]+e.w) {
        // 距離を更新する
        d[e.v] = d[u] + e.w;
        // 次にこの頂点を探索したいのでqueにpushする
        // priority_queueはデフォルト降順なので
        // 昇順にするためにマイナスにする
        // ex: デフォルトで距離が2,1の順で取り出されてしまうが、
        // 1,2の順に見ていきたいので-1, -2とすることで降順で-1から取り出せる
        que.push(make_pair(-d[e.v], e.v));
      }
    }
  }
  return d;
}

int main() {
  int N, M;
  cin >> N >> M;
  // 普通のグラフと辺の向きを逆にしたグラフの構築
  // 頂点ごとに向かう頂点とその重みを保存する
  vector<vector<edge>> G(N), rG(N);
  vl ans(N, 1e9);
  for (int i = 0; i < M; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    // コンストラクタ引数をemplace_backの引数として末尾に新たな要素を追加することができる
    G[a].emplace_back(b, c);
    rG[b].emplace_back(a, c);
    // 自己ループがある場合は更新
    if (a == b) {
      chmin(ans[a], c);
    }
  }
  for (int i = 0; i < N; i++) {
    // iの街から各街への最短距離
    auto d = dijkstra(N, G, i);
    // 辺の向きを反転させるとある街からiの街への最短距離となる
    auto rd = dijkstra(N, rG, i);
    // 自分自身の街は除いた各街について最短距離を更新
    for(int j = 0; j < N; j++) {
      if (i == j) continue;
      // 行きと帰りの合計が最短距離
      ll sum = d[j] + rd[j];
      chmin(ans[i], sum);
    }
    if (ans[i] >= 1e9) ans[i] = -1;
    cout << ans[i] << endl;
  }
  return 0;
}