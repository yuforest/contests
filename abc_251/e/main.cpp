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

const ll inf = 1e18;
int n;
int a[300005];
// 行動 1,2,…,i までは行うかどうかを決定しており、さらに、行動iはj 回行うときの、それまでにかかる合計費用としてあり得る最小値
// 行動iは0回か1回行えば良い
ll dp[300005][2];
int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  ll ans = inf;
  // 行動1を行う場合と行わない場合
  for(int t = 0; t <= 1; t++){
    // t=0の時はdp[1][0]=0,dp[1][1]はinf
    // t=1の時はdp[1][1]=a[1],dp[1][0]はinf
    dp[1][t] = a[1]*t, dp[1][1-t] = inf;

    // もらうDP
    for(int i = 2; i <= n; i++){
      // これは行動を行わない場合、この場合は前回行動をしている必要がある
      dp[i][0] = dp[i-1][1];
      // これは行動を行う場合、この場合は前回行動した場合と行動しなかった場合の
      // 最小値に今回のコストをたす
      dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
    }
    // 答えを更新、t=0の時はn回目で必ず行動する必要がある
    // t=1の場合はどちらでもよい
    if(t == 0) ans = min(ans, dp[n][1]);
    if(t == 1) ans = min(ans, min(dp[n][0], dp[n][1]));
  }
  cout << ans << endl;

  return 0;
}