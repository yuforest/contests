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

int ans[2010];

// 普通にやるとBFS1回につき、O(M)
// クエリごとにBFSをするとO(MQ)かかる
// 最悪ケースで10^10は超えてしまうのでTLE
// しかし今回は起点となる頂点から最大
// k=0 -> 1(その頂点のみ)
// k=1 -> 3
// k=2 -> 9(3*3)
// k=3 -> 27(9*3)
// の合計40頂点まで探索すれば良いので
// 探索を途中で打ち切ることで間に合わせることができる
// 150000*40=6000000程度
int main() {
  int N,M;
  cin>>N>>M;
  // グラフ構築
  vector<vector<int>> E(N);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  // 距離を記録する配列
  vector<int> dis(N,-1);

  int Q;
  cin>>Q;

  for(int i=0;i<Q;i++){
    int x,k;
    cin>>x>>k;
    x--;
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    // 頂点を記録する配列
    vector<int> vs;
    // 幅優先探索
    while(q.size()>0){
      int u = q.front();
      q.pop();
      // 今の頂点を記録
      vs.push_back(u);
      // 距離がk以上になったらそれ以上は探索しない
      if(dis[u]==k){
        continue;
      }
      for(int j=0;j<E[u].size();j++){
        // 次の頂点番号
        int v = E[u][j];
        // 既に訪問済みなら訪問しない
        if(dis[v]!=-1)continue;
        // 次に探索する頂点は今の頂点までの距離+1
        dis[v] = dis[u] + 1;
        // 次にこの頂点から探索をする
        q.push(v);
      }
    }
    int ans = 0;
    for(int j=0;j<vs.size();j++){
      // 0-indexedから1-indexedに戻している
      ans += vs[j]+1;
      // 今の頂点を初期化、過去に変更したので-1に戻している
      dis[vs[j]] = -1;
    }
    // 出力
    cout<<ans<<endl;
  }

  return 0;
}