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

#define MOD 998244353

// DP[i][f]= i 人目まで数を割り当てる方法のうち、i 人目に割り当てた数が
// 1 人目に割り当てた数と同じで ( f ? ある:ない) ものの個数
ll dp[2][1000010];
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  // 1人目まで割り当てる方法の内、1人目に割り当てた数と同じであるものはM通り
  dp[1][1]=m;
  rep3(i,1,n){
    // dp[0][i]通りは1番目と同じではないため、次の人まで見た時には
    // その数字に1番目とi番目を除いた(m-2)を掛ける
    dp[0][i+1]+=dp[0][i]*(m-2);
    // dp[0][i]通りは1番目と同じではないため、次の人まで見た時に
    // 1番目と同じになるためには1番目の数字を選ぶ
    dp[1][i+1]+=dp[0][i];
    // dp[1][i]通りは1番目と同じであるため、次の人まで見た時には
    // その数字にi(=1)番目を除いた(m-1)を掛ける
    dp[0][i+1]+=dp[1][i]*(m-1);
    // modを取る
    dp[0][i+1]%=MOD;
    dp[1][i+1]%=MOD;
  }
  // N人目まで割り当てた時に、N人目に割り当てた数が1人目に割り当てた数と同じでないものの個数
  printf("%lld\n",dp[0][n]);
}