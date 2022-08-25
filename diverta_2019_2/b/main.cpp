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

int N;
vector<long long> x, y;

int solve() {
  // Nが1なら必ずコストが1となる
  if (N == 1) return 1;

  int res = N;
  // p, qを決める(i!=jについての(xj-xi, yj-yi)を全列挙、差がある組み合わせの逆の場合も考慮)
  // どの 2 点をとってもその差ベクトルになってないような p,q を使ったらペナルティは N−1 になる(1)
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      long long dx = x[j] - x[i], dy = y[j] - y[i];
      // 決め打ちした差と同じになっているもの(コストが0で除去できるもの)
      int sub = 0;
      // iとjを全て試すことで逆の組み合わせに関しても考慮できている
      for (int i2 = 0; i2 < N; ++i2) {
        for (int j2 = 0; j2 < N; ++j2) {
          // 同じ点の場合はスキップ
          if (j2 == i2) continue;
          if (dx == x[j2] - x[i2] && dy == y[j2] - y[i2]) ++sub;
        }
      }
      res = min(res, N - sub);
    }
  }
  return res;
}

int main() {
  cin >> N;
  x.resize(N);
  y.resize(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
  cout << solve() << endl;
  return 0;
}