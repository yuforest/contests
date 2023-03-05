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
vector<ll> G[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
// #include <atcoder/all>
// using namespace atcoder;

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

int N; ll C;
ll x[101010], v[101010];
ll y[101010];
ll A[101010], B[101010], D[101010];

ll solve() {
  A[0] = v[0];
  rep3(i, 1, N) A[i] = A[i - 1] + v[i];

  // 逆回りした時の距離計算
  rep(i, N) y[i] = C - x[i];
  // 逆から累積和計算
  B[N - 1] = v[N - 1];
  per3(i, 0, N-1) {
    debug(i);
    B[i] = B[i + 1] + v[i];
  }

  D[N - 1] = B[N - 1] - y[N - 1];
  per3(i, 0, N-1) {
    D[i] = B[i] - y[i];
    // N-1番目からi番目までの寿司を食べられる時のカロリー差の最大値
    chmax(D[i], D[i + 1]);
  }
  ll ans = 0;
  // 右端はi番目の寿司まで取るとする
  rep(i, N) {
    ll sm = 0;

    sm -= x[i]; // →移動
    sm += A[i]; // →カロリー
    // この時点で帰ることもできる
    chmax(ans, sm);

    sm -= x[i]; // 原点に戻る

    // 左側に移動するが最適な答えを見つけておく
    if (i < N - 1) sm += D[i + 1];

    // 答え更新
    chmax(ans, sm);
  }
  return ans;
}
int main() {
  cin >> N >> C;
  rep(i, N) cin >> x[i] >> v[i];

  ll ans = 0;
  // 右に動いてから左に動く場合
  chmax(ans, solve());

  // 左に動いてから右に動く場合
  reverse(v, v + N);
  rep(i, N) x[i] = C - x[i];
  reverse(x, x + N);

  chmax(ans, solve());
  cout << ans << endl;
}