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

// LIS: 最長増加部分列の長さを求めるアルゴリズム
// O(NlogN)
// dp[i] := 長さが i の増加部分列として最後尾の要素のとりうる最小値
// is_strong = false のとき、同じ値が連続することを許す
template<class T> int LIS(vector<T> a,  bool is_strong = true) {
  const T INF = 1<<30; // to be set appropriately
  int n = (int)a.size();
  vector<T> dp(n, INF);
  for (int i = 0; i < n; ++i) {
      if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
      else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int N, A[1 << 19];
int P[1 << 19], Q[1 << 19];
int dp[1 << 19], cnt = 0;

int main() {
  ll N;
  // Step #1. 入力
  cin >> N;
  vl A(N+1), P(N+1), Q(N+1), dp(N+1);
  ll cnt = 0;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // Step #2. 左側の LIS を求める
  for (int i = 1; i <= N; i++) {
    // dpの最初からcntまでの位置の中でA[i]以上の最小の値の位置を求める
    int pos1 = lower_bound(dp.begin(), dp.begin() + cnt, A[i]) - dp.begin();
    // その位置にA[i]を入れる
    dp[pos1] = A[i];
    // その位置に入れたので、その位置に入れるときのLISの長さを求める
    P[i] = pos1 + 1;
    // 入れた位置がcntと同じなら、LISの長さが増える
    if (pos1 == cnt) cnt++;
  }

  // Step #3. 右側の LIS を求める
  cnt = 0;
  for (int i = N; i >= 1; i--) {
    int pos1 = lower_bound(dp.begin(), dp.begin() + cnt, A[i]) - dp.begin();
    dp[pos1] = A[i];
    Q[i] = pos1 + 1;
    if (pos1 == cnt) cnt++;
  }
  debug(P);
  debug(Q);

  // Step #4. 答えを求める
  ll Answer = 0;
  for (int i = 1; i <= N; i++) {
    Answer = max(Answer, P[i] + Q[i] - 1);
  }
  cout << Answer << endl;
  return 0;
}