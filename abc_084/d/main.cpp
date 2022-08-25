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

int cumulative[100007];

bool is_prime(long long n) {  // is n prime or not
  for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
  }
  return true;
}

// エラトステネスの篩を作成
vector<int> makeBitPrimes(int n) {
  // 全て素数のフラグを立てておく
  vector<int> v(n + 1, 1);
  v[0] = v[1] = 0;
  rep3(i, 2, sqrt(n)) {
    if (v[i]) {
      // i * 2から操作を始めるための書き方
      for (int j = 0; i * (j + 2) < n; j++) {
        // 素数ではないのでフラグを下げる
        v[i * (j + 2)] = 0;
      }
    }
  }
  return v;
}

// エラトステネスの篩を使ってとける
int Q;
int A[101010], B[101010];
int main() {
  auto ps = makeBitPrimes(101010);
  // 条件を満たすもののフラグを立てる
  rep3(i, 1, 101010) if (ps[i] and ps[(i + 1) / 2]) A[i] = 1;
  // 累積和に変換
  rep3(i, 1, 101010) B[i] = B[i - 1] + A[i];

  cin >> Q;
  rep3(q, 0, Q) {
    int L, R;
    cin >> L >> R;

    int ans = B[R] - B[L - 1];
    printf("%d\n", ans);
  }
}

// int main() {
//   int Q;
//   cin >> Q;
//   cumulative[0] = 0;
//   cumulative[1] = 0;
//   rep3(i, 2, 100001) {
//     if (i % 2 == 0) {
//       cumulative[i] = cumulative[i-1];
//       continue;
//     }
//     if (is_prime(i) && is_prime((i + 1) / 2)) {
//       cumulative[i] = cumulative[i-1] + 1;
//     } else {
//       cumulative[i] = cumulative[i-1];
//     }
//   }
//   rep(i, Q) {
//     int l, r;
//     cin >> l >> r;
//     cout << cumulative[r] - cumulative[l-1] << endl;
//   }
//   return 0;
// }