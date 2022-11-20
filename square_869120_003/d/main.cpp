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
// usng namespace atcoder;

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


template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}


vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

// dp[i][j]:= Aiまでのうち、すでにj個の要素をBの要素として選んだときの、ここまでの計算結果の最大値
long long dp[2001][2001];
const ll INF = ll(1e18);
int main() {
  int n,m;
  cin>>n>>m;
  vector<long long> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  dp[0][0]=0;
  dp[0][1]=-1000000000000000000ll;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
      // i個のうちまだ0個しか選んでいない
      if(j==0) dp[i][0] = 0;
      // i個以上多くは選べないのでマイナスの値を入れておく
      else if(j > i) dp[i][j] = -1000000000000000000ll;
      // dp[i−1][j] は AiをBの要素として選ばなかった場合であり、
      // dp[i−1][j−1]+j×AiはAiを B の j 番目の要素として選んだ場合となります
      // もらうDP
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+a[i-1]*j);
    }
  }
  cout << dp[n][m] << endl;

}

