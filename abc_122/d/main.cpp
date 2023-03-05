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

ll dp[101][4][4][4];
ll MOD = 1e9 + 7;
 
int main() {
  int N;
  cin >> N;
  rep(i, 4) rep(j, 4) rep(k, 4) {
    dp[3][i][j][k] = 1;
  }
  // 0,1,2,3はそれぞれA,G,C,Tを表す
  dp[3][0][1][2] = 0;
  dp[3][0][2][1] = 0;
  dp[3][1][0][2] = 0;
  // 4文字目からN文字目まで見ていく
  for(int a = 4;a <= N;a++) {
    // i,j,kはそれぞれ3文字前、2文字前、1文字前を表す
    // nは今の文字を表す
    rep(i, 4) rep(j, 4) rep(k, 4) rep(n, 4) {
      // AGC
      if(j == 0 && k == 1 && n == 2) continue;
      // ACG
      if(j == 0 && k == 2 && n == 1) continue;
      // GAC
      if(j == 1 && k == 0 && n == 2) continue;
      // 今の文字がC、1文字前がG、3文字前がAの場合はNG
      if(i == 0 && k == 1 && n == 2) continue;
      // 今の文字がC、2文字前がG、3文字前がAの場合はNG
      if(i == 0 && j == 1 && n == 2) continue;
      (dp[a][j][k][n] += dp[a - 1][i][j][k]) %= MOD;
    }
  }

  ll ans = 0;
  rep(i, 4) rep(j, 4) rep(k, 4) {
    ans += dp[N][i][j][k];
    ans %= MOD;
  }
  cout << ans << endl;
}