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

// LIS: 最長増加部分列の長さを求めるアルゴリズム
// dp[i] := 長さが i の増加部分列として最後尾の要素のとりうる最小値
template<class T> int LIS(vector<T> a,  bool is_strong = true) {
  const T INF = 1<<30; // to be set appropriately
  int n = (int)a.size();
  vector<T> dp(n, INF);
  for (int i = 0; i < n; ++i) {
    // 二分探索で見つけたポインタに挿入
    // 既にINFでなくてそれより大きいものが存在すればその位置を現在見ている値で置き換える
  if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    debug(dp);
  }
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main(){
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i = 0; i < N; ++i) cin >> c[i];
  cout << N - LIS(c) << endl;

  return 0;
}