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

int N, M, R;
int d[202][202];
int r[202];
#define INF INT_MAX/2

int main() {
  cin >> N >> M >> R;
  // 配列rの全ての組み合わせを試すことができる
  // 8!は40320通りなので、全探索できる
  // 変な制約に着目する
  rep(i, R) cin >> r[i];

  rep(i, N) rep(j, N) {
    if (i == j) d[i][j] = 0;
    else d[i][j] = INF;
  }
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    // 双方向に結ぶ
    d[a][b] = c;
    d[b][a] = c;
  }

  // 二点間の最短距離を高速に求めるためにワーシャルフロイド法を使う
  // iからjまでkを経由して行く場合の最短距離を求める
  rep(k, N) rep(i, N) rep(j, N)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  vector<int> v;
  // 0-indexedにする
  rep(i, R) v.push_back(r[i] - 1);
  // ソートして初めから全部試す
  sort(v.begin(), v.end());
  int ans = INF;
  // R! * R = 40320 * 8 = 322560通り
  do {
    int sm = 0;
    // 街の間の移動距離を足していく
    rep(i, R - 1) sm += d[v[i]][v[i + 1]];
    // 最小値更新
    ans = min(ans, sm);
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}
