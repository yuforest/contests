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

int ans[2010];

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll T;
  cin >> T;
  //  長さ2N の文字列 S
  // Sにおける0の位置をa1, a2..anとするとS+Sにおける0の位置は
  // a1, a2,aN, a1+N, an+2N
  // よってN個目の0と2N個目の0の距離はちょうど2Nであり、これらの間には
  // ちょうどN個の1があることを意味する
  // つまり0*N+1*N+0を出力することで
  // 少なくともN文字目までに0*Nが現れ、N文字目が0であっても
  // N+1から2Nまでの間に1がN回出現することは保証されているので
  // 条件を満たす(この場合Sの最後が0なので余分な0があっても問題ない)
  // 他の場合、例えば1010でも同様
  // 0011は5文字目で条件を満たす
  rep(i, T) {
    ll N;
    cin >> N;
    string S[3];
    rep(i, 3) cin >> S[i];
    string ans = "";
    rep(i, N) ans+="0";
    rep(i, N) ans+="1";
    ans += "0";
    cout << ans << endl;

  }
}