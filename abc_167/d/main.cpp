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


// int main() {
//   ll N, K;
//   cin >> N >> K;
//   ll A[N+1];
//   rep(i, N) {
//     cin >> A[i+1];
//   }
//   vector<int> visited(N+1, -1);
//   visited[1] = 0;
//   ll now_town = 1;
//   ll move_cnt = 0;
//   ll cycle;
//   for(int i = 0; i < N ; i++) {
//     move_cnt++;
//     now_town = A[now_town];
//     if (move_cnt == K) {
//       cout << now_town << endl;
//       return 0;
//     }
//     if (visited[now_town] == -1) {
//       visited[now_town] = move_cnt;
//     } else {
//       // 最初に発生したサイクルの検知
//       cycle = move_cnt - visited[now_town];
//       break;
//     }
//   }
//   // 今までに移動した回数を引いておく
//   K -= move_cnt;
//   // あまりを取っても現在いる位置に戻ってくる
//   K %= cycle;
//   // 余り回数のテレポーテーションを計算する
//   for(int i = 0; i < K; i++) {
//     now_town = A[now_town];
//   }
//   cout << now_town << endl;
// }



//---------------------------------------------------------------------------------------------------
void main() {
  int N;
  long long K;
  cin >> N >> K;
  // A[v] := v の1個先の町
  // B[v] = A[A[v]] という配列を用意すると、
  // B[v] := v の2個先の町
  // さらに
  // C[ v ] = B[ B[ v ] ] という配列を用意すると、
  // C[ v ] := v の 4 個先の町 (2 個先の 2 個先なので)
  // さらに
  // D[ v ] = C[ C[ v ] ] という配列を用意すると、
  // D[ v ] := v の 8 個先の町
  // next[ 0 ][ v ] = A[ v ]
  // next[ d ][ v ] = next[ d - 1 ][ next[ d - 1 ][ v ] ]
  // というDP配列を考える
  // next[ d ][ v ] := v の 2^d 個先の町
  vector<vector<int>> next(60, vector<int>(N));

  // 入力を受け取って0-indexにしている
  for (int v = 0; v < N; ++v) cin >> next[0][v], --next[0][v];
  // 2^58まで？
  for (int d = 0; d + 1 < 60; ++d) {
    for (int v = 0; v < N; ++v) {
      // vから2^d進んだ値をDP的に埋めていく
      next[d+1][v] = next[d][next[d][v]];
    }
  }
  // 街1(便宜上0-index)からスタート
  int v = 0;
  for (int d = 0; d < 60; ++d) {
    // Kのd桁目に 1 が立っているならば、
    // v = next[ d ][ v ] と現在いる街の値を更新する
    if (K & (1LL<<d)) v = next[d][v];
  }
  // 0-indexから街の1スタートに戻している
  cout << v + 1 << endl;
}