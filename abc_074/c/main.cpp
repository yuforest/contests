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
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

int dp[3030][3030];
int A, B, C, D, E, F;

int main() {
  cin >> A >> B >> C >> D >> E >> F;

  double ma = 0;
  int ans1 = 100 * A, ans2 = 0;
  // dp[i][j] := 水溶液がiグラム、そのうち砂糖がjグラムである状態にできるか
  dp[0][0] = 1;
  // 水溶液の重量と砂糖の重量
  // 全ての砂糖水の状態をシミュレーションしてDP
  // 砂糖の重量は最大で水溶液の容量まで
  rep3(i, 1, F + 1) rep3(j, 0, i + 1) {
    int water = i - j;
    int suger = j;

    // 操作1~4に対してチェックを行う
    // 遷移元のいずれかが1なら今の値も1
    // これから足す水の量がi以下で、前の状況も作ることができる
    if (100 * A <= i) if (dp[i - 100 * A][j]) dp[i][j] = 1;
    // これから足す水の量がi以下で、前の状況も作ることができる
    if (100 * B <= i) if (dp[i - 100 * B][j]) dp[i][j] = 1;
    // i,jが砂糖の量以上で、前の状況も作ることができる
    if (C <= i && C <= j) if (dp[i - C][j - C]) dp[i][j] = 1;
    // i,jが砂糖の量以上で、前の状況も作ることができる
    if (D <= i && D <= j) if (dp[i - D][j - D]) dp[i][j] = 1;

    // 砂糖が溶けきっているかつ、状態が実現可能かつ砂糖が少しでも溶けている
    // 100:E=water:suger <-釣り合っているとき
    // ここでは砂糖が残っては行けないので
    // E/100 >= suger/water
    // となるはず
    // これを変形して
    // E*water >= suger*100
    if (suger * 100 <= water * E && dp[i][j] && 0 < j) {
      // 濃度計算
      double e = 1.0 * 100 * j / i;
      // 濃度の今の最大値より大きければ更新
      if (ma < e) {
        ma = e;
        ans1 = i;
        ans2 = j;
      }
    }
  }

  printf("%d %d\n", ans1, ans2);
}