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

int N, A[201010], B[201010];
int main() {
  cin >> N;
  rep(i, N) cin >> A[i] >> B[i];
  sort(A, A + N);
  sort(B, B + N);
  // 実は、[作ることのできる中央値の最小値,作ることのできる中央値の最大値]の範囲は全部作れる
  // 作ることのできる中央値の最小値は、AをXとして考えたときの中央値で、
  // 作ることのできる中央値の最大値は、BをXとして考えたときの中央値
  // 注意はNが奇数の時は、1刻みで作ることができるが、
  // Nが偶数の時は、0.5刻みで作ることができる
  int ans = 0;
  // 偶数の場合
  if (N % 2 == 0) {
    int AX = A[N / 2] + A[N / 2 - 1];
    int BX = B[N / 2] + B[N / 2 - 1];
    ans = BX - AX + 1;
  }
  // 奇数の場合
  else {
    int AX = A[N / 2];
    int BX = B[N / 2];
    ans = BX - AX + 1;
  }
  cout << ans << endl;
}