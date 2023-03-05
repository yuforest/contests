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

long long N, X[1 << 18], Y[1 << 18];
long long Q, T[1 << 18];
long long min_X = (1LL << 60), max_X = -(1LL << 60);
long long min_Y = (1LL << 60), max_Y = -(1LL << 60);

int main() {
  // Step #1. 入力
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
  for (int i = 1; i <= Q; i++) cin >> T[i];

  // Step #2. 全点の座標を45 度回転(右側に)
  // 回転前のマンハッタン距離 = 回転後のチェビシェフ距離（座標の差の最大値）
  for (int i = 1; i <= N; i++) {
    // X座標
    long long p1 = X[i] + Y[i];
    // Y座標
    long long p2 = Y[i] - X[i];
    X[i] = p1;
    Y[i] = p2;
    // 最小の X, Y, 最大の X, Y を求める
    min_X = min(min_X, X[i]);
    max_X = max(max_X, X[i]);
    min_Y = min(min_Y, Y[i]);
    max_Y = max(max_Y, Y[i]);
  }

  // Step #3. クエリに答える
  // 45度回転させた後の2点のマンハッタン距離は、max(|x1-x2|, |y1-y2|)となる
  // よって、最小の X, Y, 最大の X, Y を求めておけば、答えを求めることができる
  for (int i = 1; i <= Q; i++) {
    long long ret1 = abs(X[T[i]] - min_X);
    long long ret2 = abs(X[T[i]] - max_X);
    long long ret3 = abs(Y[T[i]] - min_Y);
    long long ret4 = abs(Y[T[i]] - max_Y);
    cout << max({ ret1, ret2, ret3, ret4 }) << endl;
  }
  return 0;
}