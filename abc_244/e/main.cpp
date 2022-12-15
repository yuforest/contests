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

using mint = atcoder::modint998244353;
using vmint = vector<mint>;
using vvmint = vector<vector<mint>>;
using vvvmint = vector<vector<vector<mint>>>;
int N, M, K, S, T, X;
vector<int> E[2010];
// 三次元の配列
vvvmint dp(2010, vvmint(2010, vmint(2, 0)));

int main() {
  cin >> N >> M >> K >> S >> T >> X;
  // 0-indexed
  S--; T--; X--;
  // 入力を受け取りグラフを作成
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  // dp[i][lst][mod2] := 数列A[i]まで確定していて、最後の要素がlstであり、
  // Xが出現した回数を2で割った余りがmod2である
  // 数列の組み合わせ
  // 最初の要素がSで、その時もちろんXの出現回数は0回なので、
  // そのような組み合わせの数は1となる
  dp[0][S][0] = 1;
  // O(KN)、mod部分は定数倍
  // rep(lst, N) foreach(to, E[lst])と
  // toをlstから遷移可能なものにforeachで列挙するとO(N+M)
  rep(i, K) rep(lst, N) rep(mod2, 2) {
    // 最後の要素と繋がっている頂点に遷移する
    // ここの遷移は合計でMにしかならない
    fore(to, E[lst]) {
      // 次の頂点に遷移する時にその遷移先がXの時、
      // 現在Xが偶数回現れていれば(mod2が0)なら、次はmod2が1に遷移する
      // 現在Xが奇数回現れていれば(mod2が1)なら、次はmod2が0に遷移する
      dp[i + 1][to][mod2 ^ (to == X)] += dp[i][lst][mod2];
    }
  }
  // 数列の個数がK個であり、最後がTで終わり、Xが出現した回数が偶数回になる(mod2が0になる)
  // 組み合わせの数
  cout << dp[K][T][0].val() << endl;
  return 0;
}