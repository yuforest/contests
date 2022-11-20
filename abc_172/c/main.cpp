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

int N, M, K, A[201010], B[201010];
ll Atot[201010], Btot[201010];

int main() {
  cin >> N >> M >> K;
  rep3(i, 0, N) cin >> A[i];
  rep3(i, 0, M) cin >> B[i];

  // 累積和配列作成
  Atot[0] = 0;
  rep3(i, 0, N) Atot[i + 1] = Atot[i] + A[i];
  Btot[0] = 0;
  rep3(i, 0, M) Btot[i + 1] = Btot[i] + B[i];

  int ans = 0;
  int ok = M;
  // しゃくとり法、計算量O(N)
  // aが増えるにしたがってbが小さくなっていくという単調性という性質
  rep3(a, 0, N + 1) {
    // okが0以上 && a番目までのAの本の和とBのok番目までの和がK以下になるまで
    // okをデクリメント
    while (0 <= ok && K < Atot[a] + Btot[ok]) ok--;
    // okが0より大きければ最大値更新
    if(0 <= ok) chmax(ans, a + ok);
  }
  cout << ans << endl;
  return 0;
}