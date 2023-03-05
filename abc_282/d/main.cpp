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
using vvvl = vector<vector<vector<ll>>>;
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
// vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

typedef pair<ll, ll> P;
ll n, m;
vector<int> G[200005];
// 初期値は0
int color[200005];

// 探索する頂点、遷移元、色を引数に持ち探索する関数
P dfs(int v, int p, int c){
  P ret = P(0, 0);
  color[v] = c;

  // 出現した色の数をカウントする
  if(c == 1) ret.first++;
  else ret.second++;

  // 繋がっている頂点を探索
  for(auto u : G[v]){
    // 遷移元や既に違う色で塗られている場合は探索しない
    if(u == p || color[u] == -c) continue;
    // 繋がっている頂点が同じ色である場合は二部グラフではない
    if(color[u] == c) return P(-1, -1);
    // dfsで探索
    P res = dfs(u, v, -c);
    // 二部グラフでなければそれを親に伝播する
    if(res.first == -1) return P(-1, -1);
    // そうでない場合子でカウントした色も足す
    ret.first += res.first, ret.second += res.second;
  }
  return ret;
}
int main(void)
{
  cin >> n >> m;
  int u, v;
  for(int i = 1; i <= m; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  // 辺で結ぶことで二部グラフでなくなってしまうような頂点のペアとは、
  // 同じ連結成分に属する同じ色の頂点同士のペア
  // 頂点のペアの個数から、初めに辺で結ばれている頂点のペア数M引いた値を初期値とする
  ll ans = n*(n-1)/2 - m;
  for(int i = 1; i <= n; i++){
    // 今の頂点が色分けがされていない場合は探索する
    if(!color[i]){
      // 今の頂点、遷移元はないので-1,初期値の色は1
      P res = dfs(i, -1, 1);
      // 一つでも二部グラフでない連結成分があれば、答えは0になる
      if(res.first == -1){
        cout << 0 << endl;
        return 0;
      }
      // 各連結成分の同じ色に塗られた頂点同士のペアの個数を引く
      // これは白に塗られた頂点数をW, 黒に塗られた頂点すうをBとすると
      // それぞれWC2, BC2で求められる
      ans -= res.first * (res.first-1) / 2;
      ans -= res.second * (res.second-1) / 2;
    }
  }
  cout << ans << endl;

  return 0;
}