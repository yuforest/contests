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

// 金貨がX枚、銀貨がY枚、銅貨がZ枚のときの答え(操作回数の期待値)を保存しておく
double dp[101][101][101];
// メモ化再帰をする
double f(int a,int b,int c){
  // 答えが既に入っていればそれを返す
  if(dp[a][b][c])return dp[a][b][c];
  // いずれかが100枚の時答えは0
  if(a==100||b==100||c==100)return 0;
  double ans=0;
  // どの硬貨を引いたかによって3通り考える
  // 現時点で金貨を引いたので期待値は1+金貨が現在の状態から1増えた場合の期待値
  ans+=(f(a+1,b,c)+1)*a/(a+b+c);
  // 現時点で銀貨を引いたので期待値は1+銀貨が現在の状態から1増えた場合の期待値
  ans+=(f(a,b+1,c)+1)*b/(a+b+c);
  // 現時点で銅貨を引いたので期待値は1+銅貨が現在の状態から1増えた場合の期待値
  ans+=(f(a,b,c+1)+1)*c/(a+b+c);
  // その合計が現在の答えとなる
  dp[a][b][c]=ans;
  return ans;
}

// 確率DP
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%.9f\n",f(a,b,c));
}