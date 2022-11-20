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
  // 本選は K 個の都市で開催し，本選の際には全ての選手をそれらのいずれかの都市に移動させなければならない
  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<ll, pair<int, int>>>E(M);
  rep(i, M) {
      int a, b; ll c;
      cin >> a >> b >> c;
      a--; b--;
      // コスト順に並べるため
      E[i] = { c,{a,b} };
  }
  // コストでソート
  sort(E.begin(), E.end());
  dsu G(N);
  ll ans = 0;
  vector<ll>E_use;
  // 最小全域木を求める
  rep(i, M) {
    int a, b; ll c;
    c = E[i].first;
    a = E[i].second.first;
    b = E[i].second.second;
    // 連結していなければ連結してコストを追加
    if (!G.same(a, b)) {
      G.merge(a, b);
      ans += c;
      E_use.push_back(c);
    }
  }
  // 降順ソート
  sort(E_use.rbegin(), E_use.rend());
  K--;
  // K-1回ansから使用済みコストの大きいものを引く
  // 例えば開催都市が2つの場合、それらの都市をつなぐ辺が一つ不要になる
  // よって最大の辺を最小全域木のコストから差し引けばよい
  rep(i, K) ans -= E_use[i];

  cout << ans << endl;
}