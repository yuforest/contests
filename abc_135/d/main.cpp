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

using mint = modint1000000007;
string S;
int N;
// 桁DP
int main() {
  cin >> S;
  N = S.length();

  // dp[dgt][mo] := 上からdgt桁目まで確定していて、そこまでで13で割った余りがmoである組み合わせ
  vector<vector<mint>> dp(N + 1, vector<mint>(13, 0));

  // 0桁目まで確定していて、そこまでで13で割った余りが0である組み合わせは1通り
  dp[0][0] = 1;
  rep(dgt, N) rep(mo, 13){
    // ?の時は、0~9の数字を使う
    if (S[dgt] == '?') {
      // 0~9まで
      rep(nxt, 10) {
        // 次の桁の余りは、今の桁の余り(mo)に10をかけて、
        // その後に今の桁の数字(nxt)を足したものを13で割った余り
        dp[dgt + 1][(mo * 10 + nxt) % 13] += dp[dgt][mo];
      }
    }
    // ?でない時は、その数字を使う
    else {
      // 次の桁の余りは、今の桁の余り(mo)に10をかけて、その後に今の桁の数字を足したものを13で割った余り
      // そこに今の組み合わせを足す
      dp[dgt + 1][(mo * 10 + S[dgt] - '0') % 13] += dp[dgt][mo];
    }
    debug(dgt, mo, dp[dgt][mo].val());
  }


  // N桁目まで確定していて、そこまでで13で割った余りが5である組み合わせの個数を出力
  cout << dp[N][5].val() << endl;
}
