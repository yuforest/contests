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

long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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


string N;
// 下i桁まで確定していて、次の桁に追加でd円払う必要がある時の使った紙幣の最小枚数
int dp[1010101][2];

int inf = INT_MAX / 2;
int main(){
  cin >> N;
  reverse(all(N));

  int n = N.length();
  // 初期化
  rep3(i, 0, n + 1) rep3(d, 0, 2) dp[i][d] = inf;
  dp[0][0] = 0;
  // 下の桁から確定させていく
  rep3(i, 0, n) rep3(d, 0, 2) if (dp[i][d] != inf) {
    // 今の桁の値
    int c = N[i] - '0';
    // 合計して10なら今の桁で追加で払う必要はなく、次の桁で1枚多く払う
    if (c == 9 and d == 1) chmin(dp[i + 1][1], dp[i][d]);
    else {
      // d=1の時は今の桁で追加で払う必要がある
      if (d == 1) c++;
      // 次の桁で追加で払う必要がない
      chmin(dp[i + 1][0], dp[i][d] + c);
      // 次の桁で1枚多く払う
      chmin(dp[i + 1][1], dp[i][d] + 10 - c);
    }
  }
  // d=1の時は次の桁の分があるので1枚足している
  int ans = min(dp[n][0], dp[n][1] + 1);
  cout << ans << endl;
}