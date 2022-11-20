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
#include <atcoder/all>
using namespace atcoder;

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


int main() {
  ll N;
  cin >> N;
  vl a(N);
  vl b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  sort(b.begin(), b.end());
  set<ll> ans;
  // xを決めたときa[i] ^ b[i] = xとなるようにbを並び替えることができるかどうかは、
  // c[i] = a[i] ^ xとして、bとcが並び替えて一致することと同値
  // 入力例で考える
  // 3
  // 1 2 3
  // 6 4 7
  rep(i, N) {
    // ソートしてるのでi=0の時1^4 = 001 ^ 100 = 5(101)となる
    // xの候補はN通りを試せば十分
    // a[i] ^ b[j]が全てxになるのだからbを固定しても
    ll x = a[i] ^ b[0];
    vector<ll> c(N);
    // この時cは{4, 7, 6}となる
    // xに対してそれぞれaの各要素をXORするとbを復元できる(順不同で)
    // なぜなら結果は全て同じxとなるから、aとXORを取ると
    // aの部分が打ち消されbの要素だけが残る
    rep(j, N) {
      c[j] = a[j] ^ x;
    }
    // O(NlogN)
    sort(c.begin(), c.end());
    // 並び変えるとcとbは同じになる
    if (c == b) ans.insert(x);
  }
  cout << ans.size() << endl;
  fore(x, ans) {
    cout << x << endl;
  }

  return 0;
}