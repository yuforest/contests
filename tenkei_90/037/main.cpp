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

// RMQのセグメント木
class RangeMax {
public:
  int size_ = 1;
  vector<long long> dat;

  void init(int sz) {
    while (size_ <= sz) size_ *= 2;
    dat.resize(size_ * 2, -(1LL << 60));
  }
  void update(int pos, long long x) {
    pos += size_;
    dat[pos] = x;
    while (pos >= 2) {
      // 右シフト
      pos >>= 1;
      dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
    }
  }
  long long query_(int l, int r, int a, int b, int u) {
    if (l <= a && b <= r) return dat[u];
    if (r <= a || b <= l) return -(1LL << 60);
    long long v1 = query_(l, r, a, (a + b) >> 1, u * 2);
    long long v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
    return max(v1, v2);
  }
  long long query(int l, int r) {
    return query_(l, r, 0, size_, 1);
  }
};

long long W, N;
long long L[1 << 18], R[1 << 18], V[1 << 18];
long long dp[509][10009];
RangeMax Z[509];

int main() {
  // Step #1. 入力
  cin >> W >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> V[i];

  // Step #2. 初期化
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) dp[i][j] = -(1LL << 60);
    // セグメント木の配列を初期化
    Z[i].init(W + 2);
  }
  dp[0][0] = 0;
  Z[0].update(0, 0);

  // Step #3. 動的計画法
  for (int i = 1; i <= N; i++) {
    // 前までの状態は今回も実現可能なのでコピー
    for (int j = 0; j <= W; j++) dp[i][j] = dp[i - 1][j];
    for (int j = 0; j <= W; j++) {
      // もらうDPの遷移、半開区間なので右側は+1
      int cl = max(0, j - (int)R[i]), cr = max(0, j - (int)L[i] + 1);
      // どちらも0の場合は、遷移不可能
      if (cl == cr) continue;
      // clからcrの範囲の最大値をセグメント木から取得、計算量はO(logW)
      long long val = Z[i - 1].query(cl, cr);
      // 遷移可能であれば、遷移後の最大値を更新
      if (val != -(1LL << 60)) {
        dp[i][j] = max(dp[i][j], val + V[i]);
      }
    }
    // 現在のdp[i][j]をセグメント木に反映
    for (int j = 0; j <= W; j++) Z[i].update(j, dp[i][j]);
  }

  // Step #4. 出力
  if (dp[N][W] == -(1LL << 60)) cout << "-1" << endl;
  else cout << dp[N][W] << endl;
  return 0;
}