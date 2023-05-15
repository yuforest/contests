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
long long mod2 = 998244353;
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

// modpow for mod < 2 ^ 31
long long modpow(long long a, long long n, long long mod) {
  a %= mod;
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret % mod;
};
// フェルマーの小定理
// pが素数で、aがpの倍数でない正の整数の時
// a^(p-1) ≡ 1 (mod p)

// MがPの倍数の時は余りは0になるので0を出力する
// K^NをP-1で割った商をq、余りをrとすると
// M^(K^N) = M^(q(P-1)+r) = (M^(P-1))^q * M^r ≡ M^r (mod P)
// となりM^(K^N)をPで割ったあまりは、M^KをPで割ったあまりと等しい
// (M^(P-1))^qの部分は1と合同なので消える
// よってK^NをP-1で割った余りrと
// M^rをPで割った余りを求めれば良い

using mint = modint998244353;
int main() {
  ll N, K, M;
  cin >> N >> K >> M;
  if(M % mod2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  K %= (mod2-1);
  M %= mod2;
  ll r = modpow(K, N, mod2-1);
  ll ans = modpow(M, r, mod2);
  cout << ans << endl;
  return 0;
}