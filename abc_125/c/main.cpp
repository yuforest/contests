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

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int ans[2010];

int main() {
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];
  vector<int> left(N+1, 0), right(N+1, 0);
  // 左からの累積GCD(left[i]は左からi-1番目までの累積GCD)
  for (int i = 0; i < N; ++i) left[i+1] = gcd(left[i], A[i]);
  // 右からの累積GCD(right[i]は右からi番目までの累積GCD)
  for (int i = N-1; i >= 0; --i) right[i] = gcd(right[i+1], A[i]);

  int res = 0;
  for (int i = 0; i < N; ++i) {
    // 左側(i番目は選ばれていない)
    int l = left[i];

    // 右側
    int r = right[i+1];

    // 更新
    chmax(res, gcd(l, r));
  }
  cout << res << endl;
  return 0;
}


// セグメントツリー
// template<class Monoid> struct SegTree {
//   using Func = function<Monoid(Monoid, Monoid)>;
//   const Func F;
//   const Monoid UNITY;
//   int SIZE_R;
//   vector<Monoid> dat;

//   SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
//   void init(int n) {
//     SIZE_R = 1;
//     while (SIZE_R < n) SIZE_R *= 2;
//     dat.assign(SIZE_R * 2, UNITY);
//   }

//   /* set, a is 0-indexed */
//   void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
//   void build() {
//     for (int k = SIZE_R - 1; k > 0; --k)
//         dat[k] = F(dat[k*2], dat[k*2+1]);
//   }

//   /* update a, a is 0-indexed */
//   void update(int a, const Monoid &v) {
//     int k = a + SIZE_R;
//     dat[k] = v;
//     while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
//   }

//   /* get [a, b), a and b are 0-indexed */
//   Monoid get(int a, int b) {
//     Monoid vleft = UNITY, vright = UNITY;
//     for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
//         if (left & 1) vleft = F(vleft, dat[left++]);
//         if (right & 1) vright = F(dat[--right], vright);
//     }
//     return F(vleft, vright);
//   }
//   inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

//   /* debug */
//   void print() {
//     for (int i = 0; i < SIZE_R; ++i) {
//         cout << (*this)[i];
//         if (i != SIZE_R-1) cout << ",";
//     }
//     cout << endl;
//   }
// };


// int main() {
//     int N;
//     cin >> N;

//     // セグツリーの構築
//     SegTree<long long> seg(N, [](long long a, long long b) {
//       return gcd(a, b);
//     }, 0);
//     vector<long long> A(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> A[i];
//         seg.set(i, A[i]);
//     }
//     seg.build();

//     // 求める
//     long long res = 0;
//     for (int i = 0; i < N; ++i) {
//       long long left = seg.get(0, i);
//       long long right = seg.get(i+1, N);
//       res = max(res, gcd(left, right));
//     }
//     cout << res << endl;
// }