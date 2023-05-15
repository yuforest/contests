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
// vector<ll> G[1 << 18];

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

template <class F> ll optimize(int low, int high, const F& f) {
  while (high - low > 2) {
    const int m1 = (low + high) / 2;
    const int m2 = m1 + 1;
    if (f(m1) < f(m2)) {
      low = m1;
    } else {
      high = m2;
    }
  }
  return f(low + 1);
}

void solve() {
  int n, m;
  cin >> n >> m;
  // 最初A0=0, B0=0
  ll a = 0, b = 0, ans = numeric_limits<ll>::min();
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    // Aiの値を計算する
    const auto f = [&](const int k) {
      return a + b * k + x * k * (k + 1) / 2;
    };
    // xが正の時は、最大値はx=1の時か、yの時
    // f(n+1)-f(n)=2an+a+bはnについて単純増加
    // このときこの関数は単調増加なので、三分探索は不要
    if (x > 0) {
      ans = max(ans, f(1));
      ans = max(ans, f(y));
    } else {
      // 三分探索で値を求める
      // f(n+1)-f(n)=2an+a+bはnについて単純減少
      ans = max(ans, optimize(0, y + 1, f));
    }
    // A[z(i)]の値、これはA[z(i-1)]+ΣB[z(i-1+k)](k=1~n)の値
    // A[z(i-1)]+ΣB[z(i-1)+k](k=0~n)
    // = A[z(i-1)] + Σ(B[z(i-1)]+xk)(k=1~n)
    // = A[z(i-1)] + B[z(i-1)]*n + x*n(n+1)/2
    a = f(y);
    // b[z]の値、これは今の要素数を累積的に足していくもの
    b += x * y;
  }
  cout << ans << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}