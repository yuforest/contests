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

ll diff_sum(vl array) {
  ll N = array.size();
  ll res = 0;
  rep3(i, 0, N-1) {
    debug(abs(array[i+1] - array[i]));
    res += abs(array[i+1] - array[i]);
  }
  return res;
}


int main() {
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];
  // 降順
  sort(A.begin(), A.end(), greater<long long>());
  // 偶奇で場合分け
  if (N % 2 == 0) {
    long long res = 0;
    // 2, 2, 2, 2, 1, -1, -2, -2, -2, -2の係数がつくので大きい順に割り当てていく
    for (int i = 0; i < N/2 - 1; ++i) res += A[i] * 2;
    res += A[N/2 - 1];
    res -= A[N/2];
    for (int i = N/2 + 1; i < N; ++i) res -= A[i] * 2;
    cout << res << endl;
  } else {
    // 2, 1, 1, -2, -2のような-2が2より一つ多いパターン
    long long res1 = 0;
    for (int i = 0; i < N/2 - 1; ++i) res1 += A[i] * 2;
    res1 += A[N/2 - 1] + A[N/2];
    for (int i = N/2 + 1; i < N; ++i) res1 -= A[i] * 2;

    // 2, 2, -1, -1, -2のような2が-2より一つ多いパターン
    long long res2 = 0;
    for (int i = 0; i < N/2; ++i) res2 += A[i] * 2;
    res2 -= A[N/2] + A[N/2 + 1];
    for (int i = N/2 + 2; i < N; ++i) res2 -= A[i] * 2;
    cout << max(res1, res2) << endl;
  }

  return 0;
}