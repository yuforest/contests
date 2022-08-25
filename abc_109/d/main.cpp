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

int H, W, A[505][505];
int main() {
  // 奇数の物を右に詰めていって、最後に最右で奇数の物を下に詰めていくと、右下が1になるかならないかになる
  cin >> H >> W;
  rep(y, H) rep(x, W) cin >> A[y][x];

  vector<tuple<int, int, int, int>> ans;
  rep(y, H) rep(x, W - 1) {
    // 現在の位置が奇数なら右に詰めていく
    if (A[y][x] % 2 == 1) {
      // 盤面を操作
      A[y][x]--;
      A[y][x + 1]++;
      ans.push_back(make_tuple(y, x, y, x + 1));
    }
  }
  // 各行の一番右が奇数なら下に詰めていく
  rep(y, H - 1) {
    if (A[y][W-1] % 2 == 1) {
      // 盤面を操作
      A[y][W - 1]--;
      A[y + 1][W - 1]++;
      ans.push_back(make_tuple(y, W - 1, y + 1, W - 1));
    }
  }

  int n = ans.size();
  printf("%d\n", n);
  fore(t, ans) {
    int a, b, c, d;
    tie(a, b, c, d) = t;
    printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
  }
  return 0;
}