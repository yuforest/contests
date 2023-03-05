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

int N, C;
int imos[30][101010];
int main() {
  cin >> N >> C;
  rep(i, N) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; c--;
    imos[c][a]++;
    imos[c][b]--;
  }
  // 累積和を計算する
  rep(c, C) rep3(i, 1, 101010) imos[c][i] += imos[c][i - 1];
  // ダブっている区間が1ではなく2になるので、
  // 1以上のものを1にする
  rep(c, C) rep(i, 101010) if (imos[c][i]) imos[c][i] = 1;

  int ans = 0;
  // 全ての時間について
  rep(i, 101010) {
    // その時間に何チャンネルが放送されているか
    int cnt = 0;
    // チャンネルを見ていく
    rep(c, C) cnt += imos[c][i];
    // 最大値更新
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}