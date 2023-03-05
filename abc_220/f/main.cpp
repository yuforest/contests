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
  // 入力を受け取って0-indexedのグラフに
  int n; cin >> n;
  vector<vector<int>> g(n);
  for(int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  // subは0番目の頂点を起点とした部分木のサイズ
  vector<long long> sub(n, 1), ans(n);
  // 深さ優先探索、dはここまでの辺の本数
  function<void(int, int, int)> dfs=[&](int i, int p, int d){
    ans[0] += d;
    // 親以外の隣接頂点を探索
    for(int x : g[i]) if(x != p) {
      // 辺の本数を増やして再帰的に探索
      dfs(x, i, d+1);
      // 部分木のサイズを求める
      sub[i] += sub[x];
    }
  };
  // 最初の頂点を起点にした答えを求める
  dfs(0, -1, 0);
  debug(ans);
  debug(sub);
  // 頂点1に隣接する頂点の1つをsとする
  // ans(1)とans(s)の差分を考える
  // ある頂点jがsの部分木に含まれる時はdis(s,j)=dis(i,j)-1
  // 含まれない時はdis(s,j)=dis(i,j)+1
  // 頂点1に隣接する頂点の答えは(頂点1の答え)-(sの部分木の頂点数)+(N-sの部分木の頂点数)
  // で求めることができる
  // (N-sの部分木の頂点数)は1とsの答えの差分を考えた時に遠ざかる頂点数
  // DPぽい感じで答えを求めることができる
  // よってans(s) = ans(1) + N - 2 * sub(s)
  function<void(int, int)> dfs2=[&](int i, int p){
    // 隣接頂点の答えを現頂点の答えと隣接頂点の部分木の数を用いて求める
    for(int x : g[i]) if(x != p) {
      ans[x] = ans[i] - 2 * sub[x] + n;
      dfs2(x, i);
    }
  };
  dfs2(0, -1);
  for(long long x : ans) cout << x << endl;
  return 0;
}