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

int main(void)
{
  int N;
  cin >> N;
  vector<pair<int, int>> va, vb;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    va.push_back({ x, i });
    vb.push_back({ y, i });
  }

  vector<tuple<int, int, int>> edges;
  // 昇順ソート
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  // 全ての辺をx座標でソートすると、隣り合った頂点間の辺しか使われない
  // 同様に全ての辺をy座標でソートして隣り合った頂点間の辺も利用する
  // 差の内小さい方であるため、わざわざ大きい辺を張る必要はない
  // N^2で辺を張ろうとするとTLEになるため
  rep(i, N - 1) {
    // X座標の差を辺のコストとする場合
    edges.push_back(make_tuple(va[i + 1].first - va[i].first, va[i].second, va[i + 1].second ));
    // Y座標の差を辺のコストとする場合
    edges.push_back(make_tuple(vb[i + 1].first - vb[i].first, vb[i].second, vb[i + 1].second));
  }
  // 辺のコストでソート
  sort(edges.begin(), edges.end());

  dsu uf(N);
  ll ans = 0;
  for (auto p : edges) {
    int x, y, c;
    tie(c, x, y) = p;

    if (!uf.same(x, y)) {
      uf.merge(x, y);
      ans += c;
    }
  }
  cout << ans << endl;
}