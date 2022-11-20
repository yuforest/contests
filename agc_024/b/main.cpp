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

int ans[2010];

int N, P[201010];
int dp[201010];

int main() {
  // 先頭や末尾に移動されることのない整数たちは、その相対的な順序が変更されることはなく、
  // さらにそれらの間に新たに整数が挿入されることもない
  // 移動されない整数をx1,...xk
  // 全てのiに対し、x(i) + 1 = x(i+1)
  // 全てのiに対し、元の順列ではx(i)はx(i+1)より前にある
  // よってこのようなx1,...xkに対するkの最大値を求める
  // それ以外の整数が移動すべき整数である
  // 操作で操作される要素ではなく残った要素に注目して考える。
  // 残った要素に注目すると、操作で操作される要素は前後に自由に配置できるため、真ん中の列が残ることになる。
  // 答えはN-(部分列の中で数が連続するもので最長の長さ)となる。
  cin >> N;
    rep(i, N) cin >> P[i];
    int ans = 0;
    rep(i, N) {
      // 現在のindexの要素
      int p = P[i];
      // 例えば1 3 2 4という配列でi=0の時p=1,dp[0]=0なのでdp[1] = 1,
      // i=1の時p=3,dp[2] = 0なのでdp[3] = 1
      // i=2の時p=2,dp[1] = 1なのでdp[2] = 2
      // i=3の時p=4,dp[3] = 1なのでdp[2] = 2
      // 現在の数字の一つ前までにどれだけ連続する数があるのかという情報をもとに、
      // 現在のdp配列を更新している
      dp[p] = dp[p - 1] + 1;
      debug(dp[p]);
      chmax(ans, dp[p]);
    }

    cout << N - ans << endl;


  return 0;
}