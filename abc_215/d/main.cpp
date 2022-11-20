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

// 素因数分解して、その素因数の配列を返す
// 計算量はO(√N)
vector<int> enumPrimeOnly(int n) {
  int x = n;
  vector<int> res;
  for (int i = 2; 1LL * i * i <= n; i++) if (x % i == 0) {
    res.push_back(i);
    // 割り切れなくなるまで割る
    while (x % i == 0) x /= i;
  }
  // 最後に余ったら素数なのでそれもpush
  if (x > 1) res.push_back(x);
  return res;
}

int N, M, A[101010];
bool ng[101010];
int main() {
  cin >> N >> M;
	rep3(i, 0, N) cin >> A[i];

  rep3(i, 0, N) {
    auto ep = enumPrimeOnly(A[i]);
    // ここで使えない素因数の値を記録しておく
    fore(p, ep) ng[p] = true;
  }
  // 使えない素因数のMまでの倍数も答えではないのでフラグを立てておく
  // 計算量は調和級数になるのでO(MlogM)となる
  rep3(p, 2, M) if(ng[p]) {
    for (int y = p + p; y <= M; y += p) ng[y] = true;
  }
  // ngがtrueでないものだけをpush
  vector<int> ans;
  rep3(x, 1, M + 1) if (!ng[x]) ans.push_back(x);

  printf("%d\n", ans.size());
  fore(x, ans) printf("%d\n", x);
  return 0;
}