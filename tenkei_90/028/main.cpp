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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

int main() {
  ll N;
  cin >> N;
  vvl grid(1007, vl(1007, 0));
  rep(i, N) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // 二次元累積和
    grid[y1][x1]++;
    grid[y2][x1]--;
    grid[y1][x2]--;
    grid[y2][x2]++;
  }
  rep3(i, 0, 1001) rep3(j, 0, 1001) {
    if (j == 0) continue;
    grid[i][j] += grid[i][j-1];
  }
  rep3(j, 0, 1001) rep3(i, 0, 1001) {
    if (i == 0) continue;
    grid[i][j] += grid[i-1][j];
  }
  // debug(grid);
  vl ans(N+1, 0);
  rep3(i, 0, 1001) rep3(j, 0, 1001) {
    // if (grid[i][j] < 0) debug(grid[i][j]);
    ans[grid[i][j]]++;
  }
  rep3(i, 1, N+1) {
    cout << ans[i] << endl;
  }
}