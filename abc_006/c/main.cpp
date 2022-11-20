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

int main() {
  int n,m;
  cin >> n >> m;
  // 大人の数を0からn人まで全探索
  // a+b+c=N...1
  // 2a+3b+4c=M...2
  // の連立方程式を解く
  // 1をcについて解いたものを2に代入してbについて解くと下記の式が得られる
  // また1をbについて解いたものを2に代入してcについて解くと下記の式が得られる
  // つまり2つの式から一つの変数を消せるので、b, cについてそれぞれ消すと
  // aのみを全探索するだけで解が得られる
  for(int a=0;a<=n;a++){
    // 老人の数
    int b = 4*n - m - 2*a;
    // 赤ちゃんの数
    int c = m - 3*n + a;
    debug(a);
    debug(b);
    debug(c);
    if(b>=0&&c>=0){
      cout<<a<<" "<<b<<" "<<c<<endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}