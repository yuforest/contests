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



// 貪欲的にやっても解ける
// int main() {
//   ll N;
//   cin >> N;
//   ll R[N];
//   rep(i, N) cin >> R[i];
//   // simple increasing
//   bool simple_increasing = true;
//   rep3(i, 1, N) {
//     if (R[i] < R[i-1]) simple_increasing = false;
//   }
//   // simple decreasing
//   bool simple_decreasing = true;
//   rep3(i, 1, N) {
//     if (R[i] > R[i-1]) simple_decreasing = false;
//   }
//   if (simple_increasing || simple_decreasing) {
//     cout << 0 << endl;
//     return 0;
//   }
//   ll ans = 2;
//   // -1: decreasing, 0: neutral, 1: increasing
//   ll mode = 0;
//   rep3(i, 1, N) {
//     if (mode == 0) {
//       if (R[i] > R[i-1]) {
//         mode = 1;
//       } else if (R[i] < R[i-1]) {
//         mode = -1;
//       }
//     } else if (mode == 1) {
//       // change to decreasing
//       if (R[i] < R[i-1]) {
//         mode = -1;
//         ans += 1;
//       }
//     } else if (mode == -1) {
//       // change to increasing
//       if (R[i] > R[i-1]) {
//         mode = 1;
//         ans += 1;
//       }
//     }
//   }
//   cout << ans << endl;
//   return 0;
// }

int main() {
  ll N;
  cin >> N;
  ll R[N];
  rep(i, N) cin >> R[i];
  vvl dp(N, vl(2, 0));

  // dp[i][0 or 1]はR[i]まで見た時の最大値(0が上昇、1が下降)
  // 0,1は現在上昇中か下降中かを表している
  rep(i, N) {
    // initialization
    // 現在の点は1つなので1として初期化している
    dp[i][0] = dp[i][1] = 1;
    rep(j, i) {
      // 過去を使って現在を更新していく
      // jは過去を表す
      // 下降しているところから上昇する時
      // この時は現在の値と比べ過去のある点で下降し、その後上昇しているのでそこまでの値に1を加えている
      if (R[j] < R[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
      // 上昇しているところから下降する時
      // この時は現在の値と比べ過去のある点で上昇し、その後下降しているのでそこまでの値に1を加えている
      if (R[j] > R[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    }
  }
  debug(dp);
  ll ans = max(dp[N-1][0], dp[N-1][1]);
  if (ans < 3) cout << 0 << endl;
  else cout << ans << endl;
  return 0;
}