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

int ans[2010];

int main() {
  int H, W;
  cin >> H >> W;
  vvl values(H, vl(W, 0));
  rep(i, H) {
    rep(j, W) cin >> values[i][j];
  }
  int res = 0;
  rep(msk, (1 << H)) {
    auto values2 = values;
    // bit全探索で選んだ行をひっくり返す
    rep(i, H) {
      // 何もしない
      if (!(msk & (1<<i))) continue;
      // ひっくり返す
      for (int j = 0; j < W; ++j) values2[i][j] = 1 - values2[i][j];
    }
    int tmp = 0;
    // 各列ごとに0と1のどちらが多いかを調べて多い方を追加している
    // どちらにしろ列をひっくり返すことで多い方に揃えることができる
    for (int j = 0; j < W; ++j) {
      int num = 0;
      for (int i = 0; i < H; ++i) if (values2[i][j] == 0) ++num;
      tmp += max(num, H-num);
    }
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}