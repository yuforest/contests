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
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

// エラトステネスの篩
vector<bool> Eratosthenes(int N) {
  // テーブル
  vector<bool> isprime(N+1, true);

  // 1 は予めふるい落としておく
  isprime[1] = false;

  // ふるい
  for (int p = 2; p <= N; ++p) {
    // すでに合成数であるものはスキップする
    if (!isprime[p]) continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= N; q += p) {
        isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

int main() {
  double x1,y1,r; cin >> x1 >> y1 >> r;
  double x2,y2,x3,y3; cin >> x2 >> y2 >> x3 >> y3;

  // 円の中心から、長方形の角までの長さ
  double d1 = sqrt( (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1) );//右上
  double d2 = sqrt( (x2-x1)*(x2-x1) + (y3-y1)*(y3-y1) );//左上
  double d3 = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );//左下
  double d4 = sqrt( (x3-x1)*(x3-x1) + (y2-y1)*(y2-y1) );//右下

  //長方形が円を塗りつぶすパターン
  // 長方形の中に円が内包されている
  if (x2 <= x1 - r
      && y2 <= y1 - r
      && x3 >= x1 + r
      && y3 >= y1 + r){
        cout << "NO" << endl;
        cout << "YES" << endl;
  //円が長方形を塗りつぶすパターン
  // rが円の中心と長方形の全ての四隅との距離以上である場合
  }else if(r >= d1
      && r >= d2
      && r >= d3
      && r >= d4
      ){
        cout << "YES" << endl;
        cout << "NO" << endl;
  //どちらも塗りつぶしていないパターン
  }else{
    cout << "YES" << endl;
    cout << "YES" << endl;
  }
  return 0;
}