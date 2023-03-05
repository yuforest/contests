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

// int main() {
//   ll N;
//   cin >> N;
//   vl A(N);
//   ll sum = 0;
//   rep(i, N) {
//     cin >> A[i];
//     sum += A[i];
//   }
//   if (sum % 10 != 0) {
//     cout << "No" << endl;
//     return 0;
//   }
//   ll target = sum / 10;
//   debug(sum);
//   debug(target);
//   // 2周分入れておく
//   vl B;
//   rep(i, N) B.push_back(A[i]);
//   rep(i, N) B.push_back(A[i]);
//   ll l = 0;
//   ll cur = 0;
//   bool ok = false;
//   rep(r, 2*N) {
//     cur += B[r];
//     while(cur > target && l < 2*N) {
//       cur -= B[l];
//       l++;
//     }
//     if (target == cur) {
//       ok = true;
//       break;
//     }
//   }
//   if (ok) {
//     cout << "Yes" << endl;
//   } else {
//     cout << "No" << endl;
//   }

// }


long long N, A[1 << 19];
long long B[1 << 19];

int main() {
  // Step #1. Input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // Step #2. Make Array B
  // 2周分の累積和配列を作る
  for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];
  for (int i = 1; i <= N; i++) B[i + N] = B[i + N - 1] + A[i];
  // 合計が10の倍数でなければ不可能
  if (B[N] % 10LL != 0LL) {
    cout << "No" << endl;
    return 0;
  }

  // Step #3. Get Answer
  // 左側を全探索しながら、右側を二分探索することで高速化できる
  for (int i = 0; i <= N; i++) {
    // ゴールは左側までの合計も含むので、それを足した値を検索する
    long long goal = B[i] + B[N] / 10LL;
    debug(goal);
    int pos1 = lower_bound(B, B + 2 * N + 1, goal) - B;
    if (B[pos1] == goal) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}