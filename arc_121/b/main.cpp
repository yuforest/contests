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
// vector<ll> G[1 << 18];

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

int n;
vector<ll> R, G, B;
ll ans = LLONG_MAX;

int main(){
  // 入力を受け取る
  scanf("%d", &n);
  for(int i=1; i<=n*2; i++){
    ll x; char c;
    scanf("%lld %c", &x, &c);
    if(c=='R') R.push_back(x);
    if(c=='G') G.push_back(x);
    if(c=='B') B.push_back(x);
  }

  // 全てが偶数であれば、不満度を0にできるので早期リターン
  if(R.size() % 2 == 0 && G.size() % 2 == 0 && B.size() % 2 == 0){
    printf("0\n");
    return 0;
  }
  // それ以外の時全て奇数個ということは和が偶数なのであり得ない
  // 3つのうち2つが奇数個ということになる
  // そしてそのうちそれぞれ1つ以外は同色で組み合わせることができるので
  // 色が合わないのはたかだか1つでありそれを求める

  // これは同じコードを書かなくて済むように一般化している
  // Gが偶数個のときRとスワップ
  if(G.size() % 2 == 0) R.swap(G);
  // Bが偶数個のときRとスワップ
  if(B.size() % 2 == 0) R.swap(B);
  // 上記操作により絶対にRが偶数になりB,Gが奇数になる

  // それぞれソート
  sort(R.begin(), R.end());
  sort(G.begin(), G.end());
  sort(B.begin(), B.end());

  // BG 型の組が 1 つあり、他は全て同色の組
  // GR,BR 型の組が 1 つずつあり、他は全て同色の組(1つ偶数を崩してG,Bと組み合わせる)
  // これはBG型の組が1つあるとき
  for(auto x: G){
    auto it = lower_bound(B.begin(), B.end(), x);
    // 探索しているもの以上で近いものとの差
    if(it != B.end()) ans = min(ans, *it - x);
    // 探索しているもの未満で近いものとの差
    if(it != B.begin()) ans = min(ans, x - *prev(it));
  }

  ll gMin = 1e18, bMin = 1e18;
  // 緑と赤を組み合わせて最小値を探していく
  // GR,BR 型の組が 1 つずつあるとき
  for(auto x: G){
    auto it = lower_bound(R.begin(), R.end(), x);
    if(it != R.end()) gMin = min(gMin, *it - x);
    if(it != R.begin()) gMin = min(gMin, x - *prev(it));
  }
  // 青と赤を組み合わせて最小値を探していく
  for(auto x: B){
    auto it = lower_bound(R.begin(), R.end(), x);
    if(it != R.end()) bMin = min(bMin, *it - x);
    if(it != R.begin()) bMin = min(bMin, x - *prev(it));
  }

  ans = min(ans, gMin + bMin);
  cout << ans << endl;
}