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


// 周期性、こういう系の問題は最初にループして100個くらい値を出力してみることで見えてくるものがある
// ループの検出方法を頭の隅に置いておく(インデックスを通った場所、通った時のインデックスを値とする配列、-1でなければ過去に通過済み)
// ループに満たない時、周回数、周回した後の余りなどについて考慮したコードを書く
long long solve() {
  long long N, X, M;
  cin >> N >> X >> M;

  // かつて来た地点を求める
  // インデックスの値が入る、-1で初期化
  vector<int> ord(M, -1);
  vector<long long> rireki, syu;
  // 関数の和
  long long res = 0;
  for (int n = 0; n < N; ++n) {
    // かつて来た地点に戻ったら
    if (ord[X] != -1) {
      // pを過去のインデックスにして
      int p = ord[X];
      // 現在の値nまでループしてsyuに追加した後break
      for (long long i = p; i < n; ++i) syu.push_back(rireki[i]);
      break;
    }
    ord[X] = n;
    // 現在の値を履歴に残しておく
    rireki.push_back(X);
    res += X;
    // Xを更新
    X = (X * X) % M;
  }
  N -= rireki.size();

  // かつて来た時点に戻る前に N 項目に到達した場合
  if (N == 0) return res;

  // 周期の累積和をとる
  vector<long long> sum(syu.size() + 1, 0);
  for (int i = 0; i < syu.size(); ++i) sum[i+1] = sum[i] + syu[i];

  // 周期を q 週して r あまる
  long long q = N / syu.size();
  long long r = N % syu.size();
  res += sum[syu.size()] * q + sum[r];
  return res;
}

// ダブリングでも解ける
// ダブリングとは？
// 全体の要素数がN個あって1回移動した時にどの要素に到達するか定まっているとき、K個先の要素を求めるのに
// O(K) -> 前処理をO(NlogK), クエリをO(logK)で行うことができるアルゴリズム(繰り返し二乗法もその一つ)
// dp[i][j]: j番目の要素から2^i回遷移した時の到達点, i<= j <= N, 0 <= i log2Kを切り上げたもの

// O(MlogN)
// long long solve() {
//   long long N, X, M;
//   cin >> N >> X >> M;

//   // 2^55とかしとけば十分という意?
//   const int MAXD = 55;
//   // nex[t][v] := v(modM) から 2^t ステップ進んだ先の値
//   // sum[t][v] := v(modM) から 2^t 項分の総和
//   vector<vector<long long>> nex(MAXD+1, vector<long long>(M, -1)),
//                             sum(MAXD+1, vector<long long>(M, 0));
//   // 初期値セット
//   for (long long r = 0; r < M; ++r) {
//     nex[0][r] = r * r % M;
//     sum[0][r] = r;
//   }
//   // DP配列の計算、O(MlogN)
//   for (int p = 0; p < MAXD; ++p) {
//     for (int r = 0; r < M; ++r) {
//       // r(modM) から 2^t ステップ進んだ先の値
//       nex[p+1][r] = nex[p][nex[p][r]];
//       // r(modM) から 2^t 項分の総和、累積和
//       sum[p+1][r] = sum[p][r] + sum[p][nex[p][r]];
//     }
//   }
//   long long res = 0;
//   int cur = X;
//   for (int p = MAXD; p >= 0; --p) {
//     // 2^55, 2^54...2^0まで一致する箇所があればその都度足していく
//     if (N & (1LL<<p)) {
//       // 和を足していく
//       res += sum[p][cur];
//       // 次の余りの値を更新
//       cur = nex[p][cur];
//     }
//   }
//   return res;
// }


int main() {
  cout << solve() << endl;
  return 0;
}