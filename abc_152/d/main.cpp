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

ll cnt[10][10];
int main(){
  int N;
  cin >> N;

  // 1からNまで探索
  rep3(i, 1, N + 1) {
    // Aの先頭数と末尾数を固定にする
    int btm = i % 10;

    int top = -1;
    int x = i;
    while (0 < x) {
      top = x % 10;
      x /= 10;
    }
    // cnt[top][btm] := 先頭がtopで、末尾がbtmである数の個数
    // iが先頭がtopで最後がbtmな数字であるのでインクリメント
    cnt[top][btm]++;
  }

  ll ans = 0;
  // Aの先頭数をAtop, 末尾数をAbtmとすると、Bは先頭数がAbtm, 末尾数がAtopとなる
  // (A,B)の組み合わせは(先頭がAtop, 末尾がAbtmである数の個数)×(先頭がAbtm, 末尾がAtopである数の個数)
  // AtopもAbtmも0以上9以下の数であるため、このように書ける
  rep3(Atop, 0, 10) rep3(Abtm, 0, 10) ans += cnt[Atop][Abtm] * cnt[Abtm][Atop];
  cout << ans << endl;

  return 0;
}