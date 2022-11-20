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
long long mod2 = 998244353;
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

int ans[2010];
using mint = modint998244353;

int main() {
  int n, m, K;
  cin >> n >> m >> K;
  // dp[i][j]:=数列の先頭からi項まで決めた際に、総和がjであるような数列の決め方の総数
  vector dp(n + 1, vector(K + 1, mint(0)));
  dp[0][0] = 1;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < K; j++) {
      // 各項の上限はm
      for(int k = 1; k <= m; k++) {
        // ここまでの和と足そうとしている項の和がK以下なら遷移できる
        if(j + k <= K) {
          // 渡すDP
          dp[i + 1][j + k] += dp[i][j];
        }
      }
    }
  }
  mint res = 0;
  for(int i = 1; i <= K; i++) {
    res += dp.back()[i];
    debug(dp.back()[i].val());
  }
  cout << res.val() << endl;

  return 0;
}