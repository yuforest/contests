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
int main() {
  ll H, W, K, V;
  cin >> H >> W >> K >> V;
  vvl A(H+1, vl(W+1, 0));
  rep3(i, 1, H+1) {
    rep3(j, 1, W+1) {
      cin >> A[i][j];
      A[i][j] += A[i][j-1];
    }
  }
  rep3(i, 1, W+1) {
    rep3(j, 1, H+1) {
      A[j][i] += A[j-1][i];
    }
  }
  debug(A);
  ll ans = 0;
  rep3(h1, 1, H+1) {
    rep3(w1, 1, W+1) {
      rep3(h2, h1, H+1) {
        rep3(w2, w1, W+1) {
          ll area = (h2 - h1 + 1) * (w2 - w1 + 1);
          // 家と土地の合計
          ll cost = (area * K) + A[h2][w2] - A[h2][w1-1] - A[h1-1][w2] + A[h1-1][w1-1];
          if (cost <= V) {
            debug(area);
            chmax(ans, area);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}