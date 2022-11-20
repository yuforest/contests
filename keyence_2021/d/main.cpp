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

// ぬいぐるみをk種類整列済みであるとき、k+1種目のぬいぐるみを新たに整列させるときに掛かるコストは、
// k種整列させたときの順序に依存しない
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  int a[N];
  // 全ての要素を0で初期化
  int c[M]{};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    // 0-indexedに
    a[i]--;
    // ぬいぐるみの数をカウント
    c[a[i]]++;
  }
  // 累積和、全ての要素を0で初期化
  int b[M][N + 1]{};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      // M種類のぬいぐるみに対して、現在のインデックスでいくつでそのぬいぐるみが出現したか
      // それぞれ計算する
      if (a[i] == j) {
        b[j][i + 1] = b[j][i] + 1;
      } else {
        b[j][i + 1] = b[j][i];
      }
    }
  }
  // bitDP
  // M種類の状態数
  int n = 1 << M;
  // フラグが立っているものを整列済みのぬいぐるみとする
  vi dp(n);
  // Nで初期化、最大値
  for (int i = 0; i < n; i++) {
    dp[i] = N;
  }
  dp[0] = 0;
  // 状態数を全探索
  for (int i = 0; i < n; i++) {
    // 整列させたぬいぐるみの数を計算
    // 言い換えると現在の状態数の時に整列しているはずのぬいぐるみの数をカウント
    int l = 0;
    for (int j = 0; j < M; j++) {
      // フラグが立っていればj個目のぬいぐるみが整列していると言うことであり、
      // 今見ているぬいぐるみの合計数をlに追加
      if ((i & (1<<j)) != 0) {
        l += c[j];
      }
    }
    debug(l);
    // M種類のぬいぐるみを全探索
    for (int j = 0; j < M; j++) {
      int t = (1<<j);
      // 2^jのフラグが立っていないとき
      // j個目のぬいぐるみは整列していないと言うこと
      if ((i & t) == 0) {
        // j個目のぬいぐるみのフラグを立てる
        int idx = (i | t);
        // l 以降にぬいぐるみjを置くためのコスト
        // j番目のぬいぐるみのカウント
        // - (j個目のぬいぐるみが既に整列させたぬいぐるみの数+j番目のぬいぐるみのインデックスの時にいくつあるかの累積話 -
        // j個目のぬいぐるみが既に整列させたぬいぐるみの数のインデックスの時にいくつあるか)
        int cost = c[j] - (b[j][l + c[j]] - b[j][l]);
        // フラグが立った状態の状態数を更新
        // 現在見ているぬいぐるみが並んだ状態に遷移できる
        dp[idx] = min(dp[idx], dp[i] + cost);
      }
    }
    debug(dp);
  }
  // 全て整列した状態のコストが答えとなる
  cout << dp[n - 1] << "\n";
  return 0;
}
