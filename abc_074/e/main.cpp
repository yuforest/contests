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

const int N=2e6+1;
int n,k;
ll a[N];
int main(){
  cin >> n >> k;
  // rにはありうる最大値を入れる
  ll l=1,r;
  for(int i=1; i<=n ;i++){
    cin >> a[i];
    // 最大値更新
    r = max(r,a[i]);
  }

  // 答えがX以下であるか？という問題を考える
  // つまり切った後の丸太の長さの最大値がX以下になるかという問題
  while(l!=r){
    ll mid=(l+r)/2;
    ll s=0;
    // n個の丸太を全てmid以下にするためには
    // (a[i]-1)/mid回の和の回数だけ切る必要がある
    for(int i=1; i<=n ;i++){
      s+=(a[i]-1)/mid;
    }
    // k回まで切って全てmid以下にすることができれば最大値はmid以下になる
    // この場合実現可能
    if(s<=k) r=mid;
    // この場合実現不可能なので最大値はmidより大きな値になる
    else l=mid+1;
  }
  cout <<l << endl;
}