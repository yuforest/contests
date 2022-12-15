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
  int N, M;
  cin >> N >> M;
  // {n, d}
  using P = pair<int, int>;
  // dをn個並べて作れる数を表す
  P ANS = {0, 0};

  // 9N個しかないので愚直に並べても間に合う
  for (int d = 1; d <= 9; ++d) {
    ll x = 0;
    for (int n = 1; n <= N; ++n) {
      // x(n−1,d) が x(n,d) の接頭辞であることに注目
      // つまり111は1111の最初に現れる文字列だということ
      // x(n,d)=10x(n−1,d)+dが成り立つ
      // x(n,d)modM がひとつあたり O(1) 時間で計算できる
      // 掛け算や足し算ではmod両辺に適応できるので
      // x(n,d) mod M=(10x(n−1,d)+d) mod Mが成り立つ
      x = (10 * x + d) % M;
      if (x == 0) ANS = max(ANS, P({n, d}));
    }
  }

  auto [n, d] = ANS;
  // nが0ならそのような数は存在しないので−1を出力
  if (n == 0) {
    cout << "-1" << '\n';
  } else {
    // n個のdを並べて出力する
    string s(n, '0' + d);
    cout << s << '\n';
  }
  return 0;
}