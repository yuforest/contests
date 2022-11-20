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

int main() {
  int N;
  cin >> N;
  // Si  := A1,…,Ai の総和(累積和)
  // Mi  := S1,…,Si の最大値(累積和の累積max)
  vector<long long> A(N), S(N+1, 0), M(N+1, 0);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
    M[i+1] = max(M[i], S[i+1]);
  }
  long long res = 0, cur = 0;
  // 最初のi回の操作を終えた後の位置Pに
  // A1,A2..Aiをしていった時の結果はP + Siとなる
  // その過程で座標の最大値はP + Miとなる
  for (int i = 0; i < N; ++i) {
    // 例えばi＝0の時ここでは1回目に取りうる最大値を計算し更新している
    res = max(res, cur + M[i+1]);
    // そして次のループでは1回目のループが終わった状態から始めるのでS[1]を足すことになる
    cur += S[i+1];
  }
  cout << res << endl;
}