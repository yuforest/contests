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

// modであまりを取りながら累乗
long long modpow(long long a,long long b) {
  long long ans = 1;
  // bが0以上
  while(b) {
    // この桁は二進数でbitのフラグが立っている
    if(b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return ans;
}

// 逆元の計算
// フェルマーの小定理: ある数xのmodp(pは素数)上での逆数(=逆元)はx'=x^(p-2)で計算できる
long long modinv(long long a) {
  return modpow(a, mod - 2);
}

ll nCk(ll n, ll k) {
  ll x = 1; // 分子の初期値
  ll z = 1; // 分母の初期値

  // 分子を計算
  for(ll i = n-k+1; i <= n; i++) {
    x *= i;
    x %= mod;
  }
  // 分母を計算(k!)
  for(ll i = 1; i <= k; i++) {
    z *= i;
    z %= mod;
  }
  // 逆元を使って掛け算に変換する
  ll z_inv = modinv(z);

  return (x * z_inv % mod);
}

int main() {
  int N, K;
  cin >> N >> K;
  // 重複組合せの公式はn-1+kCn-1
  cout << nCk(N-1+K, N-1) << endl;
}