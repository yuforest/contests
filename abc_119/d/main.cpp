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

int A, B, Q; ll S[101010], T[101010];
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> A >> B >> Q;
  rep(i, A) cin >> S[i];
  rep(i, B) cin >> T[i];

  rep(q, Q) {
    ll x;
    cin >> x;
    ll ans = 1e18;

    // 左だけに移動
    // 現在位置が神社と寺の最小値より大きいとき
    if (S[0] < x && T[0] < x) {
      // 現在地以上の1つ前を求める
      int s = lower_bound(S, S + A, x) - S - 1;
      int t = lower_bound(T, T + B, x) - T - 1;
      // 距離の最大値で更新
      chmin(ans, max(x - S[s], x - T[t]));
    }

    // 右だけに移動
    // 現在位置が神社と寺の最大値より小さいとき
    if (x < S[A-1] && x < T[B-1]) {
      int s = lower_bound(S, S + A, x) - S;
      int t = lower_bound(T, T + B, x) - T;
      // 距離の最大値で更新
      chmin(ans, max(S[s] - x, T[t] - x));
    }

    // 左右
    // 神社と寺でそれぞれ一番近いものへの距離を求める
    ll shrine = 1e18;
    if (S[0] < x) {
      int id = lower_bound(S, S + A, x) - S - 1;
      chmin(shrine, x - S[id]);
    }
    if (x < S[A - 1]) {
      int id = lower_bound(S, S + A, x) - S;
      chmin(shrine, S[id] - x);
    }

    ll temple = 1e18;
    if (T[0] < x) {
      int id = lower_bound(T, T + B, x) - T - 1;
      chmin(temple, x - T[id]);
    }
    if (x < T[B - 1]) {
      int id = lower_bound(T, T + B, x) - T;
      chmin(temple, T[id] - x);
    }
    // どちらも左だった場合、どちらも右だった場合で足し算してしまう可能性もあるが、
    // この場合はずっと移動の方が良い結果になるので、問題ない
    chmin(ans, shrine*2 + temple);
    chmin(ans, shrine + temple * 2);

    printf("%lld\n", ans);
  }
}