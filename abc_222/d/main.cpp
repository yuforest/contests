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

using mint = atcoder::modint998244353;
int main() {
  ll N;
  cin >> N;
  vl A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  int MAX = 3000;
  // i番目まで要素が確定していて、ci=jである場合の数、つまりjは最大値となっている
  vector dp(vector(N + 1, vector(MAX + 1, mint{0})));
  // i, jが0の時は1通り
  dp[0][0] = 1;
  rep(i, N + 1) {
    // 現在のiの累積和をとっている
    // 累積和を取る前の値はその数字が最大値となる数列がいくつあるか
    // の場合の数を示しているが累積和を取ることでjまでの数字を最大値とする
    // 数列の場合の数となる
    // これは後の遷移で、1からその数までの場合の数を足し上げる必要があるからである
    // 例えば次に遷移する数が1であれば今の数は1でなければならないが、
    // 2であれば1と2の場合が考えられる
    // よってこれまでの累積和を次の場合の和にすることができる
    debug(i);
    rep(j, MAX) {
      dp[i][j + 1] += dp[i][j];
      if (j < 5) debug(dp[i][j].val());
    }
    // iがNの時は全て確定しているので取れる値がない
    if (i != N) {
      // A[i]からB[i]までのjはiからi+1に遷移できる
      // 次の値はA[i]以上B[i]以下の値である必要がある
      // よってそれに該当する累積和の部分のみ次に遷移させる
      for (int j = A[i]; j <= B[i]; j++) dp[i + 1][j] += dp[i][j];
    }
  }
  cout << dp[N][MAX].val() << "\n";


}