// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// int main() {
//   ll N;
//   cin >> N;
//   vl A(N);
//   rep(i, N) cin >> A[i];
//   ll Q;
//   cin >> Q;
//   vl l(Q), r(Q);
//   rep(i, Q) cin >> l[i] >> r[i];
//   vl times;
//   times.push_back(0);
//   rep(i, N/2+1) {
//     if (i==0) continue;
//     times.push_back(A[2*i] - A[2*i-1]);
//   }
//   vl S_times(N/2+1, 0);
//   rep3(i, 1, times.size()) {
//     S_times[i] = S_times[i-1] + times[i];
//   }
//   debug(times);
//   debug(S_times);
//   rep(i, Q) {
//     ll idx1 = lower_bound(all(A), l[i]) - A.begin();
//     ll idx2 = lower_bound(all(A), r[i]) - A.begin();
//     debug(idx1, idx2);
//     debug(idx1/2, idx2/2);
//     ll ans = 0;
//     ans += S_times[idx2/2] - S_times[idx1/2];
//     debug(ans);
//     if (idx2 > 0 && idx2%2==0) {
//       ans -= (A[idx2]-r[i]);
//     }
//     debug(ans);
//     if (idx1%2==0) {
//       ans += (A[idx1] - l[i]);
//     }
//     debug(ans);
//     cout << ans << endl;
//   }

// }

int main() {
  unsigned N;
  cin >> N;
  vector<unsigned> A(N), fA(N);
  for (auto &&a : A)
      cin >> a;
  // fA[i] := A[i] 分までに何分寝たか
  for (unsigned i = 1; i < N; ++i)
      if (i % 2 == 0)
          fA[i] = fA[i - 1] + A[i] - A[i - 1];
      else
          fA[i] = fA[i - 1];
  unsigned Q;
  cin >> Q;
  debug(A);
  // f(x) := x 分までに何分寝たか
  auto f{[&A, &fA](auto x) -> unsigned {
    // 二分探索でAj < x < Aj+1となるようなjを探す
    const auto j = upper_bound(begin(A) + 1, end(A), x) - begin(A) - 1;
    // (fA[j + 1] - fA[j])は寝ていない時間には0になる
    // よって(fA[j + 1] - fA[j]) / (A[j + 1] - A[j])寝ていない時間には0、
    // 寝ている時間には1になる
    // よってA[j]からxまでの時間を上記にかけることでx分までに何分寝たかがわかる
    return fA[j] + (fA[j + 1] - fA[j]) / (A[j + 1] - A[j]) * (x - A[j]);
  }};
  for (unsigned i = 0; i < Q; ++i) {
    unsigned l, r;
    cin >> l >> r;
    cout << f(r) - f(l) << endl;
  }
  return 0;
}