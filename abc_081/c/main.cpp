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

// 2147483647 / 2 = 約10億 = 10^9
#define INF INT_MAX/2
int N, F[101][11], P[101][11];
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> N;
  rep3(i, 0, N) rep3(j, 0, 10) cin >> F[i][j];
  rep3(i, 0, N) rep3(j, 0, 11) cin >> P[i][j];

  // 初期値を-10^9くらいにしておく必要がある
  int ans = -INF;
  // 1つは営業していないといけないので、msk=0は使わない
  // bit全探索
  rep3(msk, 1, 1 << 10) {
    int sm = 0;
    // N個の店を全探索
    rep3(i, 0, N) {
      int c = 0;
      // 時間帯を全探索してどちらも営業している場合のみcをインクリメント
      rep3(j, 0, 10) if (msk & (1 << j)) if (F[i][j]) c++;
      // どちらも営業している時間帯の個数によって利益が決まる
      sm += P[i][c];
    }
    // 答えを更新
    ans = max(ans, sm);
  }
  cout << ans << endl;
}