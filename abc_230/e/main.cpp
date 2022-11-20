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

int ans[2010];

int main() {
 long long n, ans, k;
  cin >> n;
  // √Nを求める
  for (long long i = 1; i <= n; i++) {
    if (i*i <= n)k = i;
    else break;
  }
  ans = 0;
  // [N/i] = kとなるもの
  // k0(√N)までの数は下記のように数え上げることができる
  // k <= N/i < k+1 => N/k+1 < i <= N/k(全てをNで割って逆数をとる、逆数をとると不等号の向きが変わる)
  //  [N/i] = kを変形するとk <= N/i < k+1(切り下げているのでk以上である必要があり、k+1よりは小さい)
  // 上の式を満たす整数iは([N/k] - [N/k+1])個存在する
  for (long long i = 1; i <= k; i++) ans += ((n / i) - (n / (i + 1))) * i;
  // [N/i] >= k0 + 1となるようなもの
  // i <= N/k0+1 < √Nでありたかだか√N個しか存在しない
  // [N/i] >= k0 + 1であるようなものはたかだか1回しか登場しない
  // そして数も少ない(たかだか√N個)ので足しあげていけば良い
  // 例えばN=100の時k=10なのでk+1は11となり、n / (k + 1)は9となる
  // よって100 + 50 + 33 + 25 + ... + 11を足せば良い
  for (long long i = 1; i <= n / (k + 1); i++) ans += (n / i);

  cout << ans << endl;
  return 0;
}