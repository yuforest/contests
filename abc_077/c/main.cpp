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

int ans[2010];
int N, M;

int main() {
  ll N;
  cin >> N;
  vl A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  ll ans = 0;
  // 3つのものを考えるときは、真ん中を固定して考える
  // 上部のパーツとして使えるのは大きさが[0,B[b])のもので、下部のパーツとして使えるのは大きさが(B[b],10^9]のものである。
  // 上部のパーツとして使えるものの個数a = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
  // 下部のパーツとして使えるものの個数c = N - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());
  rep(j, N) {
    // ai<bj  を満たす i の個数
    long long Aj = lower_bound(A.begin(), A.end(), B[j]) - A.begin();
    // ci ≤ bj  (不等号に等号が付くことに注意) を満たす i の個数を求めて、それを N から引けばよい
    long long Cj = N - (upper_bound(C.begin(), C.end(), B[j]) - C.begin());
    debug(Aj);
    debug(Cj);
    ans += Aj * Cj;
  }
  cout << ans << endl;
  return 0;
}

// upper_bound -> 探索したい値より大きい値が現れる最初の位置のイテレータ取得
// lower_bound -> 探索したい値以上が現れる最初の位置のイテレータを取得