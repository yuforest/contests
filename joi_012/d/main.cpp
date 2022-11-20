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

const int64_t MOD = 10000;
void add(int64_t& a, int64_t b){
  a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
  a = a*b % MOD;
}

int main() {
  int D, N;
  cin >> D >> N;
  vi T(D);
  rep(i, D) cin >> T[i];
  vi A(N), B(N), C(N);
  rep(i, N) cin >> A[i] >> B[i] >> C[i];
  debug(T);
  debug(A);
  debug(B);
  debug(C);

  // 日にちとその日の服の派手さの二次元配列
  vvl dp(D+1, vl(101, -1));
  // 1日目の服情報を先に書き込んでおく
  rep(i, N) {
    if (A[i] <= T[0] && T[0] <= B[i]) {
      debug(C[i]);
      dp[1][C[i]] = 0;
    }
  }
  // 日にちを1日目から全探索
  rep3(i, 1, D) {
    // 派手さを全探索
    rep(j, 101) {
      if (dp[i][j] == -1) continue;
      // 服を全探索
      rep(k, N) {
        if (A[k] <= T[i] && T[i] <= B[k]) {
          dp[i+1][C[k]] = max(dp[i+1][C[k]], dp[i][j] + abs(j - C[k]));
        }
      }
    }
  }
  debug(dp);
  ll ans = 0;
  rep(j, 101) {
    chmax(ans, dp[D][j]);
  }
  cout << ans << endl;
}