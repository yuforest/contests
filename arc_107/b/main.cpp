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

int ans[2010];

int main() {
  ll N, K;
  cin >> N >> K;
  // Kと−Kとで答えは変わらないので、K<0 の場合は K=−K としている
  if (K < 0) K = -K;
  // Nの2倍程度の配列を確保すればよい
  // a+bの値は2から2Nまでのため
  vector<ll> num(N*2+1, 0);
  // a+bの数を全列挙して、その値をとりうるa+bの数を配列に入れる
  for (ll n = 2; n <= N*2; ++n) {
    // 2からN+1まではn-1が使われ、
    // N+2から2NまではN*2+1-nが使われる
    // N=5の場合
    // 2->1
    // 3->2
    // 4->3
    // 5->4
    // 6->5
    // 7->4
    // 8->3
    // 9->2
    // 10->1
    num[n] = min(n-1, N*2+1-n);
  }
  ll res = 0;
  // Kから2Nまで全探索して、足した値がKになるような値の組み合わせの数を足していく
  // 与式は(a+b)-(c+d)と変形できる
  // num[n]はa+bのとりうる数の組み合わせ数を表し、num[n-K]はc+bのとりうる数の組み合わせ数を表す
  for (ll n = K; n <= N*2; ++n) res += num[n] * num[n-K];
  cout << res << endl;
  return 0;
}