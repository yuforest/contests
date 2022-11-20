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

int ans[2010];
int N, M;

int main() {
  int a,b;
  cin >> a >> b;
  // 小数点誤差を防ぐため、6で割って10を掛けている
  double ans = (double) b / 6 * 10;
  if(ans < 25) ans = 0;
  else if(ans < 155)ans = 1;
  else if(ans < 335)ans = 2;
  else if(ans < 545)ans = 3;
  else if(ans < 795)ans = 4;
  else if(ans < 1075)ans = 5;
  else if(ans < 1385)ans = 6;
  else if(ans < 1715)ans = 7;
  else if(ans < 2075)ans = 8;
  else if(ans < 2445)ans = 9;
  else if(ans < 2845)ans = 10;
  else if(ans < 3265)ans = 11;
  else ans = 12;
  string W[17] = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","C"};
  // 22.5度間隔になっているのでif文を書くべきではない
  // ((a*10 + 1125)/2250) % 16によって0から15の数字に変換できる
  // 例えばa*10が1125の時に1125を足すことによって2250になってNNE(北北東)を指すようになる
  cout << (ans==0? W[16] : W[((a*10 + 1125)/2250) % 16]) << " " << ans << endl;
}