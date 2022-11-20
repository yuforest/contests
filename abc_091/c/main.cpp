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

using Point = pair<int,int>;
int main(void) {
  int N;
  cin >> N;
  vector<Point> red(N), blue(N);
  for (int i = 0; i < N; ++i) cin >> red[i].first >> red[i].second;
  for (int i = 0; i < N; ++i) cin >> blue[i].first >> blue[i].second;
  // 青い点を x 座標が小さい順にソートする (デフォルトで第一引数の辞書順比較)
  sort(blue.begin(), blue.end());

  // 各赤い点が使用済みかどうか
  vector<bool> used(N, false);

  // 青い点を順番に見ていく
  int res = 0;
  for (int i = 0; i < N; ++i) {
    // 使用済みでなく、y 座標最大の赤い点を探す
    int maxy = -1, maxid = -1;
    for (int j = 0; j < N; ++j) {
      // 使用済みの赤い点は不可
      if (used[j]) continue;

      // x 座標, y 座標がより大きい赤い点は不可、自分より小さいものを探す
      if (red[j].first >= blue[i].first) continue;
      if (red[j].second >= blue[i].second) continue;

      // 最大値を更新、y座標が大きい赤い点は売れ残りやすい
      if (maxy < red[j].second) {
        maxy = red[j].second;
        maxid = j;
      }
    }
    debug(i);
    debug(maxid);

    // 存在しない場合はスキップ
    if (maxid == -1) continue;

    // ペアリングする
    ++res;
    used[maxid] = true;
  }
  cout << res << endl;
}

// 0 4
// 4 2
// 5 5