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

int ans[2010];

int main() {
  int n,m;
  cin >> n >> m;
  vector<int>A(n);
  rep3(i,0,n)cin >> A[i];
  vector<vector<int>>G(n);
  // 頂点を削除するときのコストの総和
  vector<ll>c(n);
  // 辺の入力
  rep3(i,0,m){
    int x,y;
    cin >> x >> y;
    x--,y--;
    G[x].push_back(y);
    G[y].push_back(x);
    // xを削除するためのコストにyの頂点に書かれている番号をたす
    c[x]+=A[y];
    // yを削除するためのコストにxの頂点に書かれている番号をたす
    c[y]+=A[x];
  }
  // 「現時点でコストが最も低い頂点」を取得するためにpriority_queueを使う
  priority_queue<pair<ll,int>>pq;
  // priority_queueはデフォルトで降順なのでマイナスをかけて、
  // 本来のコストが小さいもの(コストの絶対値が小さいもの)から取り出せるようにしている
  // コストと頂点番号をpush
  rep3(i,0,n)pq.push({-c[i],i});
  vector<bool>erased(n);
  ll ans = 0;
  // 各頂点を消すために必要なコストは増えないので、どの時点についても、
  // 「現時点で必要なことが確定しているコスト」以下のコストで消せる頂点は消してしまっても良い
  // したがって、「現時点でコストが最も低い頂点に対して操作を行う」を N回繰り返すのが最適
  // 消された頂点はerasedがtrueになるので、操作は最大N回しか行われない
  while(!pq.empty()){
    // コストと頂点番号を取り出す
    auto[cost,x] = pq.top();
    pq.pop();
    // 元のコストに戻している
    cost = -cost;
    if(erased[x])continue;
    erased[x] = true;
    // この頂点を消すためのコストと既に消した頂点を消すためのコストのどちらが大きいかで更新
    ans = max(ans, cost);
    // 消去した頂点xに繋がっている頂点が消されていなければ、
    // コストを減らして、減らしたコストをpush
    // 減らした後のコストの方が小さければそちらが先に取り出されることになる
    for(auto y:G[x])if(!erased[y]){
      // 探索頂点のコストから消去した頂点のコストを除く
      c[y] -= A[x];
      // 改めて頂点をqueに追加する
      pq.push({-c[y],y});
    }
  }

  cout << ans << endl;
  return 0;
}