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


ll dp[4400][4400];

int main() {
  ll n;
  cin >> n;
  ll n2 = n*2;
  vl a(n2+1);
  // 円環は面倒なので、2 * n + 1の配列にして同じ配列が2つ連続した形に
  rep(i,n) {
    cin >> a[i+1];
    a[i+1+n] = a[i+1];
  }
  // 区間の幅
  for(int width = 1; width <= n; width++) {
    // 始点
    for(int l = 1; l <= n2-width+1; l++) {
      // 終点
      int r = l+width-1;
      // joi
      if((n-width)%2 == 0) {
        // dp[l][r]をそれぞれ一つ減らした区間にl番目やr番目を足したものの大きい方で更新
        chmax(dp[l][r], dp[l+1][r] + a[l]);
        chmax(dp[l][r], dp[l][r-1] + a[r]);
      } else {
        // ioiは貪欲的に取る
        if(a[r] < a[l]) dp[l][r] = dp[l+1][r];
        else dp[l][r] = dp[l][r-1];
      }
    }
  }
  ll ans = 0;
  // ケーキを全て取り終わった時のインデックスを全探索
  for(int i = 1; i <= n; i++) chmax(ans,dp[i][i+n-1]);
  cout << ans << endl;
}