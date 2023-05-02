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
// using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];
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

using mint = modint998244353;
// 高橋君がi,青木君がjにいて、f=0ならば次が高橋君、f=1ならば次が青木君の時の高橋君の勝率
// 求める値はdp[A][B][0]
mint dp[110][110][2];
int main() {
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  // 初期化
  for (int i = 0; i < n; i++) for (int f = 0; f < 2; f++) {
    // i<Nに対して、dp[N][i][f]=1, dp[i][N][f]=0
    // つまり高橋君がNにいて、青木君がiにいる時は高橋君の勝ち
    // 青木君がNにいて、高橋君がiにいる時は高橋君の負け
    dp[n][i][f] = 1;
    dp[i][n][f] = 0;
  }
  // i,jの降順にdpを計算する
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      // 1からpまでの勝率を計算する
      for (int k = 1; k <= p; k++) {
        // 先の確率をもとに、dp[i][j][0]を計算する
        // 高橋君がiにいて、青木君がjにいて次が高橋君のターンの高橋君の勝率は
        // 高橋君がこれから遷移するマスの勝率の平均になる
        dp[i][j][0] += dp[min(n, i + k)][j][1];
      }
      dp[i][j][0] /= p;
      for (int k = 1; k <= q; k++) {
        // 先の確率をもとに、dp[i][j][1]を計算する
        // 高橋君がiにいて、青木君がjにいて次が青木君のターンの高橋君の勝率は
        // 青木君がこれから遷移するマスの勝率の平均になる
        dp[i][j][1] += dp[i][min(n, j + k)][0];
      }
      dp[i][j][1] /= q;
    }
  }
  cout << dp[a][b][0].val() << '\n';
}