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

const int MA = 1000001;
int N, A[201010];
int cnt[1010101];
bool ok[1010101];
int main() {
  cin >> N;
  rep3(i, 0, N) cin >> A[i];

  // 配列に登場した数字をカウント
  rep3(i, 0, N) cnt[A[i]]++;
  // 全てをtrueで初期化
  rep3(x, 1, MA) ok[x] = true;

  // 調和級数的計算量になる
  // rep(i,1,N) for(j=i;j<=N;j+=i) というループ構造はO(NlogN)で行える
  // 1回以上登場していたら
  rep3(x, 1, MA) if(0 < cnt[x]) {
    // 2回以上登場していたらその数自身も使えない
    if (1 < cnt[x]) ok[x] = false;
    // その数の倍数をfalseに変更する
    // ここの計算量がlog(N)となる
    // 数字が増える度に探索すべき数は加速度的に減っていくため
    for (int x2 = x * 2; x2 < MA; x2 += x) ok[x2] = false;
  }

  // A[i]を探索してokがtrueになっているものをカウントする
  int ans = 0;
  rep3(i, 0, N) if (ok[A[i]]) ans++;
  cout << ans << endl;
}