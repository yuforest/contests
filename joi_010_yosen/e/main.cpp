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

string S[1001];
bool used[1001][1001];
int dp[1001][1001];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int H, W, N;

void reset() {
  rep(i, 1001) {
    rep(j, 1001) {
      used[i][j] = 0;
      dp[i][j] = 0;
    }
  }
}

ll bfs(int sy, int sx, int gy, int gx) {
  reset();
  queue<pair<int, int>> que;
  que.push({sy, sx});
  used[sy][sx] = true;
  dp[sy][sx] = 0;
  // 幅優先探索
  while (!que.empty()) {
    auto q = que.front();
    que.pop();
    int h, w;
    tie(h, w) = q;

    rep(i, 4) {
      int hh = h + dy[i];
      int ww = w + dx[i];
      if (hh < 0 || hh >= H) continue;
      if (ww < 0 || ww >= W) continue;
      if (used[hh][ww] == true) continue;
      if (S[hh][ww] == 'X') continue;
      // 他の探索経路から同じ場所を探索してしまうことがあるので
      // この時点で訪問済みにして距離も入れておくと良い
      dp[hh][ww] = dp[h][w] + 1;
      used[hh][ww] = true;
      que.push({hh, ww});
    }
  }
  debug(dp[gy][gx]);
  return dp[gy][gx];
}

int main() {
  cin >> H >> W >> N;
  rep(i, H) cin >> S[i];
  vpii points;
  rep(i, H) rep(j, W) {
    if (S[i][j] == 'S') {
      points.push_back({i, j});
    }
  }
  rep3(c, 1, N+1) {
    rep(i, H) rep(j, W) {
      if (S[i][j] == '0' + c) {
        points.push_back({i, j});
      }
    }
  }
  debug(points);
  ll ans = 0;
  // チーズ工場、次の目的地
  rep3(i, 1, N+1) {
    // 幅優先探索で距離を求める
    ans += bfs(points[i-1].first, points[i-1].second, points[i].first, points[i].second);
  }
  cout << ans << endl;
  return 0;
}