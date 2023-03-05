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

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> edge(N - 1);
  vector<vector<ll>> g(N);
  for(ll i = 0; i < N - 1; i++){
    ll a, b;
    cin >> a >> b;
    // 0-indexedに
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    // 辺を記録
    edge[i] = {a, b};
  }
  vector<ll> depth(N, -1);
  depth[0] = 0;
  vector<ll> q = {0};
  // 深さ優先探索する
  while(q.size()){
    // 末尾の要素を取り出す
    ll at = q.back();
    q.pop_back();
    // 隣接頂点を探索
    for(ll i : g[at]) if(depth[i] == -1){
      // まだ値が入っていない隣接頂点の深さを更新
      depth[i] = depth[at] + 1;
      q.push_back(i);
    }
  }
  // 答えの配列
  vector<ll> s(N);
  ll Q;
  cin >> Q;
  while(Q--){
    ll t, e, x;
    cin >> t >> e >> x;
    // 辺の頂点番号を取得
    auto [a, b] = edge[e - 1];
    // aの方が深いなら入れ替える
    // これによって、aの方が常に根に近いことになる
    if(depth[a] > depth[b]){
      swap(a, b);
      // クエリが1の時は2に、2の時は1にする
      t ^= 3;
    }
    // aの深さ<bの深さを仮定する
    // クエリが1の時
    // 値に近い方から辿って頂点bと連結している辺を切り離した時の連結成分
    // 全てにxを累積和的に足す
    if(t == 1){
      s[0] += x;
      s[b] -= x;
    }
    // 逆なら、aと連結している辺を切り離した時の連結成分全てにxを足す
    else s[b] += x;
  }
  q = {0};
  // 上から辿りながら、累積和をとる
  while(q.size()){
    ll at = q.back();
    q.pop_back();
    for(ll i : g[at]) if(depth[at] < depth[i]){
      s[i] += s[at];
      q.push_back(i);
    }
  }
  for(ll i : s) cout << i << endl;
  return 0;
}