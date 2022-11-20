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
#include <atcoder/all>
using namespace atcoder;

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


ll n;
int main() {
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  ll ind = find(a.begin(), a.end(), 1) - a.begin();
  // indの次
  ll ind_n = (ind + 1) % n;
  debug(ind);
  debug(ind_n);
  ll ans;
  // ソートできる数列は1から右まわりか左まわりになっている
  // 末尾に先頭を移動する操作をM、反転させる操作をRとする
  // 右まわりになっている(ex: 2,3,4,1)
  if (a[ind_n] == 2) {
    // この時は操作Mのみを繰り返して昇順にする
    // もしくは最初に反転し(1,4,3,2)、Nが先頭に来るまで、操作Mを繰り返した後、最後に再度反転して
    // 昇順にする方法がある
    // つまり1のインデックス分か、(n-1のインデックス)+反転2回の小さい方となる
    // 2,3,4,1の時1のインデックスは3でありその前にある2,3,4という要素の数と一致する
    // またn-ind=4-3=1であり、1より前にある要素を除いた要素の数(例の場合は1のみ)に一致する
    ans = min(ind, n - ind + 2);
  } else {
    // 左まわりになっている(ex: 2,1,4,3)
    // この場合は操作Rによって反転させた後(3,4,1,2)、操作Mで末尾に移動させる方法と、
    // 先に操作Mで末尾に移動させた後最後に操作Rでひっくり返す方法がある
    // この時ind_nはNの位置を示している
    // 2,1,4,3の時4のインデックスである2回、操作Mをしてから、操作R1回をする
    // 反転1回とnから2を引いた4-2=2回操作Mをする方法がある
    // これらの最小値が答え
    ans = min(ind_n + 1, 1 + n - ind_n);
  }
  cout << ans << endl;
  return 0;
}