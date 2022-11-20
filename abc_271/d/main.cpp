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

#define yes "Yes"
#define no "No"


// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
const ll INF = ll(1e18);

int main() {
  int N, S;
  cin >> N >> S;
  int a[N], b[N];
  rep(i, N) cin >> a[i] >> b[i];
  vvb dp(N+1, vb(S+1, false));
  dp[0][0] = true;
  rep(i, N) {
    rep(j, S+1) {
      if (dp[i][j] == false) continue;
      if (j + a[i] <= S) {
        dp[i+1][j+a[i]] = true;
      }
      if (j + b[i] <= S) {
        dp[i+1][j+b[i]] = true;
      }
    }
  }

  // 経路復元
  if (!dp[N][S]) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  string ans(N, 'H');
  for(int i = N-1; i >= 0; i--) {
    if (S >= a[i] && dp[i][S-a[i]]) {
      ans[i] = 'H';
      S -= a[i];
    } else {
      ans[i] = 'T';
      S -= b[i];
    }
  }
  cout << ans << endl;
  return 0;
}

