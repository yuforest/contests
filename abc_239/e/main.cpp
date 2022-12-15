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

int n,q;
vector<int> x;
vector<vector<int>> g;
// 頂点ごとにその部分木の上位20個の大きさの頂点に書かれた番号を保持する二次元配列
vector<vector<int>> memo;
// 木の探索は親の頂点番号を保持して、逆流しないようにする
vector<int> dfs(int cur, int prev) {
  // 現在の頂点番号に書かれている数を追加
  vector<int> res = { x[cur] };
  // 現在の頂点と繋がっている頂点を探索
  for(int nv: g[cur]) {
    // 親は探索しない
    if (nv == prev) continue;
    // 繋がっている頂点に書かれている番号を部分木の頂点に書かれた番号の配列に追加
    for(auto t: dfs(nv, cur)) {
      res.push_back(t);
    }
  }
  // 降順にソート
  sort(res.rbegin(),res.rend());
  // 最大でも上位20個の大きさの頂点に書かれた数のみを保持すれば良い
  rep(i, min((int)res.size(), 20)) {
    memo[cur].push_back(res[i]);
  }
  // 最大上位20個の値の配列を返す
  return memo[cur];
}

int main() {
  cin >> n >> q;

  x.resize(n);
  // 頂点に書かれている番号を受け取る
  rep(i,n) cin >> x[i];

  g.resize(n);
  // N-1個の辺の入力を受け取る
  rep(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  memo.resize(n);
  dfs(0, -1);

  // クエリを処理する
  rep(i,q) {
    int v,k;
    cin >> v >> k;
    v--; k--;

    cout << memo[v][k] << endl;
  }

  return 0;
}