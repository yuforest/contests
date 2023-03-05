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

ll H, W, Q;
int id(int h, int w) {
  return (h * W) + w;
}

bool grid[2000][2000];
int dh[4] = { 0, 1, 0, -1 }, dw[4] = { -1, 0, 1, 0 };

int main() {
  cin >> H >> W >> Q;
  dsu uf(H*W);
  rep(i, Q) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll h, w;
      cin >> h >> w;
      h--;w--;
      grid[h][w] = true;
      rep(i, 4) {
        ll nh = h + dh[i];
        ll nw = w + dw[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (grid[nh][nw]) uf.merge(id(h, w), id(nh, nw));
      }
    } else if (t == 2) {
      ll h1, w1, h2, w2;
      cin >> h1 >> w1 >> h2 >> w2;
      h1--;w1--;h2--;w2--;
      if (grid[h1][w1] && grid[h2][w2] && uf.same(id(h1, w1), id(h2, w2))) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}