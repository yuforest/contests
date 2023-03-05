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

// フェニック木は Binary Indexed Tree(BIT)とも呼ばれる
// 累積和におけるaddとsumをO(logN)で実装できるデータ構造
int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(ll& a : A) cin >> a;
  ll ans = 0;
  fenwick_tree<ll> bit(N);
  // まずはAの転倒数を求める
  for(ll a : A){
    // aの位置より右にある要素の個数を求める
    ans += bit.sum(a, N);
    // aの位置に1を加える
    bit.add(a, 1);
  }
  // 前の転倒数との差分をとる
  // bi=a[i+k mod N]なので
  // kが1増えるということは、先頭を削除して、末尾に追加することに等しい
  for(ll a : A){
    cout << ans << '\n';
    // Bの先頭のaiを削除すると転倒数はai減り、
    // Bの末尾にaiを追加すると転倒数はN-1-ai増える
    // ので、転倒数はN-1-a*2増えることになる
    // 例えば先頭から削除するときai=0なら減る転倒数は0
    // ai=1なら減る転倒数は、この先に0があるので1個となる
    // 逆に末尾に追加する時ai=0なら増える転倒数は、この前に0以外のN-1個の要素があるのでN-1個となる
    // ai=1なら増える転倒数は、この前に0以外のN-2個の要素があるのでN-2個となる
    ans += N - 1 - a * 2;
  }
}