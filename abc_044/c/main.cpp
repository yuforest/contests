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
using vvvl = vector<vector<vector<ll>>>;
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
  ll N, A;
  cin >> N >> A;
  vl x(N);
  rep(i, N) cin >> x[i];
  vvvl dp(N+1, vvl(51, vl(2501, 0)));
  // dp[i][j][k] := i番目までのカードを使って、j枚選んだときの合計がkになる場合の数
  dp[0][0][0] = 1;
  rep(i, N){
    rep(j, 51){
      rep(k, 2501){
        if(j == 0){
          // 選ばない場合
          dp[i+1][j][k] = dp[i][j][k];
        }else{
          // 選ぶ場合、遷移可能なら遷移する
          if(k - x[i] >= 0){
            dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
          }else{
            dp[i+1][j][k] = dp[i][j][k];
          }
        }
      }
    }
  }
  ll ans = 0;
  rep3(i, 1, 51) {
    rep3(j, 1, 2501) {
      if(j == A * i) ans += dp[N][i][j];
    }
  }
  cout << ans << endl;
  return 0;
}