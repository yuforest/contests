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

int d[2][100000];
vector <int> v[100000];

// x: 現在の頂点, y: 直前の頂点, z: 現在の頂点までの距離, w: 0: Fennec, 1: Snuke
void dfs(int x, int y, int z, int w) {
  int i;
  d[w][x] = z;

  for (i = 0; i < v[x].size(); i++) {
    // 親には戻らない
    if (v[x][i] == y) continue;
    dfs(v[x][i], x, z + 1, w);
  }
}

int main() {
  int n, c1 = 0, c2 = 0, i;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    // 0-indexedにして辺を張る
    v[x].push_back(y);
    v[y].push_back(x);
  }

  // 0: Fennec, 1: Snuke
  // 最後の引数が0ならd[0]に、1ならd[1]に距離を格納する
  // それぞれ0,n-1を根として距離を再起的に探索する
  // この場合木なのでDFSで良いが、一般的なグラフの場合はBFSが良い
  dfs(0, -1, 0, 0);
  dfs(n - 1, -1, 0, 1);

  // 双方0とn-1の間の頂点を初めに塗っていくのが最適なので、
  // フェネックの距離がすぬけの距離以下なら先手のフェネックが塗れる
  // そうでなければ後手のすぬけが塗れるとして頂点数を数えて勝敗を判定する
  for (i = 0; i < n; i++) {
    if (d[0][i] <= d[1][i]) {
      c1++;
    } else {
      c2++;
    }
  }

  if (c1 > c2) {
    puts("Fennec");
  } else {
    puts("Snuke");
  }

  return 0;
}