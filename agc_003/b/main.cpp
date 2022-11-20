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

// A=(1,2,1)
// この場合は、(1, 2) と (2, 3) の 2 ペア作れる。しかし (2, 2) をペアリングしてしまうと (1, 3) をペアにできない
// 正しくは、数列 A を「0」の部分で区切った区間ごとに考えたとき、

// 区間の総和が偶数なら余すことなく、ペアリングできる
// 区間の総和が奇数なら 1 枚だけ余して、ペアリングできる

int main() {
  int N; cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  long long res = 0, sum = 0;
  for (int i = 0; i < N;) {
    int j = i;
    // しゃくとり的に0が出てくるまで区間を進める
    while (j < N && a[j]) sum += a[j++];
    // 0でない区間の和が偶数ならsumを2で割ったもの, 奇数ならsum-1を2で割ったものとなる
    res += sum / 2;
    sum = 0;
    i = j+1;
  }
  cout << res << endl;
}

// 嘘解法
// int main() {
//   ll N;
//   cin >> N;
//   ll A[N];
//   rep(i, N) cin >> A[i];
//   ll ans = 0;
//   ans += A[0] / 2;
//   A[0] %= 2;
//   rep3(i, 1, N) {
//     if (A[i-1] > 0 && A[i] > 0) {
//       A[i-1] -= 1;
//       A[i] -= 1;
//       ans++;
//     }
//     ans += A[i] / 2;
//     A[i] %= 2;
//   }
//   cout << ans << endl;
//   return 0;
// }
