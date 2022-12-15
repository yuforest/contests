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

// 50個で十分
int dist[51];
// O(2N)で答えを求めたい
// 任意の1つの頂点から一番離れた頂点をvとするとvから最も離れた点までの距離が直径になる
// 直径の端となる頂点をNで決めることができるので、もう片方もNで求めて2Nに収まる
// double-sweepという方法
// vとvより最も離れた点への距離より長い頂点の組、a,bを置いたとしても
// v--bはa--bよりも短くなることはないので背理法で示せる
// a,bのLCA(最小共通祖先)をLとすると、vはLから最も離れた頂点の一つなので
// v--bはa--bより短くなるということはない
int main(){
  dist[0] = -1e9;
  int N;
  cin >> N;
  // 1から全ての頂点に対して距離を問い合わせる
  for(int i = 1 ; i <= N ; i++){
    cout << "? " << 1 << " " << i << endl;
    // 1からi番目の頂点への答えを保存
    cin >> dist[i];
  }
  // 距離が最大の頂点を取得
  int p = max_element(dist, dist+N+1) - dist;
  int ans = 0;
  // 1からの距離が最大の頂点から再度全ての頂点に対して距離を問い合わせる
  for(int i = 1 ; i <= N ; i++){
    cout << "? " << p << " " << i << endl;
    cin >> dist[i];
    // その距離が最大のものが答えとなる
    ans = max(ans, dist[i]);
  }
  // 答えを出力
  cout << "! " << ans << endl;
}