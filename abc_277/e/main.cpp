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

long long mod = 1000000007;
// vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

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

typedef pair<int, int> edge;
const int inf = 1e9;
int n, m, k;
// vector<edge>の配列
vector<edge> G[400005];
int dist[400005];

int main(void) {
  cin >> n >> m >> k;
  int u, v, a, s;
  for(int i = 1; i <= m; i++){
    cin >> u >> v >> a;
    // 通行可能な場合は双方向にコスト1の辺を張る
    if(a) G[u].push_back(edge(v, 1)), G[v].push_back(edge(u, 1));
    // そうでない場合はn+vにコスト1の辺を張っておく
    else G[n+u].push_back(edge(n+v, 1)), G[n+v].push_back(edge(n+u, 1));
  }
  // スイッチのある頂点の入力を受け取りn+sにコスト0の辺を張る
  // スイッチを押す行動はコスト0であるため
  for(int i = 1; i <= k; i++){
    cin >> s;
    G[s].push_back(edge(n+s, 0)), G[n+s].push_back(edge(s, 0));
  }

  // 01BFSを行う
  deque<int> deq;
  deq.push_back(1);
  // 移動コストを大きな値で初期化
  for(int i = 1; i <= 2*n; i++) dist[i] = inf;
  // 最初の頂点にいる時コスト0
  dist[1] = 0;

  // dequeを使い、スイッチできるときはスイッチ後の辺にコスト0で遷移し、
  // その頂点を優先して探索することによりNや2Nに早く辿り着く経路を求めることができる
  while(deq.size()){
    int v = deq.front();
    deq.pop_front();
    // その辺につながっている頂点を探索
    for(int i = 0; i < (int)G[v].size(); i++){
      // 頂点番号とコストを取得
      int u = G[v][i].first, c = G[v][i].second;
      // その頂点番号のコストが現在の頂点にコストを足したものより低ければ
      // コストを更新
      if(dist[u] > dist[v] + c){
        dist[u] = dist[v] + c;
        // コスト0なら前にpush
        if(c == 0) deq.push_front(u);
        // そうでなければ後ろにpush
        else deq.push_back(u);
      }
    }
  }

  int ans = min(dist[n], dist[2*n]);
  if(ans == inf) ans = -1;
  cout << ans << endl;

  return 0;
}

