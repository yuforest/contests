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
// vector<ll> G[1 << 18];

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


int n;
vector<int> G[200005];
int L[200005], R[200005];
int leaf[200005];
int id = 0;
// 頂点から深さ優先探索で訪れたのが早い順に葉にidを割り振る
void dfs(int v, int p) {
  // 頂点である1以外で親にしか繋がっていないもの
  if(v != 1 && G[v].size() == 1){
    // idをインクリメントして割り振る
    leaf[v] = ++id;
    return;
  }
  // 親以外の頂点に対して探索を行う
  for(auto u : G[v]) if(u != p) dfs(u, v);
}
// i=1,2,...Nについて、L[i]とR[i]をそれぞれ頂点iの部分木に含まれる葉のidの
// 最大値と最小値にする
void dfs2(int v, int p) {
  // 現在探索している頂点が葉である場合
  // ベースケース
  if(leaf[v]){
    // その頂点番号のインデックスは葉のidとする
    L[v] = R[v] = leaf[v];
    return;
  }
  // 極端な値で初期化
  L[v] = 1e9, R[v] = -1e9;
  // 現在の頂点につながる頂点の探索
  for(auto u : G[v]){
    // 親なら探索しない
    if(u == p) continue;
    // 現在の頂点の部分木を再帰的に探索し、葉のidをセットしていく
    dfs2(u, v);
    // 現在の頂点のL[i]とR[i]は部分木に含まれる葉のidの最小値と最大値になる
    L[v] = min(L[v], L[u]);
    R[v] = max(R[v], R[u]);
  }
}
int main(void) {
  cin >> n;
  int u, v;
  // N-1回の入力を受け取る
  for(int i = 1; i <= n-1; i++){
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  // 現在の頂点番号と親の頂点番号を保持してDFSを行う
  dfs(1, -1);
  dfs2(1, -1);
  for(int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << "\n";

  return 0;
}