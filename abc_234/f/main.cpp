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

const ll MAX = 5010, MOD = 998244353;
vector<ll> fac,finv,inv;
void binom_init() {
  fac.resize(MAX);
  finv.resize(MAX);
  inv.resize(MAX);
  fac[0] = fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
    // 階乗
    fac[i] = fac[i-1]*i%MOD;
    // 逆元
    inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
    // 階乗の逆元(これを掛けることでMODを法とした割り算ができる)
    finv[i] = finv[i-1]*inv[i]%MOD;
  }
}
ll binom(ll n, ll r){
  if(n<r || n<0 || r<0) return 0;
  return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
int main(){
  // 二項係数を求めるための前処理
  binom_init();
  string S; cin >> S;
  int N = S.size();
  // 0~25まで記録できれば良い
  vector<int> freq(26);
  // 文字ごとの出現回数を記録
  for(auto el: S) freq[el-'a']++;
  // dp[i][j]: アルファベットの昇順でi番目のアルファベットまで使い、
  // 使った文字数の合計がjであるようなSの部分列、およびその並び替えの個数
  vector<vector<ll>> dp(27,vector<ll>(N+1));
  // 0文字使って0文字の並び替えは1通り
  dp[0][0] = 1;
  // 計算量はO(26N^2)かかっていそうに見えるが、
  // dp[i][j]への遷移に係る計算量が高々O(freq[i])であることを踏まえると
  // 合計の計算量は高々O((Σ_{i=0}^{25}freq[i])*N) = O(N^2)であることがわかる
  for(int i=0; i<26; i++){
    for(int j=0; j<=N; j++){
      // dp[i][j] = Σ_{k=0}^{min(j,freq[i])} dp[i][j-k]*binom(j,k)
      // ここはj文字のうち何文字をkにするかを全探索している
      for(int k=0; k<=min(j,freq[i]); k++){
        // binom(j,k)は、j個の中からk個選ぶ組み合わせの数
        dp[i+1][j] += dp[i][j-k]*binom(j,k);
        // modを取る
        dp[i+1][j] %= MOD;
      }
    }
  }
  // dp[26][i]の総和が答え
  ll ans = 0;
  for(int i=1; i<=N; i++){
    ans += dp[26][i];
    ans %= MOD;
  }
  cout << ans << endl;
}