// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
// vector<ll> G[1 << 18];
// vector<ll> rG[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int N, M, A[1010], B[1010], takara[1010];
int dp[1010][1 << 12];
// 2^12 = 4096
// bitDP=全探索の効率化
// 鍵を使うかどうかを全探索すると2^1000の計算量になるが間に合わないので
// DPを使って計算量を減らす
int main(){
  cin >> N >> M;
  rep(i, M) {
    cin >> A[i] >> B[i];
    rep(j, B[i]) {
      int c;
      cin >> c;
      c--;
      // 開けられる宝箱の集合をビットで表現
      takara[i] |= 1 << c;
    }
  }
  // 初期化
  rep(i, M + 1) rep(msk, 1 << N) dp[i][msk] = 1e9;
  // dp[i][msk] := i番目の鍵まで使用するかが決まっていて、
  // 開けられる宝箱の集合がmskであるのに必要な費用の最小値
  dp[0][0] = 0;

  // 10^3*4096 = 4*10^6程度の計算量
  rep(i, M) rep(msk, 1 << N) {
    // i番目の鍵を使わない場合
    chmin(dp[i + 1][msk], dp[i][msk]);
    // i番目の鍵を使う場合、開けられる宝箱の集合を更新
    chmin(dp[i + 1][msk | takara[i]], dp[i][msk] + A[i]);
  }

  // 全ての鍵を見た時に、開けられる宝箱の集合が全て1になっている場合の最小値
  int ans = dp[M][(1 << N) - 1];
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
}