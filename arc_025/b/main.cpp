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

int ans[2010];

int main() {
  ll H, W;
  cin >> H >> W;
  vvl C(H+1, vl(W+1));
  rep3(i, 1, H+1) rep3(j, 1, W+1) {
    cin >> C[i][j];
  }
  debug(C);
  // 累積和を保存する
  vvl black(H+1, vl(W+1, 0));
  vvl white(H+1, vl(W+1, 0));
  // 累積和の計算
  rep3(i, 1, H+1) rep3(j, 1, W+1) {
    if ((i+j) % 2 == 0) {
      black[i][j] = black[i-1][j] + black[i][j-1] - black[i-1][j-1] + C[i][j];
      white[i][j] = white[i-1][j] + white[i][j-1] - white[i-1][j-1];
    } else {
      white[i][j] = white[i-1][j] + white[i][j-1] - white[i-1][j-1] + C[i][j];
      black[i][j] = black[i-1][j] + black[i][j-1] - black[i-1][j-1];
    }
  }
  ll ans = 0;
  rep3(y1, 1, H+1) rep3(x1, 1, W+1) rep3(y2, y1, H+1) rep3(x2, x1, W+1) {
    // debug(y1);
    // debug(x1);
    // debug(y2);
    // debug(x2);
    ll black_sum = black[y2][x2] - black[y1-1][x2] - black[y2][x1-1] + black[y1-1][x1-1];
    ll white_sum = white[y2][x2] - white[y1-1][x2] - white[y2][x1-1] + white[y1-1][x1-1];
    if (y1 == 2 && x1 == 2 && y2 == 3 && x2 == 4) {
      debug(black_sum);
      debug(white_sum);
    }
    debug(black_sum);
    debug(white_sum);
    ll area = (y2-y1+1) * (x2-x1+1);
    if (black_sum == white_sum) {
      chmax(ans, area);
    }
  }
  debug(white);
  debug(black);
  cout << ans << endl;
  return 0;
}