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

int ans[2010];

int X, Y, A, B, C;
int p[101010], q[101010], r[101010];
ll smpq[201010];
ll smr[101010];

int main() {
  cin >> X >> Y >> A >> B >> C;
  rep(i, A) cin >> p[i];
  rep(i, B) cin >> q[i];
  rep(i, C) cin >> r[i];

  vector<int> pq;
  // 赤いリンゴを美味しい順にソート
  sort(p, p + A, greater<int>());
  // X個配列にpushしておく
  rep(i, X) pq.push_back(p[i]);
  // 緑のリンゴを美味しい順にソート
  sort(q, q + B, greater<int>());
  // X個配列にpushしておく
  rep(i, Y) pq.push_back(q[i]);
  // X+Y個のリンゴをソート
  sort(all(pq), greater<int>());

  smpq[0] = 0;
  // X+Y個食べた時までのの美味しさの累積和
  rep(i, X + Y) smpq[i + 1] = smpq[i] + pq[i];

  // 無色のリンゴを美味しい順にソート
  sort(r, r + C, greater<int>());
  smr[0] = 0;
  // 無色のリンゴの累積和
  rep(i, C) smr[i + 1] = smr[i] + r[i];

  ll ans = 0;
  // 無色のリンゴを全探索(0,1,2..C or 0,1,2..X+Y)
  rep(c, min(C, X + Y) + 1) {
    chmax(ans, smr[c] + smpq[X + Y - c]);
  }
  cout << ans << endl;
  return 0;
}