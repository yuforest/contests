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
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }

void slv(){
  ll l,r;
  cin>>l>>r;
  // 初期のlとrの間隔を表す
  ll w=r-l;
  while(true){
    // lとrの間隔が1になるまでに互いに素な数字が見つかることは保証される
    // ex: 2と3は素、21と22は互いに素
    assert(w>=1);
    // lからr-1までを全探索して、
    // 現在のwでgcdが1になるものがあるかどうかを探索する(答えの差をKとすると概ねK^2)
    // gcdはlogR程度となる
    // 素数の間隔は10^18までで概ね1500程度ごとなので、
    // K^2logN程度で間に合うことになる
    for(ll x = l; x < r-w+1; x++) {
      ll y = x + w;
      if (gcd(x,y)==1) {
        cout << w << endl;
        return;
      }
    }
    w--;
  }
}

int main() {
	slv();
}