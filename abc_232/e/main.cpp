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

using Fp = modint998244353;
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  // kごとに状態数は高々4つ
  // それはx,yごとにスタートとゴールの位置が異なるか同じかの2通り
  // dp[0][0]: 今(x2, y2)にいる
  // dp[0][1]: 今(x2, y | y!=y2)にいる
  // dp[1][0]: 今(x, y2 | x!=x2)にいる
  // dp[1][1]: 今(x, y | x!=x2 && y!=y2)にいる
  array<array<Fp, 2>, 2> dp = {};
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  // 0回目の時点でスタートとゴールの位置が異なるならdp[1][1]に1を入れる
  // 同じならdp[0][0]に1を入れる
  dp[x1 != x2][y1 != y2] = 1;
  while (k--) {
    // 次の状態を計算
    array<array<Fp, 2>, 2> next = {};
    // どちらかが一致しているところからどちらも一致しているところに遷移する
    next[0][0] = dp[1][0] + dp[0][1];
    // どちらも一致しているところから今の列以外に遷移する+
    // 行が一致しているところから今の列とゴール列以外に遷移する+
    // 行も列も一致していないところからゴールと同じ行に遷移する
    next[0][1] = (w-1) * dp[0][0] + (w-2) * dp[0][1] + dp[1][1];
    // どちらも一致しているところから今の行以外に遷移する+
    // 列が一致しているところから今の行とゴール行以外に遷移する+
    // 行も列も一致していないところからゴールと同じ列に遷移する
    next[1][0] = (h-1) * dp[0][0] + (h-2) * dp[1][0] + dp[1][1];
    // 行が一致しているところから今の行以外に遷移する+
    // 列が一致しているところから今の列以外に遷移する+
    // 行も列も一致していないところから、今の行とゴールの行以外に遷移する+
    // 行も列も一致していないところから、今の列とゴールの列以外に遷移する
    next[1][1] = (h-1) * dp[0][1] + (w-1) * dp[1][0] + (h-2) * dp[1][1] + (w-2) * dp[1][1];
    // 操作後の値を更新
    dp = move(next);
  }
  cout << dp[0][0].val() << '\n';
  return 0;
}