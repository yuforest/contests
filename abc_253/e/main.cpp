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
#include <atcoder/all>
using namespace atcoder;

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

using mint = atcoder::modint998244353;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector dp(n + 1, vector(m, mint(0)));
  // 最初に選ぶ数字はなんでも良い
  rep(j, m) dp[1][j] = 1;
  for(int i = 1; i < n; i++) {
    // 累積和配列
    vector<mint> cum(m + 1);
    rep(j, m) cum[j + 1] = cum[j] + dp[i][j];
    // 今回までの全ての組み合わせ数
    mint al = cum.back();
    // lとrの間にある組み合わせ数を求める
    auto get = [&cum](int l, int r) -> mint {
      if(l > r) return 0;
      return cum[r] - cum[l];
    };
    // 0からm-1までの範囲にしている
    // 1からmまでの範囲としても範囲の大きさは変わらない
    rep(j, m) {
      // 全ての組み合わせ数から次に遷移できない範囲の組み合わせ数を引いて
      // 遷移を行う
      // jは現在見ている数字
      // lの指定でj-kの範囲は含みたいからj-k+1を指定している
      dp[i + 1][j] = al - get(max(j - k + 1, 0), min(j + k, m));
    }
  }
  // 最後の行の合計を求める
  cout << accumulate(all(dp.back()), mint(0)).val() << endl;
  return 0;
}