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
// aからbまでデクリメントする
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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
// 二項係数ライブラリ
template<typename T, int FAC_MAX> struct Comb {
  vector<T> fac, ifac;
  Comb(){
    fac.resize(FAC_MAX,1);
    ifac.resize(FAC_MAX,1);
    // 階乗の配列を作成
    rep3(i,1,FAC_MAX) fac[i]=fac[i-1]*i;
    // 最後の位置に逆数を入れている
    ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];
    // フェルマーの小定理: ある数xのmodp(pは素数)上での逆数はx'=x^(p-2)で計算できる
    // 最後から2番目の逆数は、最後の逆数に最後の数をかけたもの
    // 前の値を利用して値を求めていく
    rrep(i,FAC_MAX-2,1) ifac[i] = ifac[i+1] * T(i+1);
  }
  T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
  // a!/(a-b)!b!の値、割り算をmod1000000007の逆数をかけることで表している
  T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
  // x1+x2+⋯+xk=nx1+x2+⋯+xk=n(k個に分割したボールの数を合計するとn)
  // xi は 0 以上の整数
  // ここでnがグループ数、kが球の数
  T nHk(int n, int k) {
    if (n == 0 && k == 0) return T(1);
    if (n <= 0 || k < 0) return 0;
    // 一般に a 個の玉と b 個の仕切りを並べる方法の数は
    // a+bCa通り(=a+bCbでもある)であり、k個の玉と、n-1個の仕切りの並びから、
    // 答えは n+k−1Ck通りとなる
    return aCb(n + k - 1, k);
  } // nHk = (n+k-1)Ck : n is separator
  T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
  // combination of paris for n
};

using mint = modint1000000007;
Comb<mint, 200000> com;

// 主客転倒
// 全部のmaxX-minXを考えてみると、maxXの総和-minXの総和が答え
int main() {
  ll N, K;
  cin >> N >> K;
  vl A(N);
  rep(i, N) cin >> A[i];
  mint maxX = 0;
  sort(all(A));
  // A[i]が最大値になる通り数を求めて掛ければ良い
  // i番目以前の数からK-1個を選ぶ通り数はiC(K-1)
  rep3(i, K - 1, N) maxX += mint(A[i]) * com.aCb(i, K - 1);

  mint minX = 0;
  // 大きい順
  sort(all(A), greater<ll>());
  // A[i]が最小値になる通り数を求めて掛ければ良い
  // i番目以前の数からK-1個を選ぶ通り数はiC(K-1)
  rep3(i, K - 1, N) minX += mint(A[i]) * com.aCb(i, K - 1);

  mint ans = maxX - minX;
  cout << ans.val() << endl;

}