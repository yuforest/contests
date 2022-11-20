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
#define fore(i,a) for(auto &i:a)

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

int N;
// このようにすることでpairの配列の配列を簡単に定義できる
// 重み付きグラフを作る時に便利
vector<pair<int,int>> E[101010];
int ans[101010];
void dfs(int cu, int pa = -1, int col = 0) {
  // 使用済みの色を保存するset
  set<int> used;
  used.insert(col);
  int c = 1;
  fore(to, E[cu]) if (to.first != pa) {
    while (used.count(c)) c++;
    // 辺番号のindexで色を保存
    ans[to.second] = c;
    dfs(to.first, cu, c);
    c++;
  }
}

int main() {
  cin >> N;
  rep3(i, 0, N - 1) {
    int a, b; cin >> a >> b;
    a--; b--;
    // 辺の番号をpushして管理している
    E[a].push_back({ b, i });
    E[b].push_back({ a, i });
  }

  dfs(0);

  int ma = 0;
  // 頂点から伸びている辺の数のうち最も大きなものを取得
  rep3(i, 0, N) chmax(ma, (int)E[i].size());
  printf("%d\n", ma);
  // N-1回出力
  rep3(i, 0, N - 1) printf("%d\n", ans[i]);
  return 0;

}