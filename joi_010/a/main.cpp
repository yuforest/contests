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

int main() {
  int M, N, K;
  cin >> M >> N >> K;
  string S[M];
  rep(i, M) cin >> S[i];
  vvi jungle(M+1, vi(N+1, 0));
  vvi ocean(M+1, vi(N+1, 0));
  vvi ice(M+1, vi(N+1, 0));
  rep(i, M) {
    rep(j, N) {
      if (S[i][j] == 'J') jungle[i+1][j+1]++;
      if (S[i][j] == 'O') ocean[i+1][j+1]++;
      if (S[i][j] == 'I') ice[i+1][j+1]++;
    }
  }
  // 横方向の累積和
  rep3(i, 1, M+1) {
    rep3(j, 1, N+1) {
      jungle[i][j] = jungle[i][j-1] + jungle[i][j];
      ocean[i][j] = ocean[i][j-1] + ocean[i][j];
      ice[i][j] = ice[i][j-1] + ice[i][j];
    }
  }
  // 縦方向の累積和
  rep3(i, 1, N+1) {
    rep3(j, 1, M+1) {
      jungle[j][i] = jungle[j-1][i] + jungle[j][i];
      ocean[j][i] = ocean[j-1][i] + ocean[j][i];
      ice[j][i] = ice[j-1][i] + ice[j][i];
    }
  }
  debug(jungle);
  debug(ocean);
  debug(ice);
  rep(i, K) {
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    int jungle_count = jungle[h2][w2] - jungle[h1-1][w2] - jungle[h2][w1-1] + jungle[h1-1][w1-1];
    int ocean_count = ocean[h2][w2] - ocean[h1-1][w2] - ocean[h2][w1-1] + ocean[h1-1][w1-1];
    int ice_count = ice[h2][w2] - ice[h1-1][w2] - ice[h2][w1-1] + ice[h1-1][w1-1];
    cout << jungle_count << " " << ocean_count << " " << ice_count << endl;
  }
  return 0;
}