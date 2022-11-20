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
#define all(x) (x).begin(), (x).end()
#define fore(i,a) for(auto &i:a)

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

int N, M, A[101010], B[101010];
int solve() {
  ll lc = 1;
  // B[i]の最小公倍数を求める
  rep(i, N) lc = lcm(lc, B[i]);

  // 求めた最小公倍数がB[i]で割り切れてしまったら0を返す
  // 例えばA[i]が2,4の時B[i]は1,2となる
  // このときlcは2となるが、これは2で割り切れるので半公倍数にならない
  // B[i]で割ったものが偶数だとA[i]で割った時も割り切れてしまう
  // B[i]は全て奇数である必要があり、そのためにはA[i]の素因数分解には2が一つのみ含まれる必要がある
  rep(i, N) if ((lc / B[i]) % 2 == 0) return 0;
  // 公倍数は最小公倍数の倍数
  ll ans = M / lc;
  // 2で割ったものを繰り上げたものが答え
  ans = (ans + 1) / 2;
  return ans;
}
int main() {
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  // B[i]はA[i]を2で割ったもの
  rep(i, N) B[i] = A[i] / 2;
  // 2で割ったB[i]の公倍数を取ればよい
  cout << solve() << endl;

}