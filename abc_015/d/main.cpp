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


int main(){
  int W, N, K;
  cin >> W >> N >> K;
  int A[N], B[N];
  rep(i, N) cin >> A[i] >> B[i];
  // 3次元のDP配列(どこまで選んだか、個数制限、幅制限)
  // dp[i][j][k]:=  i番目以下のスクショから j 個以下選び、幅kがWを超えないように荷物を選んだ時の価値の最大値
  // 計算量はO(NKW) = 10000 * 50 * 50 = 25000000
  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(W + 1, 0)));
   for(int i = 1; i <= N; ++i) {
      for(int j = 1; j <= K; ++j) {
        for(int k = 0; k <= W; ++k) {
          // もらうDP
          // 現在の幅に対してスクショの幅が足りている時のみk-A[i-1]から遷移できる
          if(k >= A[i-1]) {
            // j個選んでいてi-1番目を選ばないときと、j-1個選んでいてk-A[i-1]から遷移できる時を比較
            dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-1][k-A[i-1]] + B[i-1]);
          } else {
            // スクショの幅が足りていない時はそれが選べないので、現在見ているところに一つ前の値を移すのみ
            // 数は変化せず、幅も変化しない
            dp[i][j][k] = dp[i-1][j][k];
          }
        }
      }
    }
    cout << dp[ N ][ K ][ W ] << endl;
  return 0;
}
