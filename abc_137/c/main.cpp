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

int N, x[101], y[101], h[101];

int main() {
  cin >> N;
  rep3(i, 0, N) cin >> x[i] >> y[i] >> h[i];
  // ピラミッドの中心座標を全探索
  rep3(cx, 0, 101) rep3(cy, 0, 101) {
    // 高度を見ると、「H-中心とのマンハッタン距離」になっているので、
    // 逆に中心は「h[i]+中心とのマンハッタン距離」の高さになっている
    // h[i]=0になっているものは距離が分からないので、中心の高さを求めるのには使わない
    int H = 1;
    // ループしているがh[i]が0でないものなら一つだけわかれば良い
    rep3(i, 0, N) if (h[i]) H = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
    // 全ての頂点に対してチェック
    int ok = 1;
    rep3(i, 0, N) if (max(H - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]) ok = 0;
    if (ok) {
      printf("%d %d %d\n", cx, cy, H);
      return 0;
    }
  }
  return 0;
}