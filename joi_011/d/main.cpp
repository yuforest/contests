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

#define MAXN 5020

int N, M;
int is[MAXN][MAXN];

int main() {
  int i;
  int a, b, x;

  scanf("%d %d", &N, &M);
  for (i = 0; i < M; ++i) {
    scanf("%d %d %d", &a, &b, &x);
    // 三角形の頂点
    ++is[a][b];
    // 頂点の次の列
    --is[a][b + 1];
    // 左下の頂点の次の行
    --is[a + x + 1][b];
    // 右下の頂点の次の2つ先
    ++is[a + x + 1][b + x + 2];
    // 左下の頂点の2つ下の行、1つ先の列
    ++is[a + x + 2][b + 1];
    // 右下の頂点の2つ下の行、2つ先の列
    --is[a + x + 2][b + x + 2];
  }
  // 順番は斜め、上下、左右でも同じ結果となる
  // 左から右の累積和
  for (a = 1; a <= N + 10; ++a) for (b = 1; b <= a + 5; ++b) {
    is[a][b] += is[a][b - 1];
  }
  // 上から下の累積和
  for (a = 1; a <= N + 10; ++a) for (b = 1; b <= a + 5; ++b) {
    is[a][b] += is[a - 1][b];
  }
  // 左上から右下の累積和
  for (a = 1; a <= N + 10; ++a) for (b = 1; b <= a + 5; ++b) {
    is[a][b] += is[a - 1][b - 1];
  }
  int ans = 0;
  // N行×a列(その時の行)だけを見る
  for (a = 1; a <= N; ++a) for (b = 1; b <= a; ++b) {
    if (is[a][b]) {
      ++ans;
    }
  }
  printf("%d\n", ans);

  return 0;
}
