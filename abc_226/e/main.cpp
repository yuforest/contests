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


#define N 200100
#define MOD 998244353
#define pb push_back

vector<int>e[N];
bool used[N];
int x, y;
void dfs(int k) {
  used[k] = true;
  x++;
  y += e[k].size();
  // 隣接頂点の探索
  rep(i, e[k].size())if (!used[e[k][i]])dfs(e[k][i]);
  return;
}
int main(void) {
  int n, m;
  ll ans = 1;
  cin >> n >> m;
  rep(i, n)used[i] = false;
  rep(i, m) {
    cin >> x >> y;
    // 0-indexedにした無向グラフ
    e[x - 1].pb(y - 1);
    e[y - 1].pb(x - 1);
  }
  // 全ての頂点を調べる
  // 握手の定理
  // 奇数の辺に接する頂点の数が偶数であるということ
  // 例えば、握手をするパーティがあった場合、奇数人の握手をする人の数は偶数である
  rep(i, n) {
    // 連結成分ごとに考える
    if (!used[i]) {
      // 初期化
      // x: 頂点数
      // y: 辺数(無向辺なので2倍)
      x = 0;
      y = 0;
      dfs(i);
      // 無向辺の数が頂点数の2倍でないとダメ
      if (y == (x * 2)) ans = (ans * 2) % MOD;
      else ans = 0;
    }
  }
  cout << ans << endl;
  return 0;
}