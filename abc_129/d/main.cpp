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

int ans[2010];
int N, M;
ll A[101010];
ll X[101010];

int main() {
  int H, W;
  cin >> H >> W;
  string S[H];
  rep(i, H) cin >> S[i];
  vvi horizontal(H, vector<int>(W, -1));
  vvi vertical(H, vector<int>(W, -1));

  // 左から右に走査
  for(int i = 0; i < H; i++) {
    int current = 0;
    for(int j = 0; j < W; j++) {
      if (S[i][j] == '.') {
        current++;
        horizontal[i][j] = current;
      } else {
        current = 0;
      }
    }
  }
  // 左から右に走査
  for(int i = 0; i < H; i++) {
    for(int j = W-2; j >= 0; j--) {
      if (S[i][j] == '.') {
        horizontal[i][j] = max(horizontal[i][j], horizontal[i][j+1]);
      }
    }
  }

  // 上から下に走査
  for(int i = 0; i < W; i++) {
    int current = 0;
    for(int j = 0; j < H; j++) {
      if (S[j][i] == '.') {
        current++;
        vertical[j][i] = current;
      } else {
        current = 0;
      }
    }
  }
  // 下から上に走査
  for(int i = 0; i < W; i++) {
    for(int j = H-2; j >= 0; j--) {
      if (S[j][i] == '.') {
        vertical[j][i] = max(vertical[j][i], vertical[j+1][i]);
      }
    }
  }
  int ans = 0;
  // 最大の照らす範囲を検索
  rep(i, H) rep(j, W) ans = max(ans, horizontal[i][j] + vertical[i][j] - 1);

  cout << ans << endl;
  return 0;
}