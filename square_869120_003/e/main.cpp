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


ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  // 歩く経路
  vector<int> C(Q + 2);
  rep(i, Q) {
    cin >> C[i + 1];
    // 0-indexed
    C[i + 1]--;
  }
  C[0] = 0; C[Q + 1] = 0;

  vector<ll> V(N);
  // 繰り返し二乗法で隣接する街の距離を計算
  for (int i = 1; i < N; i++) V[i] = modpow(A[i - 1], A[i]);
  // 前の街から今の街までの累積和を計算
  for (int i = 1; i < N; i++) V[i] = V[i] + V[i - 1] % mod;

  ll ans = 0;
  for (int i = 1; i < Q + 2; i++) {
    // 0から先の街に行くときと0方向に戻る時を同じ式で計算する
    // 最後には必ず0に戻ってくるのでiがQ+1を作っている
    ans += V[max(C[i - 1], C[i])] - V[min(C[i - 1], C[i])] % mod;
    ans %= mod;
  }

  cout << ans << endl;
}