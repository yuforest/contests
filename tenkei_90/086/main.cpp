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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

// long long mod = 1000000007;
long long N, Q;
long long X[100], Y[100], Z[100], W[100];
long long x[100], y[100], z[100], w[100];

// 2^12=4096なので、全探索できる
long long bit_zentansaku() {
  long long ways = 0;
  // N(数列の長さ)の状態数を全探索
  // 今のbitに対してN個の要素のフラグが立っているかどうかで全探索
  for (int i = 0; i < (1 << N); i++) {
    long long bit[15];
    // iはj番目のbitが立っているかどうかを格納
    for (int j = 0; j < N; j++) bit[j + 1] = (i / (1 << j)) % 2;

    bool flag = true;
    // 今のbitに対して全ての条件を満たしているかどうかを判定
    for (int j = 1; j <= Q; j++) {
      // j番目の条件を満たしているかどうかを判定
      // どこかのbitが立っていれば良い
      if (((bit[x[j]] | bit[y[j]]) | bit[z[j]]) != w[j]) flag = false;
    }
    // 全ての条件を満たしているならば、場合の数を増やす
    // 最大でもwaysは4096
    if (flag == true) ways++;
  }
  return ways;
}

// bitごとに独立に考える
int main() {
  // Step #1. Input
  cin >> N >> Q;
  for (int i = 1; i <= Q; i++) cin >> X[i] >> Y[i] >> Z[i] >> W[i];

  // Step #2. Brute Force
  long long Answer = 1;
  // bitごとに考える
  for (int i = 0; i < 60; i++) {
    // 今回のbitを考える
    for (int j = 1; j <= Q; j++) {
      x[j] = X[j]; y[j] = Y[j]; z[j] = Z[j];
      // W[j]のi番目のbitが立っているかどうかを格納
      w[j] = (W[j] / (1LL << i)) % 2LL;
    }
    long long ret = bit_zentansaku();
    debug(ret);
    // 場合の数の積が答えとなる
    Answer *= ret;
    Answer %= mod;
  }
  cout << Answer << endl;
  return 0;
}