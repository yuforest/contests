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


typedef pair<int,int> P;
ll INF = 1LL<<60;

struct Edge {
	int to,cost;
};

typedef vector<vector<Edge> > Graph;
// グラフ、始点、距離を記録する配列のポインタを引数に取る
// ダイクストラ
void dijkstra(const Graph &G,int s,vector<ll> &dist){
  // 昇順に取り出す、コストが低い順に取り出す
  priority_queue<P, vector<P>, greater<P> > que;
  dist[s] = 0;
  // 始点をpush、始点からのコストと頂点番号
  que.push({dist[s], s});
  while(que.size()){
    P p = que.top();
    que.pop();
    int v = p.second;
    // 来たは良いが、他のルートで来た方がコストが低いことが確定しているためcontinue
    if(dist[v] < p.first) continue;
    // 隣接頂点を探索
    for(int i = 0; i < G[v].size(); i++){
      Edge e = G[v][i];
      // 今いる頂点から遷移した方がコストが下がる場合は更新して、次の頂点をpush
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        // 始点からのコストと次に探索する頂点番号をpush
        que.push({dist[e.to], e.to});
      }
    }
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  Graph G(N);
  rep(i, K) {
    int q;
    cin >> q;
    if (q == 0) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      vector<ll> dist(N, INF);
      dijkstra(G,a,dist);
      if (dist[b] == INF) {
        cout << -1 << endl;
      } else {
        cout << dist[b] << endl;
      }
    } else {
      int c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      Edge edge1;
      edge1.to = d;
      edge1.cost = e;
      G[c].push_back(edge1);
      Edge edge2;
      edge2.to = c;
      edge2.cost = e;
      G[d].push_back(edge2);
    }
  }
  return 0;
}