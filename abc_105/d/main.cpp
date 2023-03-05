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

int N, M, A[101010];
int main() {
  cin >> N >> M;
  rep(i, N) cin >> A[i];

  // 右側を固定して条件を満たす左側を高速に数え上げる
  // cnt[i] := 今までの累積和の中でmodMがiであるものの個数
  map<int, int> cnt;
  // l-1として0番目を想定している
  // つまりrまで全部取った時
  cnt[0] = 1;
  ll ans = 0, sm = 0;
  rep(i, N) {
    // 累積和をとる、smが今のrを表す
    sm += A[i];
    debug(sm);
    // [l, r]の区間和がMの倍数=[0,l)と[0, r]のそれぞれの累積和がmod Mで等しい
    // この時0からrまでの累積和からlの手前までの累積和を引くとMの倍数になる
    ans += cnt[sm%M];
    debug(cnt[sm%M]);
    debug(cnt);
    // 現在の累積和のmod Mをインクリメント
    cnt[sm%M]++;
  }
  cout << ans << endl;
}