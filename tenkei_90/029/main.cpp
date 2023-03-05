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

// 遅延評価セグメント木
class segment_tree {
private:
  int sz;
  std::vector<int> seg;
  std::vector<int> lazy;
  void push(int k) {
    if (k < sz) {
      lazy[k * 2] = max(lazy[k * 2], lazy[k]);
      lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
    }
    seg[k] = max(seg[k], lazy[k]);
    lazy[k] = 0;
  }
  // lからr-1の範囲に更新をかける
  void update(int a, int b, int x, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      push(k);
      return;
    }
    // 再帰的に更新
    update(a, b, x, k * 2, l, (l + r) >> 1);
    update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
    seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
  }
  // lからr-1までの最大値を求める
  int range_max(int a, int b, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return seg[k];
    // 半分の範囲の最大値を再帰的に求めていく
    int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
    int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
    return max(lc, rc);
  }
public:
  segment_tree() : sz(0), seg(), lazy() {};
  segment_tree(int N) {
    sz = 1;
    while (sz < N) {
      sz *= 2;
    }
    seg = std::vector<int>(sz * 2, 0);
    lazy = std::vector<int>(sz * 2, 0);
  }
  void update(int l, int r, int x) {
    update(l, r, x, 1, 0, sz);
  }
  int range_max(int l, int r) {
    return range_max(l, r, 1, 0, sz);
  }
};

// int main() {
//   int W, N;
//   cin >> W >> N;
//   segment_tree seg(W);
//   for (int i = 0; i < N; ++i) {
//     int L, R;
//     cin >> L >> R;
//     // 今のレンガを置いた後の高さを求める、現在の最大値+1
//     // 0-indexedで計算している
//     int height = seg.range_max(L - 1, R) + 1;
//     // ここも0-indexedで計算している
//     seg.update(L - 1, R, height);
//     cout << height << '\n';
//   }
//   return 0;
// }


int op(int a, int b) { return max(a, b); }
int e() { return 0; }
int mapping(int f, int x) { return max(f, x); }
int composition(int g, int f) { return max(g, f); }
int id() { return 0; }

int main() {
  int W, N;
  cin >> W >> N;
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(W);
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    // 今の高さを取得
    int max_h = seg.prod(l - 1, r);
    // 今の高さ+1となる
    cout << max_h + 1 << endl;
    // 範囲を更新
    seg.apply(l - 1, r, max_h + 1);
  }
}