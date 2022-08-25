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

int N; ll X;
//---------------------------------------------------------------------------------------------------
ll patty[51], tot[51];
// レベルlevelバーガーの下からx番目まででパティが何枚あるか（xは0-indexed）
ll f(int level, ll x) {
  // レベル0ならパティ1枚なので1を返す(ベースケース)
  if (level == 0) return 1;

  // x=0の時バンしかないので0を返す
  if (x < 1) return 0;
  // バンの分を引く
  x--;

  // この時点でlevel-1バーガーの厚さよりxが小さければ、再帰関数を呼ぶ
  if (x < tot[level - 1]) return f(level - 1, x);
  // level-1バーガーの枚数分引く
  x -= tot[level - 1];

  // この時点でxが0になるようならlevel-1バーガーに含まれるパティ+1を返す
  if (x < 1) return patty[level - 1] + 1;
  // パティの分引く
  x--;

  // この時点で上にあるlevel-1バーガーの厚さより小さければ下のパティ+1+再帰関数で求められる上のパティを返す
  if (x < tot[level - 1]) return patty[level - 1] + 1 + f(level - 1, x);
  // level-1バーガーの枚数分引く
  x -= tot[level - 1];

  // 上のlevel-1バーガーの厚さ以上の時はlevel-1バーガーに含まれるパティ*2+1を返せば良い
  return patty[level - 1] * 2 + 1;
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> N >> X;
  // 0indexに
  X--;

  // レベルlevelバーガーの総数
  tot[0] = 1;
  rep3(L, 1, N + 1) tot[L] = tot[L - 1] * 2 + 3;
  // レベルlevelバーガーに含まれるパティの数
  patty[0] = 1;
  rep3(L, 1, N + 1) patty[L] = patty[L - 1] * 2 + 1;

  cout << f(N, X) << endl;
}