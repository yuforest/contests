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


int main() {
  ll N, Q;
  cin >> N >> Q;
  vl A(N);
  rep(i, N) cin >> A[i];
  sort(A.begin(), A.end());
  vl S(N+1, 0);
  S[0] = 0;
  rep(i, N) S[i+1] += S[i] + A[i];
  debug(S);
  rep(i, Q) {
    ll x;
    ll ans = 0;
    cin >> x;
    auto low = lower_bound(A.begin(), A.end(), x);
    ll l_index = low - A.begin();
    // 5 * 20 - 29 = 71
    ans += (l_index) * x - S[l_index];
    debug(l_index);
    auto upper = upper_bound(A.begin(), A.end(), x);
    ll u_index = upper - A.begin();
    debug(u_index);
    ans += S[N] - S[u_index] - (N - u_index) * x;
    // 累積和
    // 絶対値の差
    // 順番は関係ない
    cout << ans << endl;
  }
  return 0;
}
// A: 2 5 5 6 11
// S: [ 0 2 7 12 18 29 ]
// l_index: 1
// u_index: 3
// 10
// l_index: 5
// u_index: 5
// 71
// l_index: 0
// u_index: 0
// 29

// 5
// 20
// 0

// 5 3
// 6 11 2 5 5
// 5
// 20
// 0
