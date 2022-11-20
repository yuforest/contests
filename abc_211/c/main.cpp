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
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define fore(i, a) for (auto &i : a)

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b)
{
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b)
{
  return ((a > b) ? (a = b, true) : (false));
}

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

int main(void)
{
  string s;
  cin >> s;
  int n = s.size();
  vector dp(n+1, vector<int>(9));
  // jの0文字目まで選んだ時の通り数は1通り
  rep(i,n+1) dp[i][0] = 1;
  const int mod = 1000000007;
  string t = "chokudai";
  rep(i,n)rep(j,8) {
    if (s[i] != t[j]) {
      dp[i+1][j+1] = dp[i][j+1];
    } else {
      // 一致する時ここまでの文字の選び方を足す
      dp[i+1][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
    }
  }
  cout << dp[n][8] << endl;
  return 0;
}