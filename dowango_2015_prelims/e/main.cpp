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

using mint = atcoder::modint998244353;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
int main() {
  int H, W;
  cin >> H >> W;
  vector<char> C(H * W);
  for (char& c : C) {
    cin >> c;
  }
  dsu uf(H * W);
  auto id = [&](int i, int j) {
    return i * W + j;
  };
  // 縦の連結だけをしている
  for (int i = 0; i < H - 1; ++i) {
    for (int j = 0; j < W; ++j) {
      if (C[id(i, j)] == '.' and C[id(i + 1, j)] == '.') {
        uf.merge(id(i, j), id(i + 1, j));
      }
    }
  }
  // 横の連結だけをしている
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W - 1; ++j) {
      if (C[id(i, j)] == '.' and C[id(i, j + 1)] == '.') {
        uf.merge(id(i, j), id(i, j + 1));
      }
    }
  }
  int S = 0;
  // スタート地点の探索
  while (C[S] != 'S') {
    S += 1;
  }
  // 始点のマスに隣接するマス
  vector<int> around;
  // 最初の行以外にいる、上に行ける
  if (S / W != 0) {
    around.push_back(S - W);
  }
  // 最後の行以外にいる、下に行ける
  if (S / W != H - 1) {
    around.push_back(S + W);
  }
  // 最初の列以外にいる、左に行ける
  if (S % W != 0) {
    around.push_back(S - 1);
  }
  // 最後の列以外にいる、右に行ける
  if (S % W != W - 1) {
    around.push_back(S + 1);
  }
  for (int x : around) {
    for (int y : around) {
      // 最初のマスから同じ方向ではなく連結
      if (x != y && uf.same(x, y)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}