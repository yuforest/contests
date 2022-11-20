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

int N, M, K, A[101010], B[101010], C[101010], D[101010];
int ans[101010];
set<int> friends[101010];
//---------------------------------------------------------------------------------------------------

// 条件1 aとbはブロック関係じゃない
// 条件2 aとbは直接交友関係じゃない
// 条件3 aとbは間接的に交友関係である
int main() {
  cin >> N >> M >> K;
  rep3(i, 0, M) cin >> A[i] >> B[i], A[i]--, B[i]--;
  rep3(i, 0, K) cin >> C[i] >> D[i], C[i]--, D[i]--;

  // 交友関係のUnionFind
  dsu uf(N);
  rep3(i, 0, M) {
    uf.merge(A[i], B[i]);
  }

  // -1しているのは自分自身を引くため、友達候補の数
  rep3(i, 0, N) ans[i] = uf.size(i) - 1;
  // 2人が友達関係にあるなら、友達候補からそれぞれ抜いて、直接の友達リストに追加
  rep3(i, 0, M) {
    ans[A[i]]--;
    ans[B[i]]--;
    // セットに値を追加
    friends[A[i]].insert(B[i]);
    friends[B[i]].insert(A[i]);
  }
  // ブロックリストを引いている(直接交友関係ではなくて、友達候補のもの)
  // set::countはコンテナ内に見つかった要素の数を返す、つまり直接交友関係でなければ0を返す
  // 友達関係は既に引いているので、友達候補でブロックしているものを引く必要がある
  // (友達関係を二重で引いてしまう恐れがある)
  // 条件2と3をみたすものを数えられているので、そこから!条件1 && 条件2 && 条件3」の組み合わせを引く
  // 友達でないものを探すのをlog(M)で行うことができる
  rep3(i, 0, K) if (!friends[C[i]].count(D[i]) && uf.same(C[i], D[i])) {
    ans[C[i]]--;
    ans[D[i]]--;
  }

  // 出力
  rep3(i, 0, N) {
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  cout << endl;
}
