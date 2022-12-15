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

int N, M;
int dist[401][401];

// 1073741823, 10^9程度の数となる
const int inf = INT_MAX / 2;

// kの値が増えることで使える遷移が増えて、差分的な要素が出てくる
// なので、kの値を1から増やしていくことで差分計算ができないかということを考える
int main() {
  cin >> N >> M;
  // dist[s][t] := sからtへ移る場合の最短距離
  // 最初は大きな数字で初期化しておく
  rep3(i, 0, N) rep3(j, 0, N) dist[i][j] = inf;
  // 自分への遷移コストは0
  rep3(i, 0, N) dist[i][i] = 0;

  // 入力を受け取る
  rep3(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    // コストをセット
    dist[a][b] = c;
  }

  ll ans = 0;
  // 計算量はO(N^3), 400^3=64000000程度で間に合う
  // kをインクリメントしていくことで使える頂点が増えるのと同じになる
  rep3(k, 0, N) {
    // kを経由した際の2つの頂点のコストを小さいものに更新する
    // この場合まず0が使えるようになる
    // 次のループで1を経由した場合のコストが得られることになる
    rep3(i, 0, N) rep3(j, 0, N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    // kを経由した場合のコストを更新した後に、
    // 全ての2頂点でコストを答えに足していく
    // このとき2頂点が繋がっていない、すなわちコストが無限であったら
    // 答えに足さない
    rep3(i, 0, N) rep3(j, 0, N) if (dist[i][j] < inf) ans += dist[i][j];
  }
  cout << ans << endl;
}