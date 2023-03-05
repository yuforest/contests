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


#define INF 1LL << 60
ll H, W;
// 最大と最小の差を返す関数
ll f(ll a, ll b, ll c) {
  ll ma = max(a, max(b, c));
  ll mi = min(a, min(b, c));
  return ma - mi;
}

// 縦3つに分ける方法と横3つに分ける方法を試す
ll solA() {
  ll res = INF;
  // 高さが3以上である必要がある
  if (2 < H) {
    // 3の倍数なら確実に0
    if (H % 3 == 0) return 0;
    // 3で割った余りが1の時にも2の時にもW分だけの差が生まれる
    res = min(res, W);
  }

  if (2 < W) {
    // 3の倍数なら確実に0
    if (W % 3 == 0) return 0;
    // 3で割った余りが1の時にも2の時にもH分だけの差が生まれる
    res = min(res, H);
  }

  return res;
}
// 縦に1度切ってから片方を上下に切るか、横に1度切ってから片方を左右に切る
ll solB() {
  ll res = INF;

  // 最初に縦に切る分け方を全通り試している、O(W)
  rep3(x, 1, W) {
    ll xx = x;

    // その後に片方を上下に分けるときは均等に分けるのが良い
    ll b = H / 2;
    // 切った欠片はそれぞれ
    // 上下に切った上、上下に切った下、縦に切った右側となる
    res = min(res, f(xx * b, xx * (H - b), (W - xx) * H));
  }

  // 最初に横に切る分け方を全通り試している、O(H)
  rep3(y, 1, H) {
    ll yy = y;

    // その後に片方を左右に分けるときは均等に分けるのが良い
    ll b = W / 2;
    // 切った欠片はそれぞれ
    // 左右に切った左、左右に切った右、横に切った下側となる
    res = min(res, f(yy * b, yy * (W - b), (H - yy) * W));
  }

  return res;
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> H >> W;

  ll ans = min(solA(), solB());
  cout << ans << endl;
}
