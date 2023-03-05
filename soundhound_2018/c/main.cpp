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

#define yes "Yes"
#define no "No"


// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

long long n, m, d;

int main() {
  cin >> n >> m >> d;
  // まず1組の期待値を求めて、m-1通り分足せば良い(期待値の線形性)
  // 期待値の線形性とは「和の期待値は期待値の和に等しい」こと
  // E|X+Y| = E|X| + E|Y|
  // ここではm-1通りの1つの組み合わせの差の絶対値がdである確率を足しあげれば良いことを指す
  // 分母を求める
  // d!=0である時条件を満たすペアは(1,d+1),...(n-d,n)と(d+1,1)...(n,n-d)
  // の2(n-d)個となる
  long long V = (n - d) * 2;
  // d=0の時は分子がnになる
  // 条件を満たすペアは(1,1),..(n,n)なのでn通り
  if (d == 0) V /= 2;
  // d=0の時はn/n^2=1/n
  // 選び方は全部でn^2個あるのでそれで割れば良い
  long double E = 1.0L*V / (1.0L*n*n);
  // 求めた1つの期待値*(m-1)が答えとなる
  printf("%.12Lf\n", 1.0L*(m - 1)*E);
  return 0;
}