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

// クラスカル法
// int main() {
//   ll N, M;
//   cin >> N >> M;
//   vl A(M), B(M), C(M);
//   // 辺をコストが小さい順に並べる
//   vector<pair<int,int>>E;
//   rep(i, M) {
//     cin >> A[i] >> B[i] >> C[i];
//     // 0-indexed
//     A[i]--;
//     B[i]--;
//     // 距離と辺の番号をpush
//     E.push_back(make_pair(C[i], i));
//   }
//   sort(E.begin(),E.end());
//   atcoder::dsu uf(N);
//   vl ans;
//   for(pair<int, int> p : E) {
//     int u = A[p.second];
//     int v = B[p.second];
//     if(!uf.same(u,v)) {
//       uf.merge(u,v);
//       ans.push_back(p.second+1);
//     }
//   }
//   rep(i, ans.size()) {
//     if (i) cout << " ";
//     cout << ans[i];
//   }
//   cout << endl;
//   return 0;
// }

// ダイクストラ法
struct edge{
  int to,cost,idx;
};

// 単一始点最短経路問題
// ダイクストラ法の性質を理解しているか問う問題
vector<int> dijkstra(int s, vector<vector<edge>>&G){
  vector<ll>dist(G.size(),1LL<<60);
  vector<int>idx(G.size());
  dist[s]=0;
  using P=pair<ll,int>;
  // 到達コストと頂点番号
  priority_queue<P,vector<P>,greater<P>> pq;
  // 始点の情報をpush
  pq.push({0,s});

  while(!pq.empty()){
    // 分割代入
    auto[d,v]=pq.top();
    pq.pop();
    if(dist[v]!=d) continue;
    // 隣接頂点の探索
    // 行き先、コスト、辺の番号
    for(auto[vv,c,i]:G[v]){
      // その頂点までの最短距離を更新できる場合
      // 最短経路が更新できる時は、新たな頂点に到達する時だけ
      // なぜなら到達コストが小さい順に探索していて、
      // 新しい頂点から伸びる辺も合わせた距離がpriority_queueに追加され
      // 辺の数が多くても合計距離が少なければ早く到達するため
      if(dist[vv]>dist[v]+c){
        dist[vv]=dist[v]+c;
        pq.push({dist[vv],vv});
        // vvに行くために必要な辺
        // 都市1から都市iの最短経路において、都市iに到達する直前に使った道路を保存
        idx[vv]=i;  //  <- index
      }
    }
  }
  return idx;
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<edge>>G(N);
  // グラフの構築
  for(int i=0;i<M;i++){
    int a,b,c;
    cin >> a >> b >> c;
    // 0-indexedで行き先、コスト、辺の番号をpush
    G[a-1].push_back({b-1,c,i});
    G[b-1].push_back({a-1,c,i});
  }
  // 始点の頂点番号とグラフ
  vector<int> idx=dijkstra(0, G);
  // 1-indexedに戻す
  // 1からN-1まで見れば良い(これが都市2~Nに行くために必要な辺に該当する)
  for(int i=1;i<N;i++)cout << idx[i]+1 << ' ';
}