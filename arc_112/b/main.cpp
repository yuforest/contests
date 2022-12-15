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


// C円ちょうどで作れる整数の範囲
pair<long, long> exact(const long &B, const long &C) {
  const auto n = C / 2;
  // // Cが奇数のとき、−B−n 以上 −B+n 以下の整数がすべて作れる
  if (C % 2) {
    return {-B - n, -B + n};
  } else {
    // 0円の場合
    if (!C)
      return {B, B};
    // Cが偶数のとき、B−n 以上 B+n−1 以下の整数がすべて作れる
    return {B - n, B + n - 1};
  }
}

// 具体的な操作の列を考えて、その中から、 1 を引く操作のうちひとつに注目してみます。
// その操作をしなかった場合と比べて、最終的な整数がどう変化するかを見ると、次のことが分かります。
// その操作後に −1 倍を奇数回行っている場合 、操作によって最終的な数は 1 増える。
// その操作後に −1 倍を偶数回行っている場合 、操作によって最終的な数は 1 減る。
// −1 倍する操作を全くしない場合を除けば、最初に −1 倍の操作をまとめて行ったあと、
// 最後に 1 を足す操作と引く操作をどちらも 2 円でできるとみなすことができる
int main() {
  long B, C;
  cin >> B >> C;
  // C=k の場合に作れる数は、どれも C=k+2 のときに作れることが分かる
  // Cが2余っている場合は-1掛ける操作を2回すれば良いため
  // つまりCが増えることで作れる金額の範囲が増えることはあっても減ることはない
  // よって、C 円ちょうどの場合と、C−1 円ちょうどの場合に作れる数を考えれば十分
  const auto [a, b] = exact(B, C);
  const auto [c, d] = exact(B, C - 1);
  debug(a);
  debug(b);
  debug(c);
  debug(d);
  // C 円ちょうどで作れる数は b−a+1 通りであり、C−1 円ちょうどで作れる数は d−c+1 通り
  // これらの共通部分のサイズは max(0,min(b,d)−max(a,c)+1) で求められる
  // 共通部分は最大値の最小から最小値の最大を引いたもの、開区間なので+1している
  cout << (b - a + 1) + (d - c + 1) - max(0l, min(b, d) - max(a, c) + 1)
       << endl;
  return 0;
}