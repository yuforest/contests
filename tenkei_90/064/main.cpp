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

int main() {
  ll N, Q;
  cin >> N >> Q;
  vl A(N+1);
  rep3(i, 1, N+1) cin >> A[i];
  vl L(Q), R(Q), V(Q);
  rep(i, Q) {
    cin >> L[i] >> R[i] >> V[i];
  }
  debug(A);
  vl B(N);
  ll ans = 0;
  // iとi+1の階差を考える
  rep3(i, 1, N) {
    B[i] = A[i+1] - A[i];
    // 階差の絶対値の和、つまり不便さ
    ans += abs(B[i]);
  }
  debug(B);
  debug(ans);
  // L[i-1]とL[i], R[i]とR[i+1]の階差のみが変わるので
  // その部分のみ変更すれば良い
  rep(i, Q) {
    // ここの不便さだけが変わる
    long long mae = abs(B[L[i]-1]) + abs(B[R[i]]);
    if (L[i] >= 2) {
      // L[i]とL[i+1]の間はV[i]だけ変動する
      B[L[i]-1] += V[i];
    }
    if (R[i] <= N-1) {
      // R[i]とR[i+1]の間は-V[i]だけ変動する
      B[R[i]] -= V[i];
    }
    // 変わった後の不便さ
    long long ato = abs(B[L[i]-1]) + abs(B[R[i]]);
    debug(mae);
    debug(ato);
    // 地殻変動の前と後の差を計算する、変化後から変化前を引くと変化量がわかる
    ans += (ato-mae);
    cout << ans << endl;
  }
  return 0;
}