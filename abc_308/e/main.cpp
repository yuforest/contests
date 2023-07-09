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

// mexの計算
ll mex(multiset<ll> &s) {
  ll res = 0;
  while (s.count(res)) res++;
  return res;
}

int main(){
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];
  string S;
  cin >> S;
  vector<map<ll, map<multiset<ll>, ll>>> dp(N+1);
  ll ans = 0;
  rep(i, N) {
    if (S[i] == 'M') {
      dp[i+1][1][{A[i]}]++;
    }
    if (S[i] == 'E') {
      fore(x, dp[i][1]) {
        // 2個目を選ぶ
        multiset<ll> tmp = x.first;
        tmp.insert(A[i]);
        dp[i+1][2][tmp] += x.second;
      }
    }
    if (S[i] == 'X') {
      fore(x, dp[i][2]) {
        multiset<ll> tmp = x.first;
        tmp.insert(A[i]);
        ans += mex(tmp) * x.second;
      }
    }
    // 1個選んでいて今回選ばない場合
    fore(x, dp[i][1]) {
      dp[i+1][1][x.first] += x.second;
    }
    // 2個選んでいて今回選ばない場合
    fore(x, dp[i][2]) {
      dp[i+1][2][x.first] += x.second;
    }
  }
  debug(dp);
  cout << ans << endl;
}