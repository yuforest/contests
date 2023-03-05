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

int N, A[10101];
map<int, int> primes[10101];
using mint = modint1000000007;
map<int, int> enumpr(int n) {
  map<int, int> V;
  for (int i = 2; 1LL*i*i <= n; i++) while (n%i == 0) V[i]++, n /= i;
  if (n>1) V[n]++;
  return V;
}

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  rep(i, N) primes[i] = enumpr(A[i]);

  map<int, int> allPrimes;
  // 各素因数毎に個数の最大値を取って、全部合わせて最小公倍数を求める
  rep(i, N) fore(p, primes[i]) chmax(allPrimes[p.first], p.second);
  mint lcm = 1;
  fore(p, allPrimes) {
    rep(i, p.second) lcm *= mint(p.first);
  }

  mint ans = 0;
  rep(i, N) {
    // 最小公倍数/A[i]でB[i]を求める
    mint b = lcm / mint(A[i]);
    ans += b;
  }
  cout << ans.val() << endl;
}