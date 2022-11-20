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
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()
#define fore(i,a) for(auto &i:a)

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


using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;

// dfs
// G: グラフの配列、v: 現在探索している頂点、p: 親、sum: Kからの距離の合計、dist: 距離を格納する配列のポインタ
void rec(const Graph &G, int v, int p, long long sum, vector<long long> &dist) {
  dist[v] = sum;
  for (auto e : G[v]) {
    // 木の探索は親以外を探せば良い
    if (e.first == p) continue;
    // 現在の頂点に繋がっている頂点を探索、Kからの距離を追加
    rec(G, e.first, v, sum + e.second, dist);
  }
}

int main() {
    int N; cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
      int a, b; long long c; cin >> a >> b >> c;
      --a, --b;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
    }
    int Q, K; cin >> Q >> K; --K;
    // 要素数N、0で初期化した可変長配列、Kからの距離を格納していく配列
    vector<long long> dist(N, 0);
    // Kから探索を始めている、親は最初-1、距離は最初0
    rec(G, K, -1, 0, dist);

    for (int q = 0; q < Q; ++q) {
      int x, y; cin >> x >> y; --x, --y;
      cout << dist[x] + dist[y] << endl;
    }
}