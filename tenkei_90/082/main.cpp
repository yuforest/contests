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

// long long mod = 1000000007;
// プラスのみに絞ることで10^19の範囲まで表すことができる
unsigned long long L, R;
unsigned long long power10[22];

long long modpow(long long a, long long b, long long m) {
  long long p = 1, q = a;
  for (int i = 0; i < 30; i++) {
    if ((b & (1LL << i)) != 0) { p *= q; p %= m; }
    q *= q; q %= m;
  }
  return p;
}

// mod m上でのa/bを掛け算として計算するためのメソッド
long long Div(long long a, long long b, long long m) {
  // Get the value of a/b
  return (a * modpow(b, m - 2, m)) % m;
}

// 10^iを19乗まで計算しておく
void init() {
  // Calculate 10^i
  power10[0] = 1;
  for (int i = 1; i <= 19; i++) power10[i] = (10ULL * power10[i - 1]);
}

// 1からXまでの和をmod 1000000007で計算
// 数列の和の公式
long long f(long long X) {
  // Calculate 1 + 2 + ... + X mod 1000000007
  long long v1 = X % mod;
  long long v2 = (X + 1) % mod;
  long long v = v1 * v2 % mod;
  return Div(v, 2, mod);
}

int main() {
  // Step #1. Initialize / Input
  init();
  cin >> L >> R;

  // Step #2. Brute Force by Digit-Size
  long long Answer = 0;
  // その桁の整数が何回書かれるかを
  // 1桁から19桁まで計算する
  // 桁ごとの部分問題に分割する
  for (int i = 1; i <= 19; i++) {
    // その桁の下限と上限
    // L=98,R=100の例ならi=2の時にvl=98,vr=99となる
    // vl=max(98,10) = 98
    // vr=min(100,99) = 99
    // となるためである
    unsigned long long vl = max(L, power10[i - 1]);
    unsigned long long vr = min(R, power10[i] - 1ULL);
    debug(vl);
    debug(vr);
    // 左側の方が大きければcontinue
    if (vl > vr) continue;
    // 下限から上限までの和を計算する、マイナスにならないようにmodを足す
    long long val = (f(vr) - f(vl - 1) + mod) % mod;
    debug(val);
    // 桁数*(その桁の数字の合計出現回数)
    Answer += 1LL * i * val;
    Answer %= mod;
  }

  // Step #3. Output The Answer
  cout << Answer << endl;
  return 0;
}