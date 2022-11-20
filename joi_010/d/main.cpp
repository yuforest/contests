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


vvl used(91, vl(91));
vvl field(91, vl(91));
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int W, H;


int main() {
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N) cin >> A[i];
  vvl dp(N, vl(21, 0));
  // 1番目から始めないと最初が0のような場合に遷移が2つできてしまう
  // 1より大きければ、遷移は1つになるので問題なかった
  dp[1][A[0]] = 1;
  rep3(i, 1, N-1) {
    rep(j, 21) {
      if (dp[i][j] == 0) continue;
      ll plus = j + A[i];
      ll minus = j - A[i];
      if (plus >= 0 && plus <= 20) {
        dp[i+1][plus] += dp[i][j];
      }
      if (minus >= 0 && minus <= 20) {
        dp[i+1][minus] += dp[i][j];
      }
    }
  }
  debug(dp);
  ll last = A[N-1];
  debug(last);
  cout << dp[N-1][last] << endl;
}