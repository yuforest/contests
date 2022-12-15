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

// この問題は単一始点最短閉路問題と見ることができる
// そして頂点1から始まって頂点1に帰ってくるが、同じ経路を通ってはいけないので
// 経路における頂点1に隣接する点を通る回数は2回となる
// その隣接する点から隣接する点への最短経路問題と見て、最後に1との距離を足してあげれば
// 距離を求めることができる
// その1に隣接する点の組み合わせの中で最も距離が短いものが答えとなる(N*(N-1)/2=O(N^2))
// この場合単一始点ではないのでDijkstraのN^2と合わせてO(N^4)となってしまう
// よってワーシャルフロイド法を用いてN^3で計算した方が良い
int main() {
  long long int n, m;
  cin >> n >> m;

  long long int d[301][301] = {};

  // 初期化
  for ( long long int i = 0; i <= n; i++ ) {
    for ( long long int j = 0; j <= n; j++ ) {
      // 10^11程度
      d[i][j] = 100000000000;
    }
  }

  // 入力を受け取って距離を設定する
  for ( long long int i = 0; i < m; i++ ) {
    long long int u, v, l;
    cin >> u >> v >> l;

    // 双方向グラフ
    d[u][v] = l;
    d[v][u] = l;
  }

  // ワーシャルフロイド法を使ってjからkにiを経由していった場合の最短距離を求める
  // ここで1と隣接している辺は考慮したくないのでi,j,k全て2から始める
  // iは経由点
  for ( long long int i = 2; i <= n; i++ ) {
    for ( long long int j = 2; j <= n; j++ ) {
      for ( long long int k = 2; k <= n; k++ ) {
        // 最小値更新
        d[j][k] = min( d[j][k], d[j][i] + d[i][k] );
      }
    }
  }
  // 大きな値で初期化
  long long int ans = 100000000000;

  // O(N^2)
  // 異なるiとjを全探索する、i<jとしてよい
  // なぜならi=jの時は経路として成り立たず、j<iとなるような経路はi<j
  // である経路を逆に辿ったものであるため
  // 今回は無向グラフであるため、関係ない
  for ( long long int i = 2; i <= n; i++ ) {
    // iとjは異なる必要がある
    for ( long long int j = i + 1; j <= n; j++ ) {
      // 1からiに行き、iからjに行き、jから1に行った場合の最短経路
      long long int k = d[1][i] + d[1][j] + d[i][j];
      // 最小値更新
      ans = min( ans, k );
    }
  }
  // 例えば1から辺が1つしか伸びていない場合は最適な計画を立てることができない
  // 行きと帰りの経路は異なる必要があるため
  if ( ans > 1000000000 ) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}