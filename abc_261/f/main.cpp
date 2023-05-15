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

// Ci != Cj かつ Xi > Xjであるような(i, j)の個数がコストの最小値
// コストの最小値をM, 上の条件を満たすペアの数をM'とする

// 1 <= i < j <= N かつ Xi > Xjであるような(i, j)の数をM0とする
// 1 <= i < j <= N かつ Ci = Cj = k かつ Xi > Xjであるような(i, j)の数をMk(1 <= k <= N)とする
// M' = M0 - ΣMk(k = 1 to N)

// 転倒数とは
// 1 <= i < j <= N かつ Ai > Ajであるような(i, j)の数
// つまり(i, j)の組み合わせの内、左にあるのに右にあるものより大きいものの個数
// バブルソートの交換回数だが、愚直にやるとO(N^2)かかる
// BIT(Binary Indexed Tree)を使うとO(NlogN)で求められる

int c[300000];
// 色ごとに数字を保存する配列、vectorの配列
vector<int> a[300001];
int main() {
  int n, x, sz;
  long long ans = 0;
  cin >> n;
  // 色保存
  for (int i = 0; i < n; i++)cin >> c[i];
  // 色ごとに数字を保存、0-indexedにする、0は全ての色を保存する
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[0].push_back(x - 1);
    a[c[i]].push_back(x - 1);
  }
  // 要素の1点変更と区間の要素の総和を求めることができる
  // 更新できる累積和と考えて良い
  fenwick_tree<long long> fw(n);
  // 色ごとに見ていく
  // O(NlogN)で計算できる
  for (int i = 0; i <= n; i++) {
    // その色の数字の個数
    sz = a[i].size();
    for (int j = 0; j < sz; j++) {
      // これがM0の値
      // 自分より後にある数字の個数の総和を答えに足す
      if (i == 0) ans += fw.sum(a[i][j] + 1, n);
      // これがMkの値
      else ans -= fw.sum(a[i][j] + 1, n);
      // その色の数字の個数を増やす
      fw.add(a[i][j], 1LL);
    }
    // iの色の数字の個数を減らす
    // ここで増やした分を減らして、リセットしておく
    for (int j = 0; j < sz; j++)fw.add(a[i][j], -1LL);
  }
  cout << ans << endl;

  return 0;
}