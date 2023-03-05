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

// すべての頂点の出次数が 1 の有向グラフを Functional Graphという
// Gの連結成分がK個あって、C1,C2,...CKとする。このとき、各連結成分には閉路が1つだけ存在する
int main() {
  int N;
  cin >> N;
  vector<int> X(N), C(N);
  // 0-indexed
  for (auto& x : X) cin >> x, --x;
  for (auto& x : C) cin >> x;
  dsu uf(N);
  long long ans = 0;
  // 0からN-1までを全探索
  for (int i = 0; i < N; i++) {
    // 連結でなければ連結してcontinue
    if (uf.same(i, X[i]) == false) {
      uf.merge(i, X[i]);
      continue;
    }
    // 既に連結している場合
    // つまりこの辺をつなげることで閉路ができる場合
    // 今のコストと頂点番号から初めて
    // 閉路の中で最小のコストを探す、最初の地点に戻ってくるまでやる
    // 閉路を構成する頂点のうち1つの不満度が正になるのが最適
    int cur = C[i], v = i;
    do {
      v = X[v];
      cur = min(cur, C[v]);
    } while (v != i);
    debug(cur);
    // それを追加する
    ans += cur;
  }
  cout << ans << "\n";
}