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

const ll INF = ll(1e18);

int main() {
  ll N;
  cin >> N;
  string S[5];
  rep(i, 5) cin >> S[i];
  vvl dp(N+1, vl(4, INF));
  char colors[4] = {'#', 'R', 'B', 'W'};
  rep(i, 4) {
    dp[0][i] = 0;
  }
  // 列を全て見る
  rep(i, N) {
    // 現在の色を全探索
    rep(j, 4) {
      if (dp[i][j] == INF) continue;
      // 現在の色から次の色に遷移(黒以外)
      // 次の色を全探索
      rep3(k, 1, 4) {
        // 今の色と次の色が同じならcontinue
        if (k == j) continue;
        // この列をjの色に変更するコスト
        ll cost = 0;
        // i列を全探索して次の色のコスト計算
        rep(l, 5) {
          if (S[l][i] == colors[k]) {
            continue;
          }
          cost++;
        }
        dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
      }
    }
  }
  debug(dp);
  ll ans = INF;
  rep(i, 4) {
    chmin(ans, dp[N][i]);
  }
  cout << ans << endl;
}