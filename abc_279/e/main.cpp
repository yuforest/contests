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
// vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int &i: a) {
    cin >> i;
  }

  // k = 1,2,...,M について操作を行った場合に、1,2,...,N がそれぞれどこに行くかを求める
  vector<int> b(n + 1);
  iota(b.begin(), b.end(), 0);
  for (int i: a) {
    swap(b[i], b[i + 1]);
  }
  debug(b);
  // 各要素がどこにあるかを記録
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    pos[b[i]] = i;
  }
  debug(pos);

  // 答えを求める
  // Ciにおいては、k=i の操作を飛ばしたことでそれ以降でのxとyの位置がC0の時と逆転するが、
  // xとy以外には影響を及ぼさない
  iota(b.begin(), b.end(), 0);
  for (int i: a) {
    // 現在の数列のi番目の数字が1の時、その移動を飛ばすので
    // 全てを実行した時に、b[i]があるはずの位置にはb[i+1]が存在することとなる
    if (b[i] == 1) {
      cout << pos[b[i + 1]] << '\n';
    } else if (b[i + 1] == 1) {
      // 逆に現在の数列のi+1番目の数字が1の時、その移動を飛ばすので
      // 全てを実行した時に、b[i+1]があるはずの位置にはb[i]が存在することとなる
      cout << pos[b[i]] << '\n';
    } else {
      // それ以外の時は1が最終的に存在する位置は変わらない
      cout << pos[1] << '\n';
    }
    debug(b);
    swap(b[i], b[i + 1]);
  }
}